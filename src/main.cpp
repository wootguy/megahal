#include "megahal.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{    
    srand(time(NULL));

    MegaHal hal = MegaHal();

    hal.load_personality("megahal");

    // initial greeting
    char* output = hal.do_reply("hi");
    printf(output);
    printf("\n");

    while(1) {	
        printf("> ");
        string command;
        std::getline(std::cin, command);
	    
	    if (command == "#quit")
	        break;

	    output = hal.do_reply((char*)command.c_str());

	    printf(output);
	    printf("\n");
    }

    hal.save_model();

    return 0;
}
