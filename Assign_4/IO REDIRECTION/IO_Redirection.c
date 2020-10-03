/*
	Code to demonstrate IO direction through shell meta characters
	<  input file
	>  output file
	2> error file

	C program for addition of 2 numbers
	Numbers are kept in input.txt file 
	Ouptut will be redirected in output.txt file 

*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	int no1,no2;
	
	///no1 = atoi(argv[1]);
	//no2 = atoi(argv[2]);
	
	scanf("%d %d", &no1,&no2);
	
	printf("Addition of %d and %d is %d\n",no1,no2,no1+no2);
	printf("Redirection successfull\n");

	return 0;
}
