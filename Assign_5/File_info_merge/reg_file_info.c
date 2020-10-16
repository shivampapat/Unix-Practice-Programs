#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

void FindPerms(int mode,char permissions[]){
      int mask=1,j=8;

      if((mode & 0b100000000) ==  0b100000000){
            permissions[0] ='r'; 
      }
      else{
            permissions[0] ='-';
      }
      if((mode & 0b10000000) == 0b10000000){
            permissions[1] ='w'; 
      }
      else{
            permissions[1] ='-';
      }
      if((mode & 0b1000000)  == 0b01000000){
            permissions[2] ='x'; 
      }
      else{
            permissions[2] ='-';
      }
      if((mode & 0b100000)  == 0b100000){
            permissions[3] ='r'; 
      }
      else{
            permissions[3] ='-';
      }
      if((mode & 0b10000)  == 0b10000){
            permissions[4] ='w'; 
      }
      else{
            permissions[4] ='-';
      }
      if((mode & 0b1000)  == 0b1000){
            permissions[5] ='x'; 
      }
      else{
            permissions[5] ='-';
      }
      if((mode & 0b100)  == 0b100){
            permissions[6] ='r'; 
      }
      else{
            permissions[6] ='-';
      }
      if((mode & 0b10)  == 0b10){
            permissions[7] ='w'; 
      }
      else{
            permissions[7] ='-';
      }
      if((mode & 0b1)  == 0b1){
            permissions[8] ='x'; 
      }
      else{
            permissions[8] ='-';
      }
      
      permissions[9]='\0';
}

void DisplayInfo(struct stat statbuf,  char permissions[]){
            printf("Device ID: %ld\n",statbuf.st_dev);
            printf("Inode ID: %ld\n",statbuf.st_ino);
            printf("Number of hard links: %ld\n",statbuf.st_nlink);
            printf("User ID of file owner: %d\n",statbuf.st_uid);
            printf("User ID of file group: %d\n",statbuf.st_gid);
            printf("Total file size: %ld\n",statbuf.st_size);
            printf("Block size: %ld\n",statbuf.st_blksize);
            printf("Blocks allocated: %ld\n",statbuf.st_blocks);
            printf("Time of last access: %ld\n",statbuf.st_atime);
            printf("Time of last modification: %ld\n",statbuf.st_mtime);
            printf("Time of last status change: %ld\n",statbuf.st_ctime);
            //Permission mode of file
            FindPerms(statbuf.st_mode,permissions);
            printf("Permissions of file : %s\n",permissions);   	
}


int main(int argc, char *argv[]){

      int fd = 0;
      int fd_dir = 0;
      int ret = 0;
      char permissions[10];

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

      fd = creat("Mergefile.txt", 0777);
      fd = open("Mergefile.txt",O_RDWR);

      while((nextfile = readdir(dir)) != NULL){
            
            if(nextfile->d_type == DT_REG){
                  sprintf(filename, "%s/%s", argv[1],nextfile->d_name);
                  if(stat(filename, &statbuf) == 0){     //Success
                        //Writing file information in Mergefile
                       printf("\nsize is %ld\n",sizeof(nextfile->d_name));
                       ret = write(fd,&(nextfile->d_name),sizeof(nextfile->d_name));
                       ret = write(fd,&statbuf,sizeof(statbuf));

                  }
                  else{
                        printf("Error: file data cannot be read");
                        continue;
                  }
            }
      }

      lseek(fd,0,SEEK_SET);

      //Reading all files and their infos from mergedfile.txt
      printf("\nReading files and info from mergedfile.txt\n");

      while(1){
            ret = read(fd,&filename,sizeof(filename)-1);
            if(ret == 0){
                  break;
            }
            printf("\n\nFilename: %s\n",filename);

            ret = read(fd,&statbuf,sizeof(statbuf));
            if(ret == 0){
                  break;
            }

            DisplayInfo(statbuf,permissions);
       
      }


      return 0;
}