/*
	C program to write and read a structure object in a file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>     
#include<string.h>

//Employee structure
struct Emp{
	char emp_name[20];
	char emp_addr[50];
	int emp_ID;
	int emp_age;
};

//FUnction to display the employee info
void Display_Emp(struct Emp employees){
	
	printf("\nData of the employee is\n");
	printf("\nName : %s",employees.emp_name);
	printf("\nAddress : %s",employees.emp_addr);
	printf("\nID : %d",employees.emp_ID);
	printf("\nAge : %d\n",employees.emp_age);
}

//Main function
int main(int argc, char* argv[]){

	int fd= 0, ret=0;
	int fd_read=0;
	struct Emp employee = {"Shivam","Bhosari",12,21};
	struct Emp employee_read;	

	//Command line arguments mismatched
	if(argc !=2){
	
		printf("Error: Argument count unmatched\n");
		printf("Run as make ARGS=filename run \n");
		return -1;
	}	

	//Create new file to write structure object into it
	fd = open(argv[1],O_RDWR | O_CREAT);
	if(fd == -1){
		printf("Error: Cannot create specified file\n");
		return -1;
	}
	
	//Writing structure to file
	ret = write(fd,&employee,sizeof(employee));	

	//Bring the offset to start again to read the object
	lseek(fd,0,SEEK_SET);

	//Reading structure from file
	ret = read(fd,&employee_read,sizeof(employee_read));	

	//Displaying both objects 
	Display_Emp(employee);
	Display_Emp(employee_read);

	return 0;
}
