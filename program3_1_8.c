/*
 * Program 3.1 - Number 8 
 * Author: Taylor Freiner
 * Date: 9-7-17
 * Log: Building string from characters entered into stdin
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, n;
	if (argc != 2){   /* check for valid number of command-line arguments */
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for (i = 1; i < n; i++){
		if (childpid = fork())
			break;
	}
	
	int c;
	char buff[1000];

	c = fgetc(stdin);
	while(!feof(stdin)){
		ungetc(c, stdin);
		fgets(buff, 1000, stdin);
		c = fgetc(stdin);
	}

	return 0;
}
