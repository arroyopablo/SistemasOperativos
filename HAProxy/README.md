# Documentacion del paso a paso de la practica de DOCKER.
## link de asciinema.
*[]()
# 1
	Se conecta a la maquina virtual previamente creada de DOCKER con Vagrant
	con el comando ´´vagrant ssh´´

# 2

se descarga la imagen httpd

* docker pull httpd

Para comprobar la instalación de estas imagenes escribir docker images
para listar las imagenes.

# 3
Para crear un alias en bash se necesito modificar el archivo .bashrc

Primero escribir el comando nano .bashrc para modificar el archivo
Una vez abierto con nano ir a la parte donde dice Alias definitions y colocar lo siguiente abajo del texto informativo

* alias numimages='docker images | sed '1d' | wc -l'

Una vez escrita la linea de arriba en el archivo .bashrc, desconectarse de la maquina virtual y volver a conectarse
ahora cuando se digite en la terminal numimages, arrojará el número de imagenes que han sido descargadas

# 4
Para llevar a cabo la siguiente actividad se necesita ejecutar el siguiente comando

* docker run -it ubuntu

Con este comando se ingresará al contenedor docker que ejecuta la imagen ubuntun en modo interactivo,
para poder interactuar con el shell

* Una vez dentro del contenedor para saber que archivos hay se ejecuta el comando ya conocido ls
* Para saber en que usuario se está se mira el prompt (root) o se ejecuta el comando whoami
* Al ejecutar el comando rm -rf /bin/* se eliminan todos los comandos que están ubicados en la carpeta bin, como por ejemplo ls o cat
* Al salir o ejecutar otra terminal y disparar el contenedor con ubuntu, vuelve a tener los archivos la carpeta bin
* Al ejecutar docker run -it ubuntu /bin/bash crea el contenedor, lo ejecuta y abre bash para ejecutar comandos
* Para crear un usuario se utiliza el comando sudo useradd nombre, en caso de que no reconozca sudo obviarlo.
* Instalar la aplicacion wget utilizando los comandos apt update luego apt install wget, comprobar ejecutano wget www.google.com


# 5
Para realizar esta actividad ejecutar los siguientes comandos y seguir los pasos

* Salir del contenedor docker con exit (En el caso de que se esté en la terminal del contenedor)
* nano .bashrc
* Buscar en el archivo la parte donde dice Alias definitions
* Agregar la siguiente linea abajo del texto de información
* alias identificadores='docker ps -q'
* Salir de la terminal de vagrant y volver a conectar por medio de ssh
* Colocar a correr un contenedor con docker run -it ubuntu
* Abrir otra terminal y escribir vagrant ssh
* Escribir identificadores en la terminal
* Mirar el resultado


# 6
Para borrar todos los contenedores que han terminado su ejecución hay que ejecutar el siguiente
comando ya previamente pensado y creado (Las lineas que contengan exited son los contenedores que han terminado su ejecución)

* docker rm $(docker ps -a -f status=exited -q)

# 7
Para realizar esta actividad primero se debe crear un contenedor ejecutando docker run -it ubuntu

Una vez esté en ejecución abrir otro terminal, acceder a la maquina virtual mediante vagrant ssh
Ya dentro de la maquina virtual ejecutar docker ps, copiar el identificador del contenedor que se está ejecutando
y escribir docker stop id, donde id es el identificador previamente copiado.

Se puede observar que la terminal donde estaba el shell del contenedor ha vuelto al shell de la maquina virtual.

# 8
Para realizar esta actividad con el id del contenedor que fue detenido mediante docker stop
ejecutar docker start id, donde id es el identificador del contenedor que fue detenido.

# 9
* Ejecutar el comando docker run -it ubuntu para lanzar un contenedor con ubuntu
* Ejecutar apt update y luego apt install htop
* Dentro del contenedor escribir exit para salir de el
* Copiar el identificador del contenedor anterior, donde se digitó exit
* Ejecutar docker start id, donde id es el identificador previamente copiado
* Ejecutar docker attach id, donde id es el identificador previamente copiado
* Ejecutar htop

# 10
Para realizar esta sección seguir los pasos

* Descargar la imagen ejecutando docker pull prakhar1989/static-site
* Comprobar la imagen descargada usando docker images
* Ejecutar un contenedor con la imagen digitando docker run --rm -d -P --name static-site prakhar1989/static-site
* Ejecutar docker port id, donde id es static-site
* Ejecutar wget localhost:32769 (O el puerto que haya aparecido en el paso anterior)
* Ejecutar cat index.html para ver el contenido del index.html que se está sirviendo en el contenedor
* Ejecutar docker stop static-site para detener la ejecución del servidor

# 11
* Dentro de la maquina virtual ejecutar docker pull r-base (Puede tardar varios segundos)
* Ejecutar docker run -ti --rm r-base
* Comprobar que se puede seguir realizando tareas

# 12
Dentro de la maquina virtual seguir los pasos:

* Ejecutar mkdir linux_tweet_app
* Ingresar al directorio
* Ejecutar nano Dockerfile

Copiar en el archivo Dokerfile lo siguiente

    FROM nginx:latest

    COPY index.html /usr/share/nginx/html

    EXPOSE 80 443

    CMD ["nginx", "-g", "daemon off;"]

* Ejecutar nano index.html

copiar y pegar lo siguiente

    <html>
      <body>
	    <h1> Saludos, Gustavo Aguirre, Sebastian Serna </h1>
      </body>
    </html>


* Para probar el contenedor ejecutar docker build -t miweb, lo cual creará la imagen
* Verificar la imagen ejecutando docker images
* Ejecutar docker run -p 443:80 miweb
* Abrir otra terminal y conectarse a la maquina virtual (vagrant ssh)
* Ejecutar wget localhost:443
* Ejecutar cat index.html
* Verificar que efectivamente eas es la página web creada
