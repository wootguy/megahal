#include "megahal.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{    
    srand(time(NULL));

    //megahal_setnoprompt();
    //megahal_setnowrap();
    //megahal_setdirectory(optarg);
    //megahal_setnobanner();
	
    /*
     *		Do some initialisation 
     */
    megahal_initialize();
   
	
    /*
     *		Create a dictionary which will be used to hold the segmented
     *		version of the user's input.
     */

    /*
     *		Load the default MegaHAL personality.
     */
    char* output = megahal_initial_greeting();
    megahal_output(output);
    /*
     *		Read input, formulate a reply and display it as output
     */
    while(1) {
        
	   // input = megahal_input("> ");
	
        printf("> ");
        string command;
        std::getline(std::cin, command);

	    
	    if (megahal_command((char*)command.c_str()) != 0)
	        continue;

	    output = megahal_do_reply((char*)command.c_str(), 1);

	    megahal_output(output);
    }

    megahal_cleanup();
    exit(0);
}
