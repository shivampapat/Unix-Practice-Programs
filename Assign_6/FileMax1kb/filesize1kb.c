#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	DIR* dir;
	struct dirent* nextfile;
	struct stat sb;
	
	int fd=0,fdtemp=0;
	char filename[512];

	if(argc !=2){
		printf("Error: Command arguments mismatched\n");
		return -1;
	}

	dir = opendir(argv[1]);
	fd = dirfd(dir);

	if(fd == -1){
		printf("Cannot open specified directory\n");
		return -1;
	}

	while( (nextfile = readdir(dir)) != NULL){

		if((nextfile->d_type & DT_REG) == DT_REG){
			sprintf(filename,"%s/%s",argv[1],nextfile->d_name);			
			stat(filename,&sb);
			fdtemp = open(filename,O_RDWR);	
			if(sb.st_size > 1024){
				ftruncate(fdtemp,1024);	
			}
			else{			
				lseek(fdtemp,1023-sb.st_size,SEEK_END);
				write(fdtemp,"\0",1);
			}
			close(fdtemp);
		}
	}

	closedir(dir);


	return 0;
}
