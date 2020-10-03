/*
	C program to accept filename and a position for offset
	and
	read 20 bytes from that offset
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	int fd=0;
	int offset_position = 0;
	int ret= 0;
	char buff[21];

	if(argc != 3){
	
		printf("Error: Unmatched argument count\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);

	if(fd == -1){
		printf("Error: Cannot open specified file\n");
		return -1;
	}
	
	offset_position = atoi(argv[2]);

	//offset by given position
	lseek(fd,offset_position,SEEK_SET);

	//Reading 20 bytes after this offset , from the file
	
	ret = read(fd,buff,20);	
	
	printf("%d bytes are read successfully from the file\n",ret);
	printf("Data read was: \n");
	write(1,buff,ret);

	printf("\n");

	return 0;
}
