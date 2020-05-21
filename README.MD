to do :

read file.s
check file
2 first line
name comment (and sizes)

line by line
instruction param1, param2... (REG, ...)

and transform instruction in bytecode
OP_CODE OCP(optional) CODED_PARAMS

Exec:
NAME
COMMENT

Bytcode

an executable files has a header wich is PROG_NAME_LENGTH (128) and COMMENT_LENGHT (2048)

VM : ne prend que le instructions possibles