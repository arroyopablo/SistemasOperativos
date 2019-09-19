#!/usr/bin/env python
#
# Este script fue disenado para leer los datos arrojados por el API de 
# NUMBERS y que han sido almacenados en un archivo JSON.
#
# Los datos por los cuales se espera el usuario pregunte es:
#  - year
#
# Author: Pablo Andres Arroyo - 1525805
#         Gustavo Adolfo Aguirre - 1523452
#         Sebastian Serna - 1832018
# Date: 2019-09-17
#
import json 
import sys
import os

if not len(sys.argv) == 3:
    print("Uso %s <json_file> <campo1>"%sys.argv[0])
    print("el campo 1 debe ser igual a un numero")
    sys.exit(-1)

homedir = os.environ['HOME']
os.chdir("%s/RandomYearThingSpeak"%homedir)
filename = sys.argv[1]
campo1 = sys.argv[2]
with open(filename) as json_file:
    data = json.load(json_file)
    print(data[campo1])
