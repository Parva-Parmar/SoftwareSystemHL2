#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
#include<stdlib.h>


void handler(int sig){
    printf("ITIMER_REAL: caught signal %d\n",sig);
}

int main(){
    struct itimerval timer;

    signal(SIGALRM,handler);

    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_usec = 10;

    if(setitimer(ITIMER_REAL,&timer,NULL) == -1){
        perror("setitimer");
        exit(1);
    }
    while(1){
        pause();
    }
}