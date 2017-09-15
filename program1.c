/*
 * Program 3.1 - Numbers 1 - 3
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
	int i, n, option;
	char argval;
	if (argc != 2 && argc != 3){
		fprintf(stderr, "%s Error: Incorrect number of arguments\n", argv[0]);
		return 1;
	}
	while ((option = getopt(argc, argv, "hn:")) != -1){
		switch (option){
			case 'h':
				printf("usage: %s <-n positive_integer> \n", argv[0]);
				printf("\t-n: number of processes to create\n");
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
			case '?':
				fprintf(stderr, "%s Error: usage: %s <-n positive_integer>\n", argv[0], argv[0]);
				return 1;
				break;
		}
	}
	for (i = 1; i < n; i++){
		if((childpid = fork()))
			break;
		if(childpid == -1){
			printf("%s: ", argv[0]); 
			perror("Error:");
		}
	}
	fprintf(stderr, "i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
			i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
