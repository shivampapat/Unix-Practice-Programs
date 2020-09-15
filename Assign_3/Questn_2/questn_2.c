#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>


int main(int argc, char* argv[]){

	int ret =0;
	DIR* dir;
	struct dirent* nextfile;
	
	
	if(argc != 2){
		printf("Error: Unmatched arguments\n");
		printf("Run through make file as  make ARGS=\"Directory name\" run \n");
		return -1;
	}

	dir = opendir(argv[1]);
	ret = dirfd(dir);
	
	if(ret == -1){
		printf("Error: Directory not found\n");
		return -1;	
	}
	
	printf("Files under given directory with their types : \n");
	while((nextfile = readdir(dir)) != NULL){
		switch (nextfile->d_type)
    	{
			case DT_DIR:
				printf("Directory: %s\n", nextfile->d_name);
				break;
			case DT_REG:
				printf("File     : %s\n", nextfile->d_name);
				break;
			default:
				printf("Other    : %s\n", nextfile->d_name);
    	}
		
	}
	
	printf("\n");
	
	closedir(dir);
	
	

	return 0;
}
