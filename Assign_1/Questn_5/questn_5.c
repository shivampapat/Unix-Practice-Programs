#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){

	int fd=0,ret=0;
	char arr[11];

	if(argc !=2){
		printf("Error: Unmatched argument count\n");
		printf("Execute command as exefile filename\n");
		printf("OR\n");
		printf("Run command through make file as: make ARGS=\"File name\" run\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1){
		printf("Error: Cannot open the specified file\n");
		return -1;
	}
	printf("File opened successfully with file descriptor =%d\n",fd);
	
	//Read first 10 characters
	ret= read(fd,arr,10);
	if(ret == -1){
		printf("Error: Unable to read file\n");
		return -1;
	}
	 
	printf("Data read from file is %s\n",arr);
	close(fd);

	return 0;
}
