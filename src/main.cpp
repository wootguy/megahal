#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#if !defined(AMIGA) && !defined(__mac_os)
#include <malloc.h>
#endif
#include <string.h>
#include <signal.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#if defined(__mac_os)
#include <types.h>
#include <Speech.h>
#else
#include <sys/types.h>
#endif
#include "megahal.h"
#if defined(DEBUG)
#include "debug.h"
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string>
#include <iostream>

using namespace std;


/* extern errorfp;
extern statusfp;
  */
/* extern noprompt;
extern nowrap;
extern nobanner;
extern typing_delay;
extern speech;
extern quiet;
  */
struct option {
    char* asdf;
    int qwerty;
    char* few;
    char fewfe;
};

static struct option long_options[] = {
    {"no-prompt", 0, NULL, 'p'},
    {"no-wrap", 0, NULL, 'w'},
    {"no-banner", 0, NULL, 'b'},
    {"help", 0, NULL, 'h'},
    {"directory", 1, NULL, 'd'},
    {0, 0, 0, 0}
};

void usage()
{
    puts("usage: megahal [-[pqrgwbh]]\n" \
	 "\t-h : show usage\n" \
	 "\t-p : inhibit prompts\n" \
	 "\t-q : quiet mode (no replies) enabled at start\n" \
	 "\t-r : inhibit progress display\n" \
	 "\t-g : inhibit initial greeting\n" \
	 "\t-b : inhibit banner display at startup\n" \
         "\t-d : sets the directory where your megahal files are\n");
}

/*===========================================================================*/

/*
 *		Function:	Main
 *
 *		Purpose:		Initialise everything, and then do an infinite loop.  In
 *						the loop, we read the user's input and reply to it, and
 *						do some housekeeping task such as responding to special
 *						commands.
 */
int main(int argc, char **argv)
{
    char *input=NULL;
    char *output=NULL;
    char *my_directory = NULL;
    int directory_set;
    int c, option_index = 0;
    
    directory_set = 0;
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
    output = megahal_initial_greeting();
    megahal_output(output);
    /*
     *		Read input, formulate a reply and display it as output
     */
    while(1) {
        
	   // input = megahal_input("> ");
	
        printf("> ");
        string command;
        std::getline(std::cin, command);

	    /*
	     *		If the input was a command, then execute it
	     */

	    if (megahal_command((char*)command.c_str()) != 0)
	        continue;

	    output = megahal_do_reply((char*)command.c_str(), 1);

	    megahal_output(output);
    }

    megahal_cleanup();
    exit(0);
}
