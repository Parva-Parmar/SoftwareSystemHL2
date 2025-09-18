#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int key, shmid;
	char *data;
	key = ftok(".",'b');

	shmid = shmget(key,1024,IPC_CREAT|0744);

	data = shmat(shmid,0,0);

	printf("Enter the text :");

	scanf("%[^\n]",data);
}
