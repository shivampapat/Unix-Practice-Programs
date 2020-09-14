//Accept file through command args and Read whole file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){

	int fd=0,ret=0;
	
	
	if(argc !=3){
		printf("Error: Unmatched argument count\n");
		printf("Execute command as exefile filename\n");
		printf("OR\n");
		printf("Run command through make file as: make ARGS=\"File name StringtoWrite\" run\n");
		return -1;
	}

	fd = open(argv[1],O_WRONLY);
	
	if(fd == -1){
		printf("Error: Cannot open the specified file\n");
		return -1;
	}
	printf("File opened successfully with file descriptor =%d\n",fd);


	//Write String in file
	
	ret = write(fd,argv[2],strlen(argv[2]));

	if(ret == -1){
		printf("Cannot read file");
	}
	
	printf("\nData write to  the file successfully");

	close(fd);


	return 0;
}

