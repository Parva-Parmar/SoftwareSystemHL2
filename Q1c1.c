#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("ITIMER_PROF: caught signal %d\n",sig);
}

int main(){
    struct itimerval timer;
    signal(SIGPROF,handler);

    timer.it_value.tv_sec = 10;
    timer.it_interval.tv_sec = 10;

    if(setitimer(ITIMER_PROF,&timer,NULL) == -1){
        perror("setitimer");
        exit(1);
    }

    while(1);
}