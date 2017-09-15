/*
 * Program 3.1 - Number 8 
 * Author: Taylor Freiner
 * Date: 9-14-17
 * Log: Adding perror
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, j, n, nchars, opt;
	char argval;
	static struct option nchars_option[] = {
		{"nchars", required_argument, NULL, 'c'}
	};
	if (argc != 2 && argc != 5){
		fprintf(stderr, "%s Error: Incorrect number of arguments\n", argv[0]);
		return 1;
	}
	while ((opt = getopt_long(argc, argv, "hn:c:", nchars_option, NULL)) != -1){
		switch(opt){
			case 'h':
				printf("usage: %s <-n positive_integer> <--nchars positive_integer>\n", argv[0]);
				printf("\t-n: number of processes to create\n");
				printf("\t--nchars: length of string\n");	
				printf("\t-h: help\n");
				return 0;
				break;
			case 'n':
				argval = *optarg;
				if(isdigit(argval) && (atoi(optarg) > 0)){
					n = atoi(optarg);
				}
				else{
					fprintf(stderr, "%s Error: Argument must be a positive integer\n", argv[0]);
					return 1;
				}
				break;
			case 'c':
				argval = *optarg;
				if(isdigit(argval) && (atoi(optarg) > 0)){
					nchars = 0;
					nchars = atoi(optarg);
				}
				else{
					fprintf(stderr, "%s Error: Argument must be a positive integer\n", argv[0]);
					return 1;
				}
				break;
			case '?':
				fprintf(stderr, "%s Error: usage: %s <-n positive_integer>\n", argv[0], argv[0]);
				return 1;
				break;
		}
	}

	for (i = 1; i < n; i++) {
		if ((childpid = fork()))
			break;
		if(childpid == -1){
			printf("%s: ", argv[0]);
			perror("Error:");
		}
	}
	char mybuf[nchars+1];
	for (j = 0; j < nchars; j++) {
		mybuf[j] = getc(stdin);
	}
	mybuf[nchars] = '\0';

	fprintf(stderr, "i:%d  process ID:%ld  mybuf:%s\n",
                        i, (long)getpid(), mybuf);
	return 0;
}
