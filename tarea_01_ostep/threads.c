#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

//VARIABLES GLOBALES
pthread_mutex_t puerta; //Puerta definida
volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
    cerrar_puerta(puerta); //(Cierra la puerta) Cierra la entrada de otros procesos a las siguientes instrucciones.
    for (i = 0; i < loops; i++) {
	counter++;
    }
    abrir_puerta(puerta);//(Abre la puerta) Permite a otros procesos entrar a las instrucciones cerradas previamente. 
    return NULL;
}

int main(int argc, char *argv[]) {
    
    crear_puerta(puerta);
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    }
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    destruir_puerta(puerta);  //(Destruye la puerta) Elimina esta puerta que no seguira siendo utilizada para evitar residuos de memoria. 
    return 0;
}

