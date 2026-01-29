#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "fancy-hello-world.h"

int main(void) {
    char name[60];
    char output[60];
    fgets(name, 51, stdin);
    hello_string(name, output);     
    printf("Hello World, hello ");
    printf("%s", output);
    return 0;
}

void hello_string(char* name, char* output){
    strcpy(output, name);
}