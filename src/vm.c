/*
##################################
# The Cup Virtual Machine Alpha  #
##################################
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
/* Define Opcodes*/
#define MOVE 1
#define ADD 2
#define CONDITIONAL 3
int registers[32000];
int program_arr[32000];
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
        printf("\nprog:%s\n", program);
        byte = NEXT_BYTE(program);
        program_arr[BYTE_ADDR] = byte;
        char BYTE_STR[5000];
        switch (byte) {
            case MOVE:
                printf("\nprog:%s\n", program);
                 /* MOVE Instruction */
                chopN(program, 2);
                printf("\nprog:%s\n", program);
                byte = 0;
                

                

                /* Get Byte to move to the address */
                byte = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", byte);
                
                chopN(program, strlen(BYTE_STR)+1);
                /* Get Adress of register to move to */
                int ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", ADDR);
                chopN(program, strlen(BYTE_STR)+1);
            
                printf("\nADDR:%d VAL:%d prog:%s\n", ADDR, registers[ADDR], program);
                /* Move byte to Register*/
                registers[ADDR] = byte; 
                printf("\nADDR:%d VAL:%d prog:%s\n", ADDR, registers[ADDR], program);
                amount_registers++;
                

                break;
            case ADD:
                /* ADD instruction */
                chopN(program, 2);
                byte = 0;

             
              
                int REG_1_ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", REG_1_ADDR);
                chopN(program, strlen(BYTE_STR)+1);      
      
                int REG_2_ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", REG_2_ADDR);
                chopN(program, strlen(BYTE_STR)+1);
        
                int RESULT_ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", RESULT_ADDR);
                chopN(program, strlen(BYTE_STR)+1);
                registers[RESULT_ADDR] = registers[REG_1_ADDR] + registers[REG_2_ADDR]; 
            case CONDITIONAL:
                /* CONDITIONAL instruction */
                chopN(program, 2);
                byte = 0;

                int CONDITIONAL_TYPE = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", CONDITIONAL_TYPE);
                chopN(program, strlen(BYTE_STR));

                /* Get adress of registers to compare */
                int REG_1_ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", REG_1_ADDR);
                chopN(program, strlen(BYTE_STR));

                int REG_2_ADDR = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", REG_2_ADDR);
                chopN(program, strlen(BYTE_STR));

                /* Get instruction index to jump to if conditional is true*/
                int JUMP = NEXT_BYTE(program);
                sprintf(BYTE_STR, "%d", JUMP);
                chopN(program, strlen(BYTE_STR));

                /* Get Value of registers to compare */
                int REG_1_VALUE = registers[REG_1_ADDR];
                int REG_2_VALUE = registers[REG_2_ADDR];
                switch (CONDITIONAL) {
                    case 1:
                        /* == */ 
                        if (REG_1_VALUE == REG_2_VALUE) {
                            
                        }

                }

        }
        printf("\nprog:%s\n", program);
        BYTE_ADDR++;
    }
    return 0;
}
