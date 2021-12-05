#pragma once

#include <termios.h>

namespace helper{	
	struct termios term;
	
	void disable_echo(){
		tcgetattr(fileno(stdin), &term);
	
		term.c_lflag &= ~ECHO;
		tcsetattr(fileno(stdin), 0, &term);
	}
	
	void enable_echo(){
		term.c_lflag |= ECHO;
	
		tcsetattr(fileno(stdin), 0, &term);
	}	

	const char *keycodes[] = {
	    "RESERVED",
	    "ESC",
	    "1",
	    "2",
	    "3",
	    "4",
	    "5",
	    "6",
	    "7",
	    "8",
	    "9",
	    "0",
	    "MINUS",
	    "EQUAL",
	    "BACKSPACE",
	    "TAB",
	    "Q",
	    "W",
	    "E",
	    "R",
	    "T",
	    "Y",
	    "U",
	    "I",
	    "O",
	    "P",
	    "LEFTBRACE",
	    "RIGHTBRACE",
	    "ENTER",
	    "LEFTCTRL",
	    "A",
	    "S",
	    "D",
	    "F",
	    "G",
	    "H",
	    "J",
	    "K",
	    "L",
	    "SEMICOLON",
	    "APOSTROPHE",
	    "GRAVE",
	    "LEFTSHIFT",
	    "BACKSLASH",
	    "Z",
	    "X",
	    "C",
	    "V",
	    "B",
	    "N",
	    "M",
	    "COMMA",
	    "DOT",
	    "SLASH",
	    "RIGHTSHIFT",
	    "KPASTERISK",
	    "LEFTALT",
	    "SPACE",
	    "CAPSLOCK",
	    "F1",
	    "F2",
	    "F3",
	    "F4",
	    "F5",
	    "F6",
	    "F7",
	    "F8",
	    "F9",
	    "F10",
	    "NUMLOCK",
	    "SCROLLLOCK"
	};
}
