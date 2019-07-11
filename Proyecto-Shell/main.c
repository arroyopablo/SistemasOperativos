/*
 *Gustavo Adolfo Aguirre -1523452
 *Pablo Andres Arroyo - 1525805
 *Sebastian Serna S - 1832018 
 */

#include "funciones.h"
#include <stdio.h>


int main(int argc, char **argv)
{
	char entradaString[cantidad_de_caracteres], *argumentosAnalizados[cantidad_de_comandos]; 
	
	clear();
	
	printf("shell=%s\n",getenv("PWD"));
	
	if(argc>1){
		FILE *fichero;
		fichero = fopen(argv[1],"r");
		if(!fichero){
			printf("\nEl fichero %s no existe o no puede ser abierto.\n", argv[1]);
			return 0;
		}
		while(!feof(fichero)){
			
		    fgets(entradaString,cantidad_de_caracteres,(FILE*) fichero);
			procesarString(entradaString, 
			argumentosAnalizados); 
		}
		printf("\n");
		fclose(fichero);
		return 0;
	}
	else{
		while (1) { 
			 
			// leer entrada desde teclado
			if(leerEntrada(entradaString))
			continue;
			// procesar
			procesarString(entradaString, 
			argumentosAnalizados); 
	  
		} 
		return 0; 
	}
}

