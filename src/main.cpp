#include "megahal.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{    
    srand(time(NULL));

    MegaHal hal = MegaHal();

    hal.load_personality("megahal");
    hal.write_dictionary();

    // initial greeting
    char* output = hal.do_reply("hi", false);
    printf(output);
    printf("\n");

    while(1) {	
        printf("> ");
        string command;
        std::getline(std::cin, command);
	    
	    if (command == "#quit")
	        break;

	    output = hal.do_reply((char*)command.c_str(), true);

	    printf(output);
	    printf("\n");
    }

    hal.save_model();

    return 0;
}
