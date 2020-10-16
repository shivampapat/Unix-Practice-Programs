#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){

	int fd = 0,fd_new=0;
      int fd_read = 0;
      int ret = 0,ret_2=0;
      long int size=0;
      char buff[512]={'\0'};
     
     
      char filename[257];

     
      fd = open(argv[1],O_RDONLY);

      if(fd == -1){
            printf("Error: FIle cannot be opened\n");
            return -1;
      }

      //UNpacking all files

      while(1){

            ret = read(fd,filename,sizeof(filename)-1);
            if(ret == 0){
                  break;
            }
            fd_new = creat(filename,0777);
            fd_read = open(filename,O_RDWR);

            ret = read(fd,&size,sizeof(size));
            if(ret == 0){
                  break;
            }
            if(size < 512){
                  ret_2 = read(fd,buff,size);
                  ret_2 = write(fd_new,buff,size);
            }
            else{
                  while(size >0 || ret_2 != 0){
                        ret_2 = read(fd,buff,sizeof(buff)-1);
                        size = size - ret_2;
                        ret_2 = write(fd_new,buff,ret_2);
                  }      
            }
      }

	return 0;
}