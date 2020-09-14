#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char* argv[]){

	int fd=0,ret=0;
	
	if(argc != 3){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\" Filename mode\" run \n");
		return -1;
	}
	
	if(!strcasecmp(argv[2],"read")){
		
		ret = access(argv[1],R_OK);
		if(ret == 0){
			printf("Success: Input file can be open in read mode\n");
		}
		else{
			printf("Read Permission denied.\n");
		}
	}
	else if(!strcasecmp(argv[2],"write")){
		
		ret = access(argv[1],W_OK);
		if(ret == 0){
			printf("Success: Input file can be open in write mode\n");
		}
		else{
			printf("Write Permission denied.\n");
		}
	}
	else if(!strcasecmp(argv[2],"execute")){
		
		ret = access(argv[1],X_OK);
		if(ret == 0){
			printf("Success: Input file can be executed\n");
		}
		else{
			printf("Execute Permission denied.\n");
		}
	}
	
	return 0;
}
