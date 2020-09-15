#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char* argv[]){

	int fd_dir1=0,fd_dir2=0;
	int ret=0;
	DIR* dir1;
	DIR* dir2;
	struct dirent* nextfile;
	char file1[512],file2[512];;
	
	
	
	if(argc != 3){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\"Directory1 Directory2\" run \n");
		return -1;
	}

	dir1 = opendir(argv[1]);
	fd_dir1 = dirfd(dir1);

	if(fd_dir1 == -1){
		printf("Error : Directory not found");
		return -1;
	}	
	
	dir2 = opendir(argv[2]);
	fd_dir2 = dirfd(dir2);

	if(fd_dir2 == -1){
		printf("Error : Directory not found");
		return -1;
	}	
	
	
	while((nextfile = readdir(dir1)) != NULL){
	
			
			sprintf(file1,"%s%s",argv[1],nextfile->d_name);
			sprintf(file2,"%s%s",argv[2],nextfile->d_name);
			
			
			ret = rename(file1,file2);
			if(ret == -1){
				continue;
			}
	}	
	
	printf("\nSuccess\n");
	
	closedir(dir1);
	closedir(dir2);

	return 0;
}
