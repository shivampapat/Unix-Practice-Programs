#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

char* format(char* str, time_t t){
	
	strftime(str,36, "%d.%m.%Y  %H:%M:%S",localtime(&t));
	return str;
}


int main(int argc, char* argv[]){

	int fd=0,ret=0;
	struct stat sb;
	
	char date[36];
	
	//The stat structure is defined in <bits/stat.h>, which is included from <sys/stat.h>
	
	if(argc != 2){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\" Filename\" run \n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1){
		printf("Error: Cannot open specified file\n");
		return -1;
	}

	
	printf("\nFile successfully opened with file descriptor %d\n",fd);
	
	
	ret = fstat(fd,&sb);
	
	if(ret){
		printf("Error\n");
		return -1;
	}
	
	printf("\nFile information : \n");
	
	printf("Device ID                   : %lu\n",sb.st_dev);
	printf("Inode number                : %lu\n",sb.st_ino);
	printf("Mode                        : %u\n",sb.st_mode);
	printf("Number of hard links        : %lu\n",sb.st_nlink);
	printf("User ID                     : %u\n",sb.st_uid);
	printf("Group ID                    : %u\n",sb.st_gid);
	printf("Total size in bytes         : %ld\n",sb.st_size);
	printf("Block size for file system  : %ld\n",sb.st_blksize);
	printf("Number of blocks allocated  : %ld\n",sb.st_blocks);
	printf("Last Access Time            :%s\n", format(date,sb.st_atime));
	printf("Last Modification Time      :%s\n", format(date,sb.st_mtime));
	printf("Last Status change Time     :%s\n", format(date,sb.st_ctime));
	
	
	close(fd);
	
	return 0;
}
