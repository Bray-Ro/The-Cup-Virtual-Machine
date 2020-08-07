/*
#############################
The Cup Virtual Machine Alpha
##################################
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct STACK_STRUCT {

    int STACK[5000];
};

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
void chopN(char *str, size_t n)
{
    assert(n != 0 && str != 0);
    size_t len = strlen(str);
    if (n > len)
        return;  // Or: n = len;
    memmove(str, str+n, len - n + 1);
}
int NEXT_BYTE(char program[5000]) {
        unsigned int byte;
        char prog_backup[5000];
        int cpyi;
        for(cpyi=0; program[cpyi]!='\0'; cpyi++) {
            prog_backup[cpyi] = program[cpyi];
        }

        char strbyte[5000];
        strcpy(strbyte, strtok(prog_backup, " "));
        
        int i;
        int byte_len = strlen(strbyte);
        
        // for(i=0; i<byte_len; i++){

        //     byte = byte * 10 + ( strbyte[i] - '0' );

        // }
        byte = atoi(strbyte);
        printf("\nBYTETIME:%d\n", byte);
        return byte;
}
int main(int argc, char *argv[]) {
    /* Create data stack*/
    struct STACK_STRUCT DATA_STACK;
 
    int DATA_STACK_SIZE = 0;
      
    /* byte stores current opcode */
    unsigned int byte;
    /* get contents of a cup bytecode file */
    char *buffer = read_file(argv[1]);
    char program[5000];
    strcpy(program, buffer);
    sprintf(program, "%s ", program);
    /* Execute program*/
    int BYTE_ADDR = 0;
    while (BYTE_ADDR < strlen(program)) {
        
        byte = NEXT_BYTE(program);
        
        switch (byte) {
            case 1:
                 /* PUSH Instruction */
                chopN(program, 2);
                byte = 0;
           
                byte = NEXT_BYTE(program);
                
                
                char BYTE_STR[5000];
                sprintf(BYTE_STR, "%d", byte);
                chopN(program, strlen(BYTE_STR));
                DATA_STACK.STACK[DATA_STACK_SIZE] = byte; 
             
                DATA_STACK_SIZE++;
                

                break;
        }
    
        BYTE_ADDR++;
    }
    return 0;
}
