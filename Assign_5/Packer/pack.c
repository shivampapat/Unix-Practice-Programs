#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){

	  int fd = 0,fd_2=0;
      int fd_dir = 0;
      int ret = 0,ret2=0;
      char buff[512]={'\0'};
     
      //For directories
      struct dirent * nextfile;
      DIR *dir;

      //For file information
      struct stat statbuf;
      char filename[257];

      dir = opendir(argv[1]);
      fd_dir = dirfd(dir);

      if(fd_dir == -1){
            printf("Error opening directory");
            return -1;
      }

      fd = creat("AllCombine.txt", 0777);
      fd = open("AllCombine.txt",O_RDWR);

      while((nextfile = readdir(dir)) != NULL){

      	if(nextfile->d_type == DT_REG){

      		sprintf(filename,"%s/%s",argv[1],nextfile->d_name);
      	
      		fd_2 = open(filename,O_RDONLY);
      		if(fd_2 == -1){
      			printf("Error opening in file");
      			continue;
      		}
      		stat(filename,&statbuf);
      		//Write into AllCombine.txt file

      		ret = write(fd,nextfile->d_name,sizeof(nextfile->d_name));
      		ret = write(fd,&(statbuf.st_size),sizeof(statbuf.st_size));
      		//Writing file content 

      		while((ret2 = read(fd_2,buff,sizeof(buff)-1)) != 0){
      				ret = write(fd,buff,ret2);		
      		}
      	}

      }


	return 0;
}