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

LOG::LOG::LOG(std::string logfile_path,int time_switch){
		this->LOG_file_path = logfile_path;
		this->time_switch = time_switch;
		this->lfdir = logfile_path + this->lfname;
		create_LOGfile();
	}
void LOG::LOG::message(std::string function_name,std::string message){	//write message to LOG
	std::time_t curr_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string current_time = std::ctime(&curr_time);
	std::string outputlog;
	
	if(std::regex_search(current_time,std::regex("\n"))){
		current_time = std::regex_replace(current_time,std::regex("\n")," ] ");
	}
	
	if(LOG::time_switch == CONFIG::WITH_TIME){
		outputlog = "[" + current_time + " [" + function_name + "] " + message;
	}else if(LOG::time_switch == CONFIG::WITHOUT_TIME){
		outputlog = message;
	}

	checkLOG:
	if(LOG::olfstream.is_open()){
		LOG::olfstream << outputlog << std::endl;
	}else{
		LOG::olfstream.open(LOG::lfdir.c_str(),std::ios::out|std::ios::app);
		goto checkLOG;
	}
}

void LOG::LOG::create_LOGfile(){
	if(!LOG::olfstream.is_open()){
		LOG::olfstream.open(LOG::lfdir.c_str(),std::ios::out|std::ios::app);
	}
}

void LOG::LOG::close(){
	if(LOG::olfstream.is_open()){
		LOG::olfstream.close();
	}
}
LOG::LOG::~LOG()
{
}
 
