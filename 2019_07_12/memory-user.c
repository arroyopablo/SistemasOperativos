#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
  //validar que se pasa un arguemento
  if(argc < 2){
	printf("No se ha pasado ningun argumento\n");
	return 1;
  }
  //convertir ese arguemento a un numero entero. Este número representa la
  //cantidad en megabits
  int bytes = atoi(argv[1]);
  printf("el valor es megabits es %d:", bytes); 

  //Solicitar esa cantidad en megabits al heap del "adress space" y
  //asignarlo a un arreglo
  int *array = malloc(bytes*1024*1024*(sizeof(int)));
  if (array == NULL){
  printf("Memoria no asignada");
  exit(-1);
  }

  //iterar sobre el arreglo
  int i = 0;
  for(;i < bytes*1024*1024; i++)
  array[i] = i;
  
  //salir
  sleep(10);
  
  return 0;
}
