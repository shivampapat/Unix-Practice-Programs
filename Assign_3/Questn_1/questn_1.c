#include<stdio.h>
#include<dirent.h>   // For directory stream, dirent is defined here


int main(int argc, char* argv[]){

	DIR* dir;                 // Structure for directory descriptor
	struct dirent* nextfile;
	int ret=0;
	

	if(argc != 2){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\"Directory name\" run \n");
		return -1;
	}
	
	
	dir = opendir(argv[1]);   // Returns directory stream for the given input directory
	ret = dirfd(dir);
	
	if(ret == -1){
		printf("Error : Directory not found");
		return -1;
	}
	
	//readdir() Read next entry in the dierctory (Return type is dirent)
  	printf("Contents of the given repository are : \n");
  	while((nextfile = readdir(dir)) != NULL){
  		printf("%s\n",nextfile->d_name);
  	}
  	printf("\n");
  
	
	closedir(dir);  // Returns int, 0 = true,  -1 = failure

	return 0;
}
