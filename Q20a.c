#include <stdio.h>       
#include <fcntl.h>       
#include <unistd.h>      
#include <sys/types.h>   
#include <sys/stat.h>    

int main(){
	char buff[80];
	int fd = open("fifo20",O_WRONLY);
	printf("Enter some text: ");
	scanf("%[^\n]",buff);
	write(fd,buff,sizeof(buff));
	close(fd);
}
