#include <stdio.h>

#include <stdlib.h>

#include <string.h>



void copia_invertida(char *nombrearchivoleer, char *nombrearchivoescribir);



int main(int argc, char* argv[]){

	copia_invertida("entrada.txt","salida.txt");

	return 0;

}





//Función que copia el contenido de un archivo en otro invirtiendo cada línea

void copia_invertida(char *nombrearchivoleer, char *nombrearchivoescribir){

	FILE *parchivolectura, *parchivoescritura;

	//char linealeida[NUMCARACTERES], lineainvertida[NUMCARACTERES];

	int fin=0;

 

	//Abrimos los archivos

	parchivolectura = fopen(nombrearchivoleer,"r");

	parchivoescritura = fopen(nombrearchivoescribir,"w");

	

	int i=0;   // movera el puntero a los caracteres del archivo

	

	

	//Comprobamos si la apertura ha sido correcta

	if ((parchivolectura == NULL)||(parchivoescritura == NULL)){

		printf("Error al abrir ficheros");

	}else {

	//Recorremos el archivo de lectura mientras no se acabe

		do {

		

		fseek(parchivolectura, -2 - i, SEEK_END);

	    char f = getc(parchivolectura);

	    char a = ftell(parchivolectura);

		i++;

	    if(a==1){

			// Este es el ultimo caracter que se va a leer

			fprintf(parchivoescritura, "%c", f);
			
			fin=1;

		}else

		    fprintf(parchivoescritura, "%c", f);

		}while (fin!=1);

		

		//Cuando llegamos al final del archivo de lectura, cerramos los archivos

		fclose(parchivolectura);

		fclose(parchivoescritura);

	}

 return;



}
