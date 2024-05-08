#include <filesystem>
#include <chrono>
#include <ctime>
#include <regex>
#include "log.h"

void log::log(std::string Logfile_path,int time_switch){
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
 
