#include "megahal.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{    
    srand(time(NULL));

    megahal_initialize(".");

    char* output = megahal_initial_greeting();
    printf(output);
    printf("\n");

    while(1) {	
        printf("> ");
        string command;
        std::getline(std::cin, command);
	    
	    if (command == "#quit")
	        break;

	    output = megahal_do_reply((char*)command.c_str());

	    printf(output);
	    printf("\n");
    }

    megahal_save_model("megahal.brn");

    return 0;
}
