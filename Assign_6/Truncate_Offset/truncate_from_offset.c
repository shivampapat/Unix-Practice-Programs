#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int main(int argc,char* argv[]){

	int fd=0;
	int ret=0;
	char filename[512]={'\0'};

	struct stat statbuf;

	if(argc !=3){
		printf("error: unmatched argument count\n");
		return -1;
	}

	fd = open(argv[1],O_RDWR);

	if(fd == -1){
	  	printf("Error opening file");
	    return -1;
	}
	
	//SHift offset to given offset
	lseek(fd,atoi(argv[2]),SEEK_SET);

	ret = ftruncate(fd,atoi(argv[2]));

	if(ret == -1){
		printf("Error: cannot truncate");
		return -1;
	}

	close(fd);



	return 0;
}