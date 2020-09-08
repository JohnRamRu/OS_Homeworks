#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

int main(){
	char command[BUFF_SIZE];
	while(1){
		char directory[BUFF_SIZE];
		getcwd(directory, sizeof(directory));
        printf("Shell: %s : ", directory);
		fgets(command, BUFF_SIZE, stdin);
		command[strlen(command) - 1] = '\0';
        system(command);
	}
	return 0;
}