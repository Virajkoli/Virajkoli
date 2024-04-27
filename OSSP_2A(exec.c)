#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(int argc,char *argv)
{
    pid_t mypid ,forkreturn;
    forkreturn=fork();
    mypid=getpid();
    if(forkreturn>0)
    {   wait(NULL);
        printf("\nMy pid is %d",mypid);
        printf("\nI am a parent process executing the ps command\n");
        wait(NULL);
        system("ps");
    }
    else if(forkreturn==0)
    {  
        printf("\nMy pid is %d",mypid);
        printf("\nI am a child process executing the ls command\n");
        char *ls_args[]={"/bin/ls",NULL};
        execv("/bin/ls",ls_args);
        perror("execv");
        exit(EXIT_FAILURE);
    }
    else
    {   printf("\nchild creation is filed");
        exit(EXIT_FAILURE);
    }
    return 0;
}
