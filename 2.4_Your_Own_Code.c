#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){
	char name[10];
	printf("Please input your name :");
	fgets(name, sizeof(name),stdin);
	printf("My name is:");
	puts(name);
	printf("Child proccess => PPID =%d, PID=%d\n", getppid(), getpid());
	exit(0);
}

void parentTask(){
	printf("Parent process => PID=%d\n", getpid());
	printf("Process is finished.\n");
}

void waits(){
	printf("Waiting for child process to finish...\n");
	wait(NULL);
	printf("Child process finished.\n");
}

int main(void){

	for (int i=0; i<4; i++){
	pid_t pid = fork();

		if(pid==0){
			childTask();
		}

		else if(i==3){
			waits();
			parentTask();
		}

		else waits();
		}
	return EXIT_SUCCESS;
	}
