#include <stdio.h>       
#include <fcntl.h>       
#include <unistd.h>      
#include <sys/types.h>   
#include <sys/stat.h>    


int main(){
	char buff1[]="Hello from B";
	char buff2[80];

	int fd1 = open("fifo21a",O_RDONLY);
	int fd2 = open("fifo21b",O_WRONLY);

    read(fd1,buff2,sizeof(buff2));
    printf("The text from B is : %s\n",buff2);
    
	write(fd2,buff1,sizeof(buff1));

    close(fd1);
    close(fd2);
    return 0;
}
