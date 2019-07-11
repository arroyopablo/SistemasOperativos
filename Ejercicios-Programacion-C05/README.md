# CAPITULO 5

#### Integrantes del grupo : Pablo Andres Arroyo[1525805],Gustavo Adolfo Aguirre[1523452],Sebastian Serna[1832018]

## Pregunta 1
* [pregunta1.c](pregunta1.c)
### Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

**fork()** crea una copia del proceso padre.Sin embargo, el proceso padre e hijo tienen su propio espacio de direccion. Ambos procesos (hijo y padre) no pueden inteferir en el espacio de direcciones del otro (memoria). Ademas, cada uno mantiene su propia copia de variables.

## Pregunta 2
* [pregunta2.c](pregunta2.c)
### Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?

Tanto el hijo como el padre pueden acceder al descriptor de archivo abierto utilizando **open()**. Ambos pueden escribir en el archivo, pero el orden en el que lo hacen no es determinista (*si no usamos* **wait()**). ** Observacion: ** Es posible que solo uno haya podido escribir sobrescribiendo el otro.

## Pregunta 3
* [pregunta3.c](pregunta3.c)
### Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?

es posible usando **usleep()** aunque estoy generaria retrasos ya que no tenemos el tiempo preciso en el que terminara la ejecuccion del hijo, para hacer uso de este creamos un archivo en el que se escribe true cuando el hijo termina de ser ejcutado, mientras no sea true el padre hace un usleep()de 10 milisegundos y asi hasta que el hijo termine y el archivo contenga un true (puede ser cualquier otra palabra)

## Pregunta 4
* [pregunta4.c](pregunta4.c)
### Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including execl(), execle(), execlp(), execv(), execvp(), and execvP(). Why do you think there are so many variants of the same basic call?

*execl* y *execv* son muy identicos, es minima la diferencia.
*execlp* y *execvp* son muy identicos.
*execle* y *execvpe* son cercanamente identicos.

la diferencia entre ellos es:

*-* las funciones que tiene una *l* en su nombre, requieren argumentos separados por comas. 
*-* las funciones que tiene una *v* en su nombre, requieren argumentos como vector de array.
*-* las funciones cuyo nombre termina en *e* necesitan un agumento de ambiente 

## Pregunta 5
* [pregunta5.c](pregunta5.c)
### Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?

**wait ()** en caso de éxito, devuelve el ID de proceso del hijo terminado; en caso de error, se devuelve -1.

Si usamos *wait()* en el proceso hijo retorna -1. Porque no hay un hijo de hijo, por lo tanto no espera nigun proceso (hijo) para salir.

## Pregunta 6
* [pregunta6.c](pregunta6.c)
### Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?

**waitpid ()** se usa cuando queremos esperar o un proceso secundario (hijo) específico en lugar de ayudar a que salgan todos los procesos secundarios. También nos permite especificar más comportamientos.

## Pregunta 7
* [pregunta7.c](pregunta7.c)
### Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?

Al cerrar **stdout** no podemos imprimir en pantalla usando **printf()**. Pero no ocurre ningun error si lo intentamos.
