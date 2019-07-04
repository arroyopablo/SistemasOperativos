#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child
    {
        printf("************* Ejecutando proceso hijo **************\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        // ***************** Descomentar solo una ************************ /

        //execl("/bin/ls", "ls", NULL);
        //execlp("ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, envp);
        
        //execv("/bin/ls", argv);
        //execvp("ls", argv);
        execvpe("ls", argv, envp);
    }
    else if (rc > 0) // padre
    {
        wait(NULL);
    }
    else
    {
        fprintf(stderr, "Error ocurrido durante el fork()");
    }
}
