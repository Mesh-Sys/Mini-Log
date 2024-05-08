/**	MIT License

	Copyright (c) 2024 Mesh Anthony 
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.**/
#include <filesystem>
#include <chrono>
#include <ctime>
#include <regex>
#include "log.h"

log::log(std::string Logfile_path,int time_switch){
		this->log_file_path = Logfile_path;
		this->time_switch = time_switch;
		this->lfdir = Logfile_path + this->lfname;
		create_logfile();
	}
void log::message(std::string function_name,std::string message){	//write message to log
	std::time_t curr_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string current_time = std::ctime(&curr_time);
	std::string outputlog;
	
	if(std::regex_search(current_time,std::regex("\n"))){
		current_time = std::regex_replace(current_time,std::regex("\n")," ] ");
	}
	
	if(log::time_switch == tenum::WITH_TIME){
		outputlog = "[" + current_time + " [" + function_name + "] " + message;
	}else if(log::time_switch == tenum::WITHOUT_TIME){
		outputlog = message;
	}

	checklog:
	if(log::olfstream.is_open()){
		log::olfstream << outputlog << std::endl;
	}else{
		log::olfstream.open(log::lfdir.c_str(),std::ios::out|std::ios::app);
		goto checklog;
	}
}

void log::create_log(){
	if(!log::olfstream.is_open()){
		log::olfstream.open(log::lfdir.c_str(),std::ios::out|std::ios::app);
	}
}

void log::close(){
	if(log::olfstream.is_open()){
		log::olfstream.close();
	}
}
log::~log()
{
}
 
