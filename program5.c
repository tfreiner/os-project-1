/*
 * Program 3.1 - Number 7
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

int main (int argc, char *argv[]){
	pid_t childpid = 0;
	int i, n, option;
	char argval;
	if (argc != 2 && argc != 3){
		fprintf(stderr, "%s Error: Incorrect number of arguments\n", argv[0]);
		return 1;
	}
	while ((option = getopt(argc, argv, "hn:")) != -1){
		switch(option){
			case 'h':
				printf("usage: %s <-n positive_integer>\n", argv[0]);
				printf("\t-n: number of processes to create\n");
				printf("\t-h: help\n");
				return 0;
				break;
			case 'n':
				argval = *optarg;
				if(isdigit(argval) && (atoi(optarg) > 0))
					n = atoi(optarg);
				else{
					fprintf(stderr, "%s Error: Argument must be a digit\n", argv[0]);
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
		if ((childpid = fork()))
			break;
		if(childpid == -1){
			printf("%s: ", argv[0]);
			perror("Error: ");
		}
	}
	
	fprintf(stderr, "i:%d", i);
	fprintf(stderr, "  process ID:%ld", (long)getpid());
	fprintf(stderr, "  parent ID:%ld", (long)getppid());
	fprintf(stderr, "  child ID:%ld\n", (long)childpid);

	return 0;
}
