# Ejercicio 1
## Consigna
Dada una cadena que contenga varios números que pueden ser decimales, octales o <br>
hexadecimales, con o sin signo para el caso de los decimales, separados por el carácter <br>
‘$’ , reconocer los tres grupos de constantes enteras, indicando si hubo un error léxico , <br>
en caso de ser correcto contar la cantidad de cada grupo. <br>
Debe diagramar y entregar el o los autómatas utilizados y las matrices de transición. <br>
La cadena debe ingresar por línea de comando o por archivo <br>

## Evidencias de prueba
Para la evidencia de prueba decidimos usar como prueba el archivo automata.txt en el cual se encuentra una string con todo los tipos de variables posibles para utilizar.
La prueba salio satisfactoria mostrando el siguiente mensaje por pantalla:
<img src="./Capturas EV/ev punto 1.png"/>

## Documentacion del codigo
Para el código utilizamos tres librerías:
```c
#include <stdio.h> // biblioteca estándar de input/output
#include <stdbool.h> // biblioteca para ejecutar funciones con return bool
#include <string.h> // biblioteca para la utilización de la función length
```
y utilizamos 2 funciones propias
```c
int posicion_actual(char,char*); // Función que retorna según el carácter y el autómata la posición actual
bool es_final(int,int*,int); // Funcion para saber si la posición actual es o no final
```

## Automata utilizado
<img src="./Capturas EV/AutomataUtiliizadoPunto1.drawio.png"/>

# Ejercicio 2
## Consigna
Debe realizar una función que reciba un carácter numérico y retorne un número entero.

## Evidencias de prueva
<img src="./Capturas EV/Ev punto 2.png"/>

## Documentacion del codigo
```c
#include <stdio.h> // biblioteca base para ejecutar el codigo
```
y utilizamos 1 funciones propia

```c
int tranformador(char* variable); // funcion que tranforma el string en un entero
```

# Ejercicio 3
## Consigna

Ingresar una cadena que represente una operación simple con enteros decimales y <br>
obtener su resultado, se debe operar con +,- ,/, *. Ejemplo = 3+4*8/2+3-5 = 29. Debe <br>
poder operar con cualquier número de operandos y operadores respetando la precedencia <br>
de los operadores aritméticos y sin paréntesis. <br>
La cadena ingresada debe ser validada previamente preferentemente reutilizando las <br>
funciones del ejercicio 1. <br>
Para poder realizar la operación los caracteres deben convertirse a números utilizando la <br>
función 2. <br>
La cadena debe ingresar por línea de comando o por archivo. <br>

## Evidencias de prueva
<img src="./Capturas EV/Evidencia de prueba punto 3.png" />

## Documentacion del codigo

Para el codigo utilizamos tres librerias: 
```c
#include <stdio.h> // biblioteca base para ejecutar el codigo
#include <stdbool.h> // biblioteca para ejecutar funciones con return bool
#include <string.h> // biblioteca para la utilizacion de la funcion length
```
y Utilizamos 7 funciones propias

```c
int tranformador(char*); // tranforma una strign en un int
void removerEspacios(char*); // elimina los espacion en el estrign
void reiniciarString(char*); // borra todos los datos de un string
int length(char*); // calcula la longitud de un string

bool gramaticaValida(char[][15],char*,int*,int,int,char*);// evalua si una gramatica pertenece a un automata
int posicion_actual(char,char*,int,int); // Funcion que retorna segun el caracter y el automata la pocicion actual
bool es_final(int,int*,int); // Funcion para saber si la pocicion actual es o no final 
```
