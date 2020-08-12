# The-Cup-Virtual-Machine
The official Bytecode interpreter for the cup programming language
# documentation for the Cup Virtual Machine
Note That these docs will update along with the VM and the VM will get more opcodes
The Cup Virtual Machine is an application wich executes the compiled bytecode that the Cup Compiler generates. The following text will document the architecture of the Cup Virtual machine aswell as all of the Opcodes for the VM. This will help people create new implementations of the cup VM aswell as create new Cup compilers.

# The architecture of the cup Virtual Machine
The Cup virtual machine, Unlike The Java and Python Virtual machine is register based wich means that The cup VM has registers instead of only a stack. The CVM has 3200 of these registers in the standard implementation, These registers may all hold a hexadecimal integer value ( Chars may be implemented by storing the corrosponding Hexadecimal ASCII code in a register and then printing those registers).

# Cup VM opcodes

## 1 (MOVE)
Example:
```
1 1 3;
```
The 1 Opcode Moves a Hexadecimal integer into a register, The example above Moves The value 1 into register 3. The first operand is the value you wish to move to a register and the second operand is the register you want to move to, this can be used for many things and is perhaps the most important opcode for the CVM.
## 2 (ADD)
Example:
```
2 1 2 3
```
The 2 Opcode Adds the value of 2 registers together and stores the result in another, The example above adds the value of register 1 and 2 and stores it in register 3. The first 2 operands are the addresses of the 2 registers you want to add together and the 3rd operand is the address you want to store the result in. This is another very important Opcode for the Cup VM as it is what will handle all mathematical operations that you need to do with the cup VM.

# Tips for writing Cup Bytecode
Though it is not recommended to directly write bytecode for the Cup VM and instead to use the Cup language itself, If you would like to write a program in Cup bytecode then here are some syntax tips and other tips to keep your code readable.

1. In Cup Bytecode do not use newlines, this creates errors for the VM and breaks your program.
2. To Make your code look cleaner and more readable, we advise that you put a special charecter such as a semi-colon to seperate Opcodes, It doesent really matter what you use though because it will just be ignored by the VM.
