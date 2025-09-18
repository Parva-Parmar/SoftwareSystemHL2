#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int key,shmid;
    char *data;
    key = ftok(".",'b');

    shmid = shmget(key,1024,0);

    data = shmat(shmid,0,0);
    printf("Text from the shared memory: %s\n",data);
    getchar();
}