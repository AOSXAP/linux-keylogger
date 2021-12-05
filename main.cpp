#include <linux/input.h> 
#include <fcntl.h> 		 //define O_RDONLY
#include <unistd.h> 	 //define read
#include <stdlib.h> 
#include <iostream>
#include <cstring>

#include "helper.h"

#define RD O_RDONLY
#define INF 1


int main(){
	const char* dev = "/dev/input/event4";
	int fd = open(dev, O_RDONLY);

	struct input_event ev; 

	helper::disable_echo();
	
	while(INF){
		read(fd, &ev, sizeof(ev));

		if((ev.type == EV_KEY) && (ev.value == 0)) 
			std::cout<<helper::keycodes[ev.code]<<"\n";

		if(strcmp(helper::keycodes[ev.code], "ESC") == 0) break;
		
	}

	helper::enable_echo();
	//system("cancel && clear");
	close(fd);
}
