#include <stdio.h>
#include<stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]){
//check if the number of arguments is 2
   if (argc !=3)   {
   // Log an error message to syslog and exit
        openlog(argv[0], LOG_PID | LOG_USER, LOG_USER);
        syslog(LOG_ERR, "Error: Two arguments are required.");
        closelog();
   exit(EXIT_FAILURE);
   }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    FILE *file = fopen(writefile, "w");
    
    if (file==NULL){
        openlog(argv[0], LOG_PID | LOG_USER, LOG_USER);
        syslog(LOG_ERR, "Error: Could not open file: %s.", writefile);
       closelog();
       exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%s", writestr);
    

    
    
    if (fclose(file)!=0){
         openlog(argv[0], LOG_PID | LOG_USER, LOG_USER);
        syslog(LOG_ERR, "Error: File couldnot be closed.");
        closelog();
        exit(EXIT_FAILURE);
    }
    
    openlog(argv[0], LOG_PID | LOG_USER, LOG_USER);
    // Log a message with LOG_DEBUG level
    syslog(LOG_DEBUG, "Debugging Message: Writing to %s", writefile);
    // Close syslog
    closelog();
  
return 0;
}
