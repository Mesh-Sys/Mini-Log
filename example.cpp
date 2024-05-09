#include <iostream>
#include "log.h"

//intialise logger by creating an object
Log log(DEFAULT,DEFAULT); //if logfile path is DEFAULT it would the directory the program executed from
					// if the logfile name is DEFAULT it would use the default logfile name "Log.txt"

int main(){
	//using individual method
	log.info("Started Method main");	//using info method

	log.warning("Started Method main");	//using warning method

	log.debug("Started Method main");	//using debug method

	log.verbose("Started Method main");	//using verbose method

	log.error("Started Method main");	//using error method

	//using the message method and specifying the logging level manually
	log.message(INFO,"Started Method main Specified Logging Level");

	log.message(WARNING,"Started Method main Specified Logging Level");

	log.message(DEBUG,"Started Method main Specified Logging Level");

	log.message(VERBOSE,"Started Method main Specified Logging Level");

	log.message(ERROR,"Started Method main Specified Logging Level");

	log.close();	//close logging file
}