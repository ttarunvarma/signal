
#include<stdio.h>
#include<signal.h>
int flag;
void handle_sigint_quit(int sig) {
    printf("Caught signal %d\n", sig);
    flag =1;
}
int main() {
    signal(SIGINT, handle_sigint_quit);

    while (1){
        printf("Hello......\n");
        sleep(1);
        if(flag){
            signal(SIGQUIT, handle_sigint_quit);
            signal(SIGINT, SIG_IGN);  // On hitting  ctrl+C , the process will ignore as a response.
        }
    }
    return 0;
}
/*
Hello......
Hello......
^CCaught signal 2  // Hit Ctrl+C
Hello......
Hello......
^CHello......    //ignored Ctrl+C
^CHello......
Hello......
^\Caught signal 3  // Hit ctrl+\
Hello......
Hello......
^CHello......
Hello......
Hello......
^\Caught signal 3
Hello......
Hello......
Hello......
^Z                //hit ctrl+z
[5]+  Stopped                 ./script_sig.sh

Displaying Hello Infinitely.
Ctrl+C : causes "Caught Signal 2" as it has been handled.
Finally Terminated by Ctrl+z
