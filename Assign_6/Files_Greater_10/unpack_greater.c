#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){

	int fd = 0;
	int ret = 0;

	//File parameters
	long int size=0;
	char buff[512]={'\0'};
	char filename[257];

	if(argc !=2){
		printf("error: unmatched argument count\n");
		return -1;
	}


	fd = open(argv[1],O_RDONLY);
	if(fd == -1){
	  	printf("Error opening in file");
	    return -1;
	}

	while(1){
		ret = read(fd,filename,sizeof(filename)-1);
		if(ret == 0){
			break;
		}
		ret = read(fd,&size,sizeof(size));
		if(size > 20){
			printf("Filename : %s\n",filename);
		}
		lseek(fd,size,SEEK_CUR);
	}	

	close(fd);

	return 0;
}