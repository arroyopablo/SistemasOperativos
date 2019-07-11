/*
 * main.c
 * 
 * Copyright 2019 Invitado <invitado@s1pc36>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
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

