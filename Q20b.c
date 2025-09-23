#include <stdio.h>       
#include <fcntl.h>       
#include <unistd.h>      
#include <sys/types.h>   
#include <sys/stat.h>  

int main(){
	char buff[80];
	int fd = open("fifo20",O_RDONLY);
	read(fd,buff,sizeof(buff));
	printf("The data of fifo is: %s\n",buff);
}
