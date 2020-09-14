//Adding 2 numbers
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Error : Argument count unmatched\n");
		printf("Execute as exefile number1 number2\n");
		return -1;
	}
	
	int no1 = atoi(argv[1]);
	int no2 = atoi(argv[2]);

	printf("Addition of %d and %d is %d\n",no1,no2,no1+no2);

	return 0;
}
