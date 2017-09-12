/*
 * Program 3.1 - Number 5
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
	int i, n, k, m;
	char option;
	if (argc != 7 && argc != 2){
		fprintf(stderr, "Usage: %s <-n x> <-k y> <-m z>\n", argv[0]);
		return 1;
	}
	while ((option = getopt(argc, argv, "hn:k:m:")) != -1){
		switch(option){
			case 'h':
				printf("Usage: %s <-n x> <-k y> <-m z>\n", argv[0]);
				printf("\t-n x: number of processes to create\n");
				printf("\t-k y: number of times to display processes\n");
				printf("\t-m z: length of time to sleep\n");
				printf("\t-h help\n");
				return 0;
				break;
			case 'n':
				n = atoi(optarg);
				break;
			case 'k':
				k = atoi(optarg);
				break;
			case 'm':
				m = atoi(optarg);
				break;
		}
	}

	for (i = 1; i < n; i++){
		if (childpid = fork())
			break;
	}
	for(i = 0; i < k; i++){
		fprintf(stderr, "i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
				i, (long)getpid(), (long)getppid(), (long)childpid);
		sleep(m);
	}
	return 0;
}
