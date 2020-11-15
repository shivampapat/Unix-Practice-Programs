#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char* argv[]){

	int fd_dir=0,fd_file=0;
	char path[256]={'\0'};

	DIR* dir;

	if(argc !=3){
		printf("error: unmatched argument count\n");
		return -1;
	}

	dir = opendir(argv[1]);
	fd_dir = dirfd(dir);

	if(fd_dir == -1){
	  	printf("Error opening directory");
	    return -1;
	}

	//Creating new file in the given directory
	sprintf(path,"%s/%s",argv[1],argv[2]);

	fd_file = creat(path,0777);
	if(fd_file == -1){
		printf("Error creating file");
	    return -1;
	}

	close(fd_file);
	closedir(dir);

	return 0;
}
