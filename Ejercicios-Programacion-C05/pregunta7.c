#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // hijo
    {
        close(STDOUT_FILENO);
        printf("Se puede imprimir esto?\n");
    }
    else if (rc > 0) // padre
    {
        wait(NULL);
        printf("Soy el proceso padre\n");
    }
    else 
    {
        printf("Error ocurrido durante el fork()\n");
    }
}
