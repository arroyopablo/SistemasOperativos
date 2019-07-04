#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    
    if (rc == 0) // hijo
    {
        printf("Soy el proceso hijo y Mi PID es %d\n", getpid());
        exit(0);
    }
    else if (rc > 0) // padre
    {
        int estado;
        waitpid(rc, &estado, 0);
        printf("Soy el padre y Mi PID  es %d\n", getpid());        
    }
    else
    {
        fprintf(stderr, "Error ocurrido durante el fork()");
    }
}
