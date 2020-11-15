#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){

	int fd_dir=0;
	int ret=0;
	char filename[512]={'\0'};

	DIR* dir;
	struct dirent* nextfile;

	struct stat statbuf;

	if(argc !=2){
		printf("error: unmatched argument count\n");
		return -1;
	}

	dir = opendir(argv[1]);
	fd_dir = dirfd(dir);

	if(fd_dir == -1){
	  	printf("Error opening directory");
	    return -1;
	}

	while((nextfile = readdir(dir)) != NULL){

		if(nextfile->d_type == DT_REG){


			sprintf(filename,"%s/%s",argv[1],nextfile->d_name);
			stat(filename,&statbuf);

			if(statbuf.st_size > 100){
				ret = remove(filename);
				if(ret != 0){
					printf("Cannot delete file\n");
				}
			}
		}
	}

	closedir(dir);



	return 0;
}