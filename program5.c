/*
 * Program 3.1 - Number 7
 * Author: Taylor Freiner
 * Date: 9-11-17
 * Log: Adding getopt functionality 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main (int argc, char *argv[]){
	pid_t childpid = 0;
	int i, n;
	char option;
	if (argc != 2 && argc != 3){
		fprintf(stderr, "Usage: %s <-n x>\n", argv[0]);
		return 1;
	}
	while ((option = getopt(argc, argv, "hn:")) != -1){
		switch(option){
			case 'h':
				printf("usage: %s <-n x>\n", argv[0]);
				printf("\t-n x: number of processes to create\n");
				printf("\t-h help\n");
				return 0;
				break;
			case 'n':
				n = atoi(optarg);
				break;
		}
	}
	for (i = 1; i < n; i++){
		if (childpid = fork())
			break;
	}
	
	fprintf(stderr, "i:%d", i);
	fprintf(stderr, "  process ID:%ld", (long)getpid());
	fprintf(stderr, "  parent ID:%ld", (long)getppid());
	fprintf(stderr, "  child ID:%ld\n", (long)childpid);

	return 0;
}