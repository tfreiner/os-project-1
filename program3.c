/*
 * Program 3.1 - Number 5
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
	int i, j, n, k, m, option;
	char argval;
	if (argc != 7 && argc != 2){
		fprintf(stderr, "%s Error: Incorrect number of arguments\n", argv[0]);
		return 1;
	}
	while ((option = getopt(argc, argv, "hn:k:m:")) != -1){
		switch(option){
			case 'h':
				printf("usage: %s <-n positive_integer> <-k positive_integer> <-m positive_integer>\n", argv[0]);
				printf("\t-n: number of processes to create\n");
				printf("\t-k: number of times to display processes\n");
				printf("\t-m: length of time to sleep\n");
				printf("\t-h: help\n");
				return 0;
				break;
			case 'n':
				argval = *optarg;
				if(isdigit(argval) && (atoi(optarg) > 0))
					n = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a positive integer\n", argv[0]);
					return 1;
				}
				break;
			case 'k':
				argval = *optarg;
				if(isdigit(argval) && (atoi(optarg) > 0))
					k = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a positive integer\n", argv[0]);
					return 1;
				}
				break;
			case 'm':
				argval = *optarg;
				if(isdigit(argval) && (atoi(optarg) > 0))
					m = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a positive integer\n", argv[0]);
					return 1;
				}
				break;
			case '?':
				fprintf(stderr, "%s Error: usage: <-n positive_integer> <-k positve_integer> <-m positive_integer>\n", argv[0]);
				return 1;
				break;
		}
	}

	for (i = 1; i < n; i++){
		if ((childpid = fork()))
			break;
		if(childpid == -1){
			printf("%s: ", argv[0]);
			perror("Error: ");
		}
	}
	for(j = 0; j < k; j++){
		fprintf(stderr, "i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
				i, (long)getpid(), (long)getppid(), (long)childpid);
		sleep(m);
	}
	return 0;
}
