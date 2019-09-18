# Documentacion del paso a paso de la practica de DOCKER.
## link de asciinema.
*[asciinema](https://asciinema.org/a/jamNx1oK8E04Ioms43mRKuMds)

# 1. Se conecta a la maquina virtual previamente creada de DOCKER con Vagrant
	con el comando ´´vagrant ssh´´

# 2. Se descarga la imagen httpd

* docker pull httpd

Para comprobar si estan las imagenes se escribe ´´docker images´´

# 3. Para crear un alias en bash se debe modificar el archivo .bashrc

el comando ´´nano ~ \.bashrc´´ 
Una vez se abre el bashrc se va a la seccion donde dice Alias definitions y se coloca ´´alias numimages='docker images | sed '1d' | wc -l' ´´ 

se reinicia él contedor de docker con el comando ´´exit´´´y se vuelve a concetar con el comando ´´vagrant ssh´´

# 4. Con este comando ´´docker run -it ubuntu´´ se ingresará al contenedor docker que ejecuta la imagen ubuntu en modo interactivo,
para poder interactuar con el shell

* Una vez dentro se ejecuta el comando ls para saber que archivos contiene
* para verificar que usuario somos se escribe el comando ´´whoami´´
*  el comando ´´rm -rf /bin/*´´  eliminan todos los comandos que están ubicados en la carpeta bin
* Al reiniciar el docker  o ejecutar otra terminal y disparar el contenedor con ubuntu, vuelve a tener los archivos la carpeta bin
* Al al escribir  ´´docker run -it ubuntu /bin/bash´´ abre el bash para ejecutar los comandos
* Con el comando ´´useradd nombre´´  se crea un usuario
* Para instalar la aplicacion wget se escribe los comandos ´´apt update´´ y se espera que descargue y despues ´´apt install wget´´´ 
para comprobar se ejecuta ´´wget www.google.com´´


# 5. Para continuar con la practica se sale del contenedor de docker  con ´´exit´´ 
* ´´nano ~ \.bashrc´´
* se repite la parte #3 donde se ingresa al bashrc y se modifica el alias
* ´´alias identificadores='docker ps -q'´´
* Salir de la terminal de vagrant y volver a conectar por medio de ssh
* se pone a correr el contenedor con ´´docker run -it ubuntu´´
* se abre  otra terminal y se escribe ´´identificadores´´


# 6. Para borrar todos los contenedores se ejecuta el siguiente comando ´´docker rm $(docker ps -a -f status=exited -q)´´

# 7. se crea un contenedor docker  ´´docker run -it ubuntu´´
se abre otra terminal y se accede a la maquina virtual ´´vagrant ssh´´ y una vez dentro de la maquina virtual se escribe el comando ´´docker ps´´ 
se copia el identificador del contenedor y despues se detiene el contedor ´´´docker stop  "identificadorcopiado"´´


# 8. para iniciar el contedor se escribe ´´docker start "identificadorcopiado"´´

