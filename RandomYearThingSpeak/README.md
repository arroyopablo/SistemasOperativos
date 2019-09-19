# generador de años aleatorios y ThingSpeak

Este repositorio busca presentar un escenario donde una máquina virtual que corre [Raspbian](https://www.raspbian.org/) toma datos de un generador de años y los envía a la nube.

* [Desarrollo de la práctica](#desarrollo-de-la-práctica)
  * [Preparación de scripts](#preparación-de-scripts)
    * [Simulando el sensor de temperatura](#simulando-el-sensor-de-temperatura)
      * [Un script que engloba lo anterior](#un-script-que-engloba-lo-anterior)
      * [Leer los datos de dev00](#leer-los-datos-de-dev00)
    * [Subir los datos a ThingSpeak](#subir-los-datos-a-thingspeak)
  * [Despliegue de sistema operativo Raspbian](#despliegue-de-sistema-operativo-raspbian)
  * [Programando la ejecucion del script de forma periódica](#programando-la-ejecucion-del-script-de-forma-periódica)

---

# Desarrollo de la práctica


## Preparación de scripts

Como se mencionó al comienzo de este documento se quiere tener acceso a un generador de años aleatorios y los datos de este generador subirlos a Internet.

### Generador de años aleatorios

Los datos del generador serán tomados de la plataforma [rapidapi](https://rapidapi.com/).
Para tomar los datos de esta plataforma se debe crear un script que toma los datos de la plataforma.
Este script se llamará `randomYear.sh` y tendrá el siguiente código:

```
#!/usr/bin/env bash
curl --request GET \
	--url 'https://numbersapi.p.rapidapi.com/6/21/date?fragment=true&json=true' \
	--header 'x-rapidapi-host: numbersapi.p.rapidapi.com' \
	--header 'x-rapidapi-key: cedf4035c9msh383b17601816b1cp19a99djsnede95eff7c8e'
```

#### Un script que engloba lo anterior

Para leer el generador se ejecutará el siguiente comando,

```
./readAPI.sh dev00
```

Los datos quedarán en el archivo `dev00`.

#### Leer los datos de dev00

Para leer los datos de `dev00` se usa el script `readYearJSON.py` como sigue:

* **year** `./readWeatherJSON.py dev00 main year`

### Subir los datos a ThingSpeak

Para subir los datos a ThingSpeak se hace uso del script `subirDatosTS.sh`.
El script por defecto buscará el archivo `dev00`. 
Sin embargo, el usuario puede especificar otro archivo invocando el comando de la siguiente manera:

```
./subirDatosTS.sh datos.json
```

En este caso se asume que los datos están en un archivo llamado `datos.json`.
Vale la pena aclarar que ese archivo debe tener una estructura como la que arroja el API del sitio OpenWeatherMap.

## Despliegue de sistema operativo Raspbian

Para llevar a cabo la práctica se debe crear una máquina virtual con el sistema operativo Raspbian. 
Raspbian es un sistema operativo basado en Debian Linux y que se diseñó para trabajar sobre ambientes SOC (*System On a Chip*).
[En esta página](https://www.osboxes.org/raspbian/) se puede hacer su descarga de una versión para sistemas x86 y que corren bajo ambientes virtuales como VirtualBox.

Una vez descargado el archivo se descomprime.
El archivo resultado de ese proceso de descompresión es un VDI que se le pegará a una máquina virtual.
El *hypervisor* en este caso es VirtualBox y las características de la máquina serán las siguientes:

* Name: Raspbian
* Type: Linux
* Version: Debian (32-bit)
* Memory size: 1024 MB
* Hard disk: "Use an existing virtual hard disk file". Buscar por el archivo VDI que se acabó de descomprimir.

Habilitar el PAE en esta máquina virtual.
Seleccionar **System**, **Processor** y seleccionar **"Enable PAE/NX"**.
Esta opción permite acceder a regiones de memoria más allá de los 4 GB en RAM.

Iniciar la máquina virtual.
Una vez la máquina termina de arrancar el login del usuario es **pi** y el password es **osboxes.org**<a name="osboxes"><sup>osboxes</sup></a>.

## Programando la ejecucion del script de forma periódica

Para ejecutar periódicamente el script se hará uso del servicio `cron` de Unix.
Ingrese via `ssh` a la máquina virtual desplegada en la [sección anterior](#despliegue-de-sistema-operativo-raspbian).

```
ssh -p 2222 pi@localhost
```

El usuario es `pi` y su password es `osboxes.org`.

Para crear las tareas que se quieren ejecutar de forma periódica se hace uso del comando `cron` como sigue:

```
crontab -e
```

Adicionar las siguiente líneas:

```

*/2 * * * *     /home/pi/RandomYearThingSpeak/readAPI.sh dev00 >> /home/pi/RandomYearThingSpeak/logfile
1-59/2 * * * *     /home/pi/RandomYearThingSpeak/subirDatosTS.sh >> /home/pi/RandomYearThingSpeak/logfile

```

Esto lo que indica es que cada dos minutos, 0, 2, 4, ..., 58; minutos se ejecuta el programa `readAPI.sh`.
De otro lado, `subirDatosTS.sh` se va a ejecutar también cada dos minutos pero al minuto, 1, 3, 5, ..., 59.

**NOTA** Si su usuario no es `pi` por favor hacer los ajustes en la entrada al cron para indicar la ruta `home` adecuada de su usuario.

---

<sup>[osboxes](#osboxes)</sup> https://www.ostechnix.com/osboxes-free-unixlinux-virtual-machines-for-vmware-and-virtualbox/
