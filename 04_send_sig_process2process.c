#include<stdio.h>
#include<signal.h>
int alarm;
void handle_sigalrm(int sig) {
    printf("Caught signal %d\n", sig);
    alarm = 1;
}
int main() {
        int ret;
        ret = fork();
        switch(ret){
        case 0:
                sleep(5);
                kill (getppid(), SIGALRM);  // child process sends SIGALRM to parent process.
                exit(0);   // child process terminates
        }
        signal(SIGALRM, handle_sigalrm);
        pause();  // parent process comes out from pause state after receiving SIGALRM from child process
        if(alarm){
                printf("Handle executed\n");
        }
    return 0;
}
/*

Caught signal 14
Handle executed
----------------

sleep Vs pause
sleep needs time in secs to go in sleep state.
But pause remains for infinite time

*/
