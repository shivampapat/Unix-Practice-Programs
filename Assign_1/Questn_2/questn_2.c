#include<stdio.h>

int main(int argc, char* argv[]){
	
	if(argc != 2){
		printf("Error : Argument count unmatched\n");
		printf("Execute as exefile your name");
		return -1;
	}
	
	printf("Your name is  %s",argv[1]);
	
	return 0;
}
