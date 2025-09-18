#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	char buff[80];
	int fd[2];
	pipe(fd);

	if(fork()){
		close(fd[0]); 
		printf("Enter message to the child\n");
		scanf("%[^\n]",buff);
		write(fd[1],buff,sizeof(buff));
	}
	else{
		close(fd[1]);
		read(fd[0],buff,sizeof(buff));
		printf("The message from parent is: %s\n",buff);
	}
	wait(0);
}
