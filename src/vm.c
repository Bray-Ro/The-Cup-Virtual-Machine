/*
#############################
The Cup Virtual Machine Alpha
##################################
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
char* read_file(char fname[5000]) {
        /* declare a file pointer */
    FILE    *fptr;
    char    *buffer;
    long    numbytes;
    char str1;
    char file[5000];
    /* open an existing file for reading */
	fptr = fopen (fname, "r");  
	
	str1 = fgetc(fptr);
	while (str1 != EOF)
	{
            if (str1 != '\n') {
                sprintf(file, "%s%c", file, str1);   
            }
			
            
			str1 = fgetc(fptr);
	}
    
    fclose (fptr);
    return file;
}
int byte;

int main(int argc, char *argv[]) {
    char *buffer = read_file(argv[1]);
    char program[5000];
    strcpy(program, buffer);
    char prog_backup[5000];
    int cpyi;
    for(cpyi=0; program[cpyi]!='\0'; cpyi++) {
        prog_backup[cpyi] = program[cpyi];
    }

    char strbyte[5000];
    strcpy(strbyte, strtok(prog_backup, " "));
    int i;
    int byte_len = strlen(strbyte);
    for(i=0; i<byte_len; i++){

        byte = byte * 10 + ( strbyte[i] - '0' );

    }
    return 0;
}
