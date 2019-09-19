#!/usr/bin/env bash
#
# Este script sube dato relativo a un año aleatorio
# a un canal de ThingSpeak.
#
# Author: Pablo Andres Arroyo - 1525805
#         Gustavo Adolfo Aguirre - 1523452
#         Sebastian Serna - 1832018
# Date: 2019-09-17
#
apiKey="QLDYEJ3D03ZMTH34"
device="dev00"

yearTS_HOME="${HOME}/RandomYearThingSpeak"
PATH=${yearTS_HOME}:${PATH}
if [ $# -eq 1 ]; then
  device=${1}
fi

if [ ! -f ${yearTS_HOME}/${device} ]; then
  echo "[subirDatosTS] ${yearTS_HOME}/${device} no existe"
  exit -1
fi
year=$( readYearJSON.py ${yearTS_HOME}/${device}  year )

update=$(curl --silent --request POST --header "X-THINGSPEAKAPIKEY: $apiKey" --data "field1=$year" "http://api.thingspeak.com/update")

if [ ${update} -eq 0 ]; then
  echo "[subirDatosTS] Error al subir datos"
  exit -1
else
  exit 0
fi
