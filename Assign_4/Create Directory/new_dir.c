/*
	C program to accept a directory name 
	and
	Create new directory of that name
*/

#include<stdio.h>
#include<sys/stat.h>  // For mkdir()

int main(int argc, char* argv[]){

	int ret=0;
	
	if(argc !=2) {
		printf("Error: Argument count unmatched\n");
		printf("Run as makr ARGS=\"directoryname\" run\n");
		return -1;
	}
	
	ret = mkdir(argv[1],0777);
	
	if(ret == -1){
		printf("Error: Cannot create diriectory of the provided name\n");
		return -1;
	}

	printf("Success.. Directory created!!");

	return 0;
}
