#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){

	int fd=0;
	int max =0,ret=0;
	char max_filename[512];
	char temp_filename[512];
	DIR* dir;
	struct dirent* nextfile;
	struct stat filest;
	
	if(argc != 2){
		printf("Error: Unmatched argument count\n");
		printf("Check readme for instructions to run\n");
		return -1;
	}
	
	dir = opendir(argv[1]);
	fd = dirfd(dir);
	
	if(fd == -1){
		printf("Error: No directory\n");
		return -1;
	}
	
	while((nextfile = readdir(dir)) != NULL){
		
		if(nextfile->d_type & DT_REG){
			sprintf(temp_filename,"%s%s",argv[1],nextfile->d_name);
			
			ret = stat(temp_filename,&filest);
			
			if(ret == 0){
				if(max < filest.st_size){
					max = filest.st_size;
					sprintf(max_filename,"%s",nextfile->d_name);
				}
			}
		}
		
	}
	
	printf("\nFile with largest size is %s\n",max_filename);
	

	return 0;
}
