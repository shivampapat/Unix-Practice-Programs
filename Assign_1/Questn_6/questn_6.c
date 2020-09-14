//Accept file through command args and Read whole file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

	int fd=0,ret=0;
	char arr[1024];
	
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


	//Read whole file
	
	ret = read(fd,arr,sizeof(arr));

	if(ret == -1){
		printf("Cannot read file");
	}
	
	printf("\nData from the file is :\n");
	
	while(ret !=0){
		write(1,arr,ret);
		ret = read(fd,arr,sizeof(arr));
		printf("\n");
	}

	close(fd);


	return 0;
}

