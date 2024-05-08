/**	MIT License

	Copyright (c) 2024 Mesh Anthony 
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above c
}
opyright notice and this permission notice shall be included in all
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

namespace LOG{
//using a class so that multiple LOGfiles can be placed at diffrent directory
enum CONFIG{WITH_TIME,		//enum to act as the time switch for the LOGfile
			WITHOUT_TIME,
            DEFAULT};
class LOG{
private:
	std::string log_file_path;
	const std::string lfname = "LOG.txt";	//set LOGfile name
	int time_switch = CONFIG::WITH_TIME;		//specifies if time and date should be enabled in the LOG file
	void create_LOGfile();
	std::ofstream olfstream;		//LOGfile's output file stream
	std::string lfdir;	//directory + filename
	

public:	
	LOG(std::string logfile_path,int time_switch);
    
	LOG();
	~LOG();
    
    //initialize the LOGfile by creating a file
	void create_file(std::string logfile_path,int time_switch){
		this->log_file_path = logfile_path;
		this->time_switch = time_switch;
		this->lfdir = logfile_path + this->lfname;
		create_LOGfile();
	}
	
	void create_file(std::string logfile_path){
		this->LOG_file_path = logfile_path;
		this->lfdir = logfile_path + this->lfname;
		create_LOGfile();
	}
	
	void message(std::string function_name,std::string message);
	
	
	void close();
}; 

}
