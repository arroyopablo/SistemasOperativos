#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int archivo_fondo = open("archivo_fondo.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    int rc = fork();

    if (rc == 0) // child process
    {
        write(archivo_fondo, "true", 4);
        printf("Soy el proceso hijo\n");
        printf("hello\n");
        close(archivo_fondo);
    }
    else if (rc > 0)
    {
        char buffer[4];
        buffer[4] = '\0';
        while (strcmp(buffer, "true\0") != 0)
        {
            // se cierra y se abre el archivo para actualizar el contenido
            close(archivo_fondo);
            backend_file = open("archivo_fondo.txt", O_CREAT | O_RDWR, S_IRWXU);
            read(archivo_fondo, buffer, 4);
            usleep(10 * 1000); // dormir por 10 milli-seconds
        }

        printf("Soy el proceso padre\n");
        printf("goodbye\n");
    }
    close(archivo_fondo);
    return 0;
}
