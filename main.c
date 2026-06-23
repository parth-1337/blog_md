#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmark-gfm.h>
#include <cmark-gfm-core-extensions.h>


int main(int argc , char *argv[]) {

    (void)argc;

    if (argv[2] != NULL && strcmp(argv[2], "--dark") == 0) {
        gen_file(1 , argv[1]);
    } 
    // defualt is light
    else {

        if (argv[2] != NULL && strcmp(argv[2], "--light") != 0) {
            printf("Unknown flag '%s'. Defaulting to light theme.\n", argv[1]);
        }
        
        gen_file(0 , argv[1]); 
    }

    return 0;
}


