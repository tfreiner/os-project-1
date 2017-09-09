/*
 * Program 3.1 - Number 8 
 * Author: Taylor Freiner
 * Date: 9-9-17
 * Log: Reworking loop logic and passing nchars variable at command line 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, j, n, nchars;
	char x;
	if (argc != 3){   /* check for valid number of command-line arguments */
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	nchars = atoi(argv[2]);
	char mybuf[nchars+1];

	for (i = 1; i < n; i++) {
		if (childpid = fork())
			break;
	}

	//TODO figure out why this is not waiting for nchars characters after the first process	
	for (j = 0; j < nchars; j++) {
		mybuf[j] = getc(stdin);
	}
	mybuf[nchars] = '\0';

	fprintf(stderr, "i:%d  process ID:%ld  mybuf:%s\n",
                        i, (long)getpid(), mybuf);
        return 0;
}
