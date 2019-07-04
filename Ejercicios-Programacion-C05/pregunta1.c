#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int x;

    x = 100;

    int rc = fork();

    if (rc == 0) // proceso hijo
    {
        printf("-----------------------------------------------\n");
        printf("-               Proceso Hijo                  -\n");
        printf("-----------------------------------------------\n");
        printf("El valor de X en el proceso hijo es: %d\n", x);
        x = 200;
        printf("El nuevo valor de x en el proceso hijo es: %d\n\n", x);
        
    }
    else if (rc > 0) // Proceso padre
    {
        wait(NULL);
        printf("-----------------------------------------------\n");
        printf("-               Proceso Padre                 -\n");
        printf("-----------------------------------------------\n");
        printf("El valor de X en el proceso padre es: %d\n", x);
        x = 300;
        printf("El nuevo valor de x en el proceso padre es: %d\n", x);
    }
    else // error
    {
        fprintf(stderr, "Error, no se pudo crear el proceso");
    }
}
