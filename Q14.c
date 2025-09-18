#include<stdio.h>
#include<unistd.h>

int main(){
	int i,j,fd[2];
	char buff[80];
	i = pipe(fd);
	printf("i = %d",i);
	j = write(fd[1],"hello\n",7);
	read(fd[0],buff,j);
	printf("From pipe: %s\n", buff);
}
