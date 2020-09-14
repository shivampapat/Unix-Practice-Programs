#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char* argv[]){

	int fd=0,ret=0;
	char arr[1024];
	int bytes_to_read=0;
	
	
	if(argc != 3){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\" Filename bytes to read\" run \n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	bytes_to_read = atoi(argv[2]);
	
	
	if(fd == -1){
		printf("Error: Cannot open specified file\n");
		return -1;
	}

	
	printf("\nFile successfully opened with file descriptor %d\n",fd);
	
	while(1){
		
		if(bytes_to_read <1024){
			ret = read(fd,arr,bytes_to_read);	
		}
		else{
			ret = read(fd,arr,1024);
		}
		
		write(1,arr,ret);
		bytes_to_read -= ret;

		if(ret == 0 || bytes_to_read ==0){
			break;
		}
	}
	printf("\n");
	
		
	close(fd);
	
	return 0;
}
