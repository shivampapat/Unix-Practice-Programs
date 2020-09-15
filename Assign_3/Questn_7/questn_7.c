#include<stdio.h>
#include<dirent.h>
#include<unistd.h>  /// unlink sys call
#include<sys/stat.h>

int main(int argc, char* argv[]){

	int fd_dir=0,ret =0;
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
	fd_dir = dirfd(dir);
	
	if(fd_dir == -1){
		printf("Error: No directory\n");
		return -1;
	}
	
	while((nextfile = readdir(dir)) != NULL){
	
		if(nextfile->d_type & DT_REG){
			sprintf(temp_filename,"%s%s",argv[1],nextfile->d_name);
			ret  = stat(temp_filename, &filest);
			
			if(ret == 0){
				if(filest.st_size == 0){
					unlink(temp_filename);
				}
			}
		}
		
	}	
		

	return 0;
}
