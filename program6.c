/*
 * Program 3.1 - Number 8 
 * Author: Taylor Freiner
 * Date: 9-11-17
 * Log: Adding getopt functionality 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, j, n, nchars, opt;
	char x;
	char* mybuf;
	static struct option nchars_option[] = {
		{"nchars", required_argument, NULL, 'c'}
	};
	if (argc != 2 && argc != 5){
		fprintf(stderr, "Usage: %s <-n x> <--nchars y>\n", argv[0]);
		return 1;
	}
	while ((opt = getopt_long(argc, argv, "hn:c:", nchars_option, 0)) != -1){
		switch(opt){
			case 'h':
				printf("Usage: %s <-n x> <--nchars y>\n", argv[0]);
				printf("\t-n x: number of processes to create\n");
				printf("\t--nchars y: length of string\n");	
				printf("\t-h help\n");
				return 0;
				break;
			case 'n':
				n = atoi(optarg);
				break;
			case 'c':
				nchars = atoi(optarg);
				break;
		}
	}

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
