#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
#include<stdlib.h>

void handler(int sig){
    printf("ITIMER_VIRTUAL: caught signal %d\n", sig);
}

int main(){
    struct itimerval timer;
    signal(SIGVTALRM,handler);
    timer.it_value.tv_sec = 10;
    timer.it_interval.tv_sec = 10;
    if(setitimer(ITIMER_VIRTUAL,&timer,NULL) == -1){
        perror("settimer");
        exit(1);
    }
    while(1);
}


/*
deku@Parva-Parmar:/media/deku/Data/Algo/Software systems/list2$ gcc Q1b1.c -o Q1b1
deku@Parva-Parmar:/media/deku/Data/Algo/Software systems/list2$ ./Q1b1
ITIMER_VIRTUAL: caught signal 26
ITIMER_VIRTUAL: caught signal 26
ITIMER_VIRTUAL: caught signal 26
^C
deku@Parva-Parmar:/media/deku/Data/Algo/Software systems/list2$ 
*/