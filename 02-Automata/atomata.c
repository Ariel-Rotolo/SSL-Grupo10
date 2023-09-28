#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int pocicion_actual(char,char*);
bool es_final(int,int*,int);


int main() {
    int eccDec = 0 ,eccHex = 0 ,eccOct = 0,eccError = 0;
    char variable ; 
    int estadoAnterior = 0,estadoActual = 0;
    
    size_t automata[][27] = {
    {1, 1, 5, 5, 5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 0, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 0, 4, 4, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 0, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    {5, 5, 0, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
    };
    int estadosFinales[] = {1, 2, 3, 4};
    int accEstFin = 4;
    char alfabeto[27] = {'-', '+', '$', 'X', 'x', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
    int accAlf = 27;
    int inicio = 0;
    
    
    
    
    FILE *archivo;
    archivo = fopen("automata.txt","r");
    variable = fgetc(archivo);
    

    while (variable != EOF) {
        do{
            estadoAnterior = estadoActual;
            estadoActual = automata[estadoActual][pocicion_actual(variable,alfabeto)];
            variable = fgetc(archivo);
            
        }while(variable != EOF && estadoActual != 0);

        if (es_final(estadoAnterior,estadosFinales,accEstFin)) {
            switch (estadoAnterior)
            {
            case 1:
                eccDec++;
                break;
            case 2:
                eccDec++;
                break;
            case 3:
                eccOct++;
                break;
            case 4:
                eccHex++;
                break;
            }
        }else{
            eccError++;
        }

    }
    printf("Decimales : %d \nOctales: %d \nHexadecimales: %d \nErrores lexicos: %d",eccDec,eccOct,eccHex,eccError);

    return 0;
}

int pocicion_actual(char elemento,char* alfabeto) {
    int i;
    int accAlf;
    accAlf = strlen(alfabeto);
    for (i = 0; i < accAlf; i++) {
        if (alfabeto[i] == elemento) {
            return i;
        }
    }

    return accAlf - 1;
}

bool es_final(int estado, int* estadosFinales, int accEstFin) {
    int i;

    for (i = 0; i < accEstFin; i++) {
        if (estadosFinales[i] == estado) {
            return true;
        }
    }

    return false;
}