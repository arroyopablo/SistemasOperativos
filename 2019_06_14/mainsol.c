#include "solucion.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  pid_t pid;
  int x = 20;

  pid = fork();
  if(pid == 0){
    printf("fibonacci(%d) * 100 = ",x);
    x = fibonacci(x);
    guardarEntero("archivo",x);
  }else{
    pid= wait(NULL);
    x = leerEntero("archivo") * 100;
    printf("%d\n",x);
  }

  return 0;
}
