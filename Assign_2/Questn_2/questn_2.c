#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char* argv[]){

	int fd=0;
	
	if(argc != 3){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\" Filename mode\" run \n");
		return -1;
	}
	
	if(!strcasecmp(argv[2],"read")){
		fd = open(argv[1],O_RDONLY);
	}
	else if(!strcasecmp(argv[2],"write")){
		fd = open(argv[1],O_WRONLY);
	}
	else if(!strcasecmp(argv[2],"read-write")){
		fd = open(argv[1],O_RDWR);
	}
	else{
		printf("\nError : No such mode exist\n");
		return -1;
	}
	
	if(fd == -1){
		printf("Error: Cannot open specified file\n");
		return -1;
	}

	for(int i=0;argv[2][i] != '\0';++i){
		argv[2][i] = tolower(argv[2][i]);
	}	

	printf("\nFile successfully opened with file descriptor %d in %s mode\n",fd,argv[2]);
	
	close(fd);
	
	return 0;
}
