#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]){
	
	int fd=0;
	int ret =0;
	
	fd = open(argv[1], O_CREAT | O_RDWR);
	
	if(fd == -1){
		printf("Error: Cannot open specific file\n");
		return -1;
	}
	
    ret = write(fd,"Shivam",6);
	
	
	//Creating hole of 1kb at end of file
	lseek(fd,1024,SEEK_SET);
	
	ret = write(fd,"Papat",5);
	
	close(fd);
	
	
	return 0;
}
