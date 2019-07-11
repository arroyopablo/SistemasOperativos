#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h> 


int cantidad_de_caracteres = 150;
int cantidad_de_comandos = 100;

char* pwd;
char cwd[1024];


#define clear() printf("\033[H\033[J");
 
// Leer la entrada   
int leerEntrada(char* str) 
{ 
	
    char* buf ; 
    buf = readline("\nIntroduzca su comando>>$ ");
	
    if (strlen(buf) != 0) {
		add_history(buf);
        strcpy(str, buf); 
        return 0; 
    } else { 
        return 1; 
    } 
  

 } 
   
    
//Funcion donde el comando del sistema es ejecutado    
void ejecutarComando(char** comandoAnalizar) //comandoAnalizar es el comando que va a ser analizado por la función  
{ 
	int pidPadre = (int) getpid();
	//imprimimos el pid del padre
	printf("(pid:%d)=%s\n", pidPadre ,getenv("PWD"));
	
    // Ejecutamos el hijo 
    pid_t pid = fork();  
    if (pid < 0) { 
        printf("\nFallo en el fork..."); 
        return; 
    } else if (pid == 0) { 
		
        if (execvp(comandoAnalizar[0], comandoAnalizar) < 0) { 
            printf("\nNo se pudo ejecutar el comando..."); 
        } 
        exit(0); 
    } else { 
        // esperando a que el hijo termine 
        
        wait(NULL);  
        return; 
    } 
} 
    


//Muestra en pantalla los comandos disponibles en el shell
void openHelp() 
{ 
    puts("\n***Menu de ayuda***"
        "\nLista de comandos disponibles:"
        "\n>cd"
        "\n>clr"
        "\n>dir"
        "\n>environ"
        "\n>echo"
        "\n>help"
        "\n>pause"
        "\n>quit"
        "\n>all other general commands available in UNIX shell"
        "\n>improper space handling"); 
  
    return; 
} 

void funcion_cd(char* dirDestino){
	int flagError;
	pwd = (char*) malloc(sizeof(char)*100);
	
    if(dirDestino){
		flagError = chdir(dirDestino);
		getcwd(pwd,100);
	} 		 
   else{
	   flagError = chdir(getenv("PWD"));
	   getcwd(pwd,100);
	   printf("%s\n",pwd); 
    } 
   
   if(flagError){
	 printf("Dirección errónea, inexistente o faltan permisos de acceso");   
   }
   else{
	      setenv("PWD",pwd,1);
	      getcwd(cwd,100);
	     	
   }
   free(pwd);	
 }

void detener(){
	printf("\nPresione Enter para continuar... ");
	while(1){
		char ch = getchar();
		if(ch == '\n')  {     // '\n' es un enter expresado en caracter. 
			break ; 
			}
	}
	return;	
}
  
// Funccion que ejecuta los comandos creados 
int controladorDeTerminal(char** comandoAnalizar) 
{ 
    int comandosTotales = 9;
	int posicion = 0; 
    char* listaDeComandos[comandosTotales]; 
    
    listaDeComandos[0] = "cd"; 
    listaDeComandos[1] = "clr"; 
    listaDeComandos[2] = "dir";
    listaDeComandos[3] = "environ";
    listaDeComandos[4] = "echo";
    listaDeComandos[5] = "help";
    listaDeComandos[6] = "pause";
    listaDeComandos[7] = "quit";
    listaDeComandos[8] = "pwd";
    
    
    for (int i = 0; i < comandosTotales; i++) { 
        if (strcmp(comandoAnalizar[0],listaDeComandos[i]) == 0) { 
            posicion = i + 1; 
            break; 
        }
    } 
	
    switch (posicion) { 
    case 1:  
		funcion_cd(comandoAnalizar[1]);
		
		return 1; 
    case 2: 
		clear();
       
        return 1; 
    case 3: 
    //dir
		ejecutarComando(comandoAnalizar);
		
        return 1; 
    case 4:
		comandoAnalizar[0]="env";
        ejecutarComando(comandoAnalizar);
        
        return 1; 
    case 5: 
    //echo
		ejecutarComando(comandoAnalizar);

        return 1; 
	case 6: 
        openHelp(); 
        
        return 1; 
    case 7: 
		detener();
		
        return 1;
    case 8: 
        exit(0); 
        
        return 1;
    case 9:
		ejecutarComando(comandoAnalizar);
		
		return 1;
    default: 
		printf("Comando no conocido");
        break; 
    } 
  
    return 0; 
} 

//Analiza gramaticalmente un comando
void analisisEspacio(char* str, char** comandoAnalizar) 
{ 
    int i; 
  
    for (i = 0; i < cantidad_de_comandos; i++) { 
        comandoAnalizar[i] = strsep(&str," \t\n"); 
  
        if (comandoAnalizar[i] == NULL) 
            break; 
        if (strlen(comandoAnalizar[i]) == 0) 
            i--; 
    } 
} 


//
void procesarString(char* str, char** comandoAnalizar) 
{  
    
    analisisEspacio(str, comandoAnalizar);  
  
    if (controladorDeTerminal(comandoAnalizar)) 
     return; 
} 






   

