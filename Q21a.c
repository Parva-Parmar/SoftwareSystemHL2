#include <stdio.h>       
#include <fcntl.h>       
#include <unistd.h>      
#include <sys/types.h>   
#include <sys/stat.h>    


int main(){
	char buff1[80];
	char buff2[]="Hello from A";

	int fd1 = open("fifo21a",O_WRONLY);
	int fd2 = open("fifo21b",O_RDONLY);

	write(fd1,buff2,sizeof(buff2));

	read(fd2,buff1,sizeof(buff1));
	printf("The text from B is : %s",buff1);

    close(fd1);
    close(fd2);
    return 0;
}
