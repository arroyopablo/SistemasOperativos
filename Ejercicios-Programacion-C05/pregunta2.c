#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct stat sb;
    int mi_archivo = open("archivo_prueba.txt", O_CREAT | O_RDWR, S_IRWXU);
    
    int rc = fork();

    if (rc == 0)
    {
        const char * mensaje_hijo = "Este es un mensaje escrito por el proceso hijo\n";
        printf("************ El proceso hijo ha escrito en el archivo ************\n");
        write(mi_archivo, mensaje_hijo , strlen(mensaje_hijo));
        exit(0);
    }
    else if (rc > 0)
    {
        wait(NULL);
        const char * mensaje_padre = "Yo soy el padre y estoy escribiendo en el archivo\n";
        printf("************ El proceso padre ha escrito en el archivo ************\n");
        write(mi_archivo, mensaje_padre, strlen(mensaje_padre));
    }
    sync();
    fstat(mi_archivo, &sb);
    lseek(mi_archivo, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(mi_archivo, buffer, sb.st_size);

    printf("El contenido del archvio es: \n%s", buffer);
    close(mi_archivo);
    return 0;
}
