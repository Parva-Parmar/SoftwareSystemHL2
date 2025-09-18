#include<stdio.h>
#include<unistd.h>


int main(){
	char buff1[80];
	char buff2[80];
	int fd1[2];
	int fd2[2];
	int lock[2];
	pipe(lock);
	pipe(fd1);
	pipe(fd2);

	write(lock[1],"T",1);

	if(fork()){
		close(fd1[1]);
		close(fd2[0]);

		char token;

		read(lock[0],&token,1);
		printf("Enter the message to the child\n");
		fflush(stdout);
		scanf(" %[^\n]",buff2);

		write(lock[1],&token,1);
		write(fd2[1],buff2,sizeof(buff2));
		read(fd1[0],buff1,sizeof(buff1));
		printf("The message to the parent is %s\n",buff1);
	}
	else{
		close(fd1[0]);
		close(fd2[1]);

		char token;

		read(lock[0],&token,1);
		printf("Enter the message to the parent\n");
		fflush(stdout);
		scanf(" %[^\n]",buff1);

		write(lock[1],&token,1);
		write(fd1[1],buff1,sizeof(buff1));
		read(fd2[0],buff2,sizeof(buff2));
		printf("The message to the child is %s\n",buff2);
	}
}
