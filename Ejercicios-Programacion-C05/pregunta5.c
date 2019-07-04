#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // proceso hijo
    {
        int wc = wait(NULL);
        printf("Soy el proceso hijo\n");
        printf("El codigo de retorno de wait() es %d\n", wc);
    }
    else if (rc > 0) // proceso padre
    {
        printf("Soy el proceso padre\n");
    }
    else
    {
        fprintf(stderr, "Error ocurrido durante el fork()");
    }
}
