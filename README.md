# Mini-Log
A Mini Logging Library Written In C++

Just include the log.h header file in your project

example.cpp shows a good example

# step 1:
  intialize the logger
  
    Log log(Null,Null);  //if logfile path is NULL it would the directory the program executed from
			// if the logfile name is NULL it would use the default logfile name "Log.txt"
		   
    Log log("log/","log1.txt");  //seperate log directory, custom logfile name
    
# step 2:
   write your logs
   
      -using logging level methods
      
      -using message method and specifying logging level

   //using logging level methods
   
   	log.info("message");	//using info method
   
   	log.warning("message");	//using warning method
   
   	log.debug("message");	//using debug method
   
   	log.verbose("message");	//using verbose method
   
   	log.error("message");	//using error method

   //using message method and specifying logging level
   
   	log.message(INFO,"message");
   
   	log.message(WARNING,"message");
   
   	log.message(DEBUG,"message");
   
   	log.message(VERBOSE,"message");
   
   	log.message(ERROR,"message");
   
#step 3:
  close Log file(deinitialize the logger)
  
  	log.close();
