#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	int fd_open = 0;
	int fd_create=0;
	char buff[1024];
	int ret=0;
	
	if(argc != 3){
		printf("Error: Unmatched argument count\n");
		printf("PLease read the readme file to run the progam\n");
		return -1;
	}
	
	fd_open = open(argv[1],O_RDONLY);
	
	if(fd_open == -1){
		printf("Error: No such file exists\n");
		return -1;
	}
	
	fd_create = creat(argv[2],0777);
	
	if(fd_create == -1){
		printf("Error: File cannot be created\n");
		return -1;
	}
	
	while(1){
		
		ret = read(fd_open,buff,sizeof(buff));
		if(ret == 0){
			break;
		}
		write(fd_create,buff,ret);
	}
	
	close(fd_open);
	close(fd_create);
	

	return 0;
}
