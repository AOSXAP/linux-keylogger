# linux-keylogger

A simple C++ keylogger prototype, which is meant to showcase the basics of Linux keylogging.

Replace "/dev/input/event4" (main.cpp) with your keyboard event, "$cat /proc/bus/input/devices" should give you an idea about it

The keylogger needs root privileges to be run. You can use the "build.sh" script to try it out, or compile it with the command "g++ main.cpp -o main && sudo ./main"
