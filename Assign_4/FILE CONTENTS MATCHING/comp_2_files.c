/*
	C program to compare 2 file contents
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

	int fd1=0,fd2=0;
	char buff1[512],buff2[512];
	int ret1=0,ret2=0;
	
	if(argc != 3){
		printf("Invalid arugment count\n");
		printf("Run as..   make ARGS=\"filename1 filename2\" run  \n");
		return -1;
	}
	
	fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1){
		printf("Error: Cannot open the first specified file\n");
		return -1;
	}

    fd2 = open(argv[2],O_RDONLY);
	if(fd2 == -1){
		printf("Error: Cannot open the second specified file\n");
		return -1;
	}
	
	while(1){
		
		ret1 = read(fd1,buff1,511);
		ret2 = read(fd2,buff2,511);	
	
		if(ret1 == 0 || ret2 ==0){
			break;
		}
		if(strcmp(buff1,buff2) != 0)
			break;
	
	}
	
	if(ret1 ==0 && ret2 == 0){
		printf("File data is same\n");
	}
	else{
		printf("File data is not same\n");
	}
	
	

	return 0;
}

