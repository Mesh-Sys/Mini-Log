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
