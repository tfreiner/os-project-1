/*
 * Program 3.1 - Number 5
 * Author: Taylor Freiner
 * Date: 9-13-17
 * Log: Adding error checking
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, j, n, k, m;
	char option, argvalue;
	if (argc != 7 && argc != 2){
		fprintf(stderr, "%s Error: Incorrect number of arguments\n", argv[0]);
		return 1;
	}
	while ((option = getopt(argc, argv, "hn:k:m:")) != -1){
		switch(option){
			case 'h':
				printf("usage: %s <-n x> <-k y> <-m z>\n", argv[0]);
				printf("\t-n x: number of processes to create\n");
				printf("\t-k y: number of times to display processes\n");
				printf("\t-m z: length of time to sleep\n");
				printf("\t-h help\n");
				return 0;
				break;
			case 'n':
				argvalue = *optarg;
				if(isdigit(argvalue))
					n = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a digit\n", argv[0]);
					return 0;
				}
				break;
			case 'k':
				argvalue = *optarg;
				if(isdigit(argvalue))
					k = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a digit\n", argv[0]);
					return 0;
				}
				break;
			case 'm':
				argvalue = *optarg;
				if(isdigit(argvalue))
					m = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a digit\n", argv[0]);
					return 0;
				}
				break;
			case '?':
				fprintf(stderr, "%s Error: usage: %s <-n x>\n", argv[0], argv[0]);
				return 1;
				break;
		}
	}

	for (i = 1; i < n; i++){
		if (childpid = fork())
			break;
	}
	for(j = 0; j < k; j++){
		fprintf(stderr, "i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
				i, (long)getpid(), (long)getppid(), (long)childpid);
		sleep(m);
	}
	return 0;
}
