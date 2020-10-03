/*
	C program to 
	Accept directory and copy 10 bytes from each regular files into new file
*/

#include<stdio.h>
#include<dirent.h>    // For dirent structure
#include<fcntl.h>     // creat, O_RDONLY  
#include<unistd.h>    //read write


int main(int argc, char* argv[]){

	int dir_fd =0, fd_new=0;
	int fd_temp=0;
	int ret=0;
	char buff[11];
	char temp_filename[512];
	
	DIR* dir;
	struct dirent* nextfile;


	if(argc != 3){
	
		printf("Error: Unmatched argument count\n");
		printf("Run as..  make ARGS=\"directory_name newfile\"  \n");
		return -1;
	}
	
	//Direcotry opening
	dir = opendir(argv[1]);
	dir_fd = dirfd(dir);
	
	
	if(dir_fd == -1){
	
		printf("Cannot open directory\n");
		return -1;
	}

	//Creating new final merged file
	
	fd_new = creat(argv[2],0777);
	
	if(fd_new == -1){
		printf("Error : Unable to create new file\n");
		return -1;
	}

	
	while((nextfile = readdir(dir)) != NULL){
		
		if(nextfile->d_type == DT_REG){
			
			sprintf(temp_filename,"%s/%s",argv[1],nextfile->d_name);
			fd_temp = open(temp_filename,O_RDONLY);
			
			if(fd_temp == -1){
				printf("Error : Unable to open the file\n");
				continue;
			}
			
			ret = read(fd_temp,buff,10);
			
			write(fd_new,buff,ret);
			write(fd_new,"\n",1);
		}
		
	}


	closedir(dir);

	return 0;
}
