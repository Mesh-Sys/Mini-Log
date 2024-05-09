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
	SOFTWARE.
**/
#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <regex>

//define logging level
#define INFO 1
#define WARNING 2
#define DEBUG 3
#define VERBOSE 4
#define ERROR 5

//using a class so that we can have logging level has method 
class Log{
private:
	const std::string default_filename = "Log.txt";
	ofstream olfstream;
	bool intialised = false;
	std::string file_dir;
	void openlogfile();

public:
	Log(std::string logfile_path,std::string logfile_name);
	~Log();
	void init(std::string logfile_path,std::string logfile_name);

	void info(std::string msg){
		message(INFO,msg);
	}

	void warning(std::string msg){
		message(WARNING,msg);
	}

	void debug(std::string msg){
		message(DEBUG,msg);
	}

	void verbose(std::string msg){
		message(VERBOSE,msg);
	}

	void error(std::string msg){
		message(ERROR,msg);
	}

	void message(int level,std::string msg);
	void close();
};

Log::Log(std::string logfile_path,std::string logfile_name){
	Log::init(logfile_path,logfile_name);
}

void Log::init(std::string logfile_path,std::string logfile_name){
	if(!Log::intialised){
		if(logfile_name == NULL){
			logfile_name = Log::default_filename;
		}
		if(logfile_path == NULL){
			logfile_path = "";
			Log::file_dir = logfile_name;
		}else{
			if(std::filesystem::exists(logfile_path.c_str())){	//check if logfile directory(if defined) exists
				Log::file_dir = logfile_path +  "/" + logfile_name;
			}
		}
		try{
			Log::olfstream.open(Log::file_dir.c_str(),std::ios::out|std::ios::app);
		}catch(const exception &e){
			std::cerr << "Error occured while opening logfile in : " << __func__ << ":Exception - " << e.what();  
		}
		Log::intialised = true;
	}	
}

void Log::openlogfile(){	//open logfile if it is closed
	if(!LOG::olfstream.is_open()){
		try{
			Log::olfstream.open(Log::file_dir.c_str(),std::ios::out|std::ios::app);
		}catch(const exception &e){
			std::cerr << "Error occured while opening logfile in : " << __func__ << ":Exception - " << e.what();  
		}
	}
}

void Log::message(int level,std::string msg){	//write message to LOG
	if(Log::intialised){
		std::time_t curr_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::string current_time = std::ctime(&curr_time);
		std::string outputlog;
		
		if(std::regex_search(current_time,std::regex("\n"))){
			current_time = std::regex_replace(current_time,std::regex("\n")," ] ");
		}
		
		switch(level){
			case INFO:
				outputlog = "[" + current_time + "] INFO: " + msg;
			break;
			case WARNING:
				outputlog = "[" + current_time + "] WARNING: " + msg;
			break;
			case DEBUG:
				outputlog = "[" + current_time + "] DEBUG: " + msg;
			break;
			case VERBOSE:
				outputlog = "[" + current_time + "] VERBOSE: " + msg;
			break;
			case ERROR:
				outputlog = "[" + current_time + "] ERROR: " + msg;
			break;
			default:
				outputlog = "[" + current_time + "] UNKNOWN: " + msg;
			break;
		}
	
		checkLogFileAvailability:
		if(Log::olfstream.is_open()){
			Log::olfstream << outputlog << std::endl;
		}else{
			Log::openlogfile();
			goto checkLogFileAvailability;
		}
	}	
}

void Log::close(){
	if(Log::olfstream.is_open()){
		Log::olfstream.close();
	}
}

Log::~Log(){
}