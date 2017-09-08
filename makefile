all: program1 program4 program5 program6 program7 program8

program1: program3_1.c
	gcc -o program1 program3_1.c

program4: program3_1_4.c
	gcc -o program4 program3_1_4.c

program5: program3_1_5.c
	gcc -o program5 program3_1_5.c

program6: program3_1_6.c
	gcc -o program6 program3_1_6.c

program7: program3_1_7.c
	gcc -o program7 program3_1_7.c

program8: program3_1_8.c
	gcc -o program8 program3_1_8.c
