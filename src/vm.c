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

int registers[32000];

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
        
   
        byte = atoi(strbyte);
     
        return byte;
}
int main(int argc, char *argv[]) {
    int i = 0;
    /* Create Registers */
    while (i != 32000) {
        registers[i] = 0;
        
        i++;
    }
 
    int amount_registers = 0;
      
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
                 /* MOVE Instruction */
                chopN(program, 2);
                byte = 0;

                char BYTE_STR[5000];
                int ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", ADDR);
                chopN(program, strlen(BYTE_STR));

                byte = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", byte);
                chopN(program, strlen(BYTE_STR));
                printf("\nREGISTER:%d\n", registers[ADDR]);
                registers[ADDR] = byte; 
                printf("\nREGISTER:%d\n", registers[ADDR]);
                amount_registers++;
                

                break;
                 
        }
     
        BYTE_ADDR++;
    }
    return 0;
}
