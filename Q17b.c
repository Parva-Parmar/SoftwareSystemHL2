#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int fd[2];
	pipe(fd);

	if(!fork()){
		close(1);
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls","ls","-l",(char*)NULL);
	}
	else{
		close(0);
		close(fd[1]);
		dup2(fd[0],0);
		execlp("wc","wc",(char*)NULL);
	}
}
