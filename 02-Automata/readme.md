# Ejercicio 1
## Consigna
Dada una cadena que contenga varios números que pueden ser decimales, octales o <br>
hexadecimales, con o sin signo para el caso de los decimales, separados por el carácter <br>
‘$’ , reconocer los tres grupos de constantes enteras, indicando si hubo un error léxico , <br>
en caso de ser correcto contar la cantidad de cada grupo. <br>
Debe diagramar y entregar el o los autómatas utilizados y las matrices de transición. <br>
La cadena debe ingresar por línea de comando o por archivo <br>

## Evidencias de prueva
Para la evidencia de prueba decidimos usar como prueba el archivo automata.txt en el cual se ecuentra una strign con todo los tipos de variables posibles para utilizar.<br>
La prueba salio satifactoria mostrando el siguiente mensaje por pantalla:
<img src="./Capturas EV/ev punto 1.png"/>

## Documentacion del codigo
Para el codigo utilizamos tres librerias: 
```c
#include <stdio.h> // biblioteca base para ejecutar el codigo
#include <stdbool.h> // biblioteca para ejecutar funciones con return bool
#include <string.h> // biblioteca para la utilizacion de la funcion length
```
y utilizamos 2 funciones propias
```c
int pocicion_actual(char,char*); // Funcion que retorna segun el caracter y el automata la pocicion actual
bool es_final(int,int*,int); // Funcion para saber si la pocicion actual es o no final 
```

## Automata utilizado
<img src="./Capturas EV/AutomataUtiliizadoPunto1.drawio.png"/>

# Ejercicio 2
## Consigna
Debe realizar una función que reciba un carácter numérico y retorne un número entero.

## Evidencias de prueva
<img src="./Capturas EV/"/>

## Documentacion del codigo
```c
#include <stdio.h> // biblioteca base para ejecutar el codigo
```
y utilizamos 1 funciones propia

```c
int tranformador(char* variable); // funcion que tranforma el string en un entero
```