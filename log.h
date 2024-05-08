 #pragma once

#include <string>
#include <fstream>

//using a class so that multiple Logfiles can be placed at diffrent directory
enum tenum{WITH_TIME,		//enum to act as the time switch for the Logfile
			WITHOUT_TIME};
class log{
private:
	std::string log_file_path;
	const std::string lfname = "log.txt";	//set Logfile name
	int time_switch = tenum::WITH_TIME;		//specifies if time and date should be enabled in the log file
	void create_logfile();
	std::ofstream olfstream;		//Logfile's output file stream
	std::string lfdir;	//directory + filename
	

public:	
	log(std::string Logfile_path,int time_switch);
	log();
	~log();
    
    //initialize the logfile by creating a file
	void create_file(std::string Logfile_path,int time_switch){
		this->log_file_path = Logfile_path;
		this->time_switch = time_switch;
		this->lfdir = Logfile_path + this->lfname;
		create_logfile();
	}
	
	void create_file(std::string Logfile_path){
		this->log_file_path = Logfile_path;
		this->lfdir = Logfile_path + this->lfname;
		create_logfile();
	}
	
	void message(std::string function_name,std::string message);
	
	
	void close();
}; 
