#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char* argv[]){

	int ret =0,flag = 0;
	DIR* dir;
	struct dirent* nextfile;
	
	
	if(argc != 3){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\"Directory_name Filename\" run \n");
		return -1;
	}

	dir = opendir(argv[1]);
	ret = dirfd(dir);
	
	if(ret == -1){
		printf("Error: Directory not found\n");
		return -1;	
	}
	
	while((nextfile = readdir(dir)) != NULL){
		
 			if(strcmp(argv[2], nextfile->d_name) == 0 ){
 				printf("File found\n");
 				flag = 1;
 				break;
 			}   	
	}
	
	if(flag == 0){
		printf("Error: File not found in the directory");
	}
	
	printf("\n");
	
	closedir(dir);
	
	

	return 0;
}
