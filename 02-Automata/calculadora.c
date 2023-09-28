#include <stdio.h>
#include <stdbool.h> 
#include <string.h>


int tranformador(char*);
void removerEspacios(char*);
void reiniciarString(char*);
int length(char*);

int main(){
    char ejemplo[] = "+ 4 * 2 + 2 * 2";
    char valorNumericoString[20];
    char operador, operadoaux;
    int valorEntero = 0 , eccTotal = 0,eccAux = 0;
    int i = 1;
    int j = 0;
     
    removerEspacios(ejemplo);
    int longitudArray = length(ejemplo);
    printf("array: %s\n",ejemplo); 
    
    printf("array longitud: %d\n",longitudArray);

    // si empieza con +/- o con numero
    if (ejemplo[0] != '-' && ejemplo[0] != '+'){
        operador = '+';
        valorNumericoString[0] = ejemplo[0];
        j = 1;
        printf("se selecciono operador de base \n");
    }else{
        operador = ejemplo[0];
        printf("el operador inicial es: %d \n",operador);
    }

    while (i < longitudArray){        

        while(ejemplo[i] <= '9' && ejemplo[i] >= '0'){
            valorNumericoString[j++] = ejemplo[i++];
            printf("ultimo valor de i = %d \n",i);

        }



        valorEntero = tranformador(valorNumericoString);
        
        if(i < longitudArray){
            operadoaux = ejemplo[i++];  
            if(operadoaux == '*' || operadoaux == '/'){
                eccAux = valorEntero;
                reiniciarString(valorNumericoString);
                j = 0;
                while (operadoaux == '*' || operadoaux == '/'){

                    while(ejemplo[i] <= '9' && ejemplo[i] >= '0'){
                        valorNumericoString[j++] = ejemplo[i++];
                    }
                    valorEntero = tranformador(valorNumericoString);
                    if(operadoaux == '*'){
                        eccAux = eccAux * valorEntero;
                    }else{ 
                        eccAux = eccAux / valorEntero;
                    }
                        operadoaux = ejemplo[i++];
                }
            }else{   
                printf("entre a la suma/resta \n");
                eccAux = valorEntero;
            }  
        }else{
            printf("ultimo valor");
            eccAux = valorEntero;
        }
        
        if(operador == '+'){
            printf("suma: %d + %d\n",eccTotal,eccAux);
            eccTotal = eccTotal + eccAux;
        }else{
            eccTotal = eccTotal - eccAux;
        }
        
        operador = operadoaux;
        printf("ultimo valor de i = %d \n",i);
        j = 0;
        printf("%d\n",ejemplo[i]);
        
        reiniciarString(valorNumericoString);
    }
    
    printf("total: %d",eccTotal);
    return 0;

}

int tranformador(char* variable){
    int ecc = 0;
    int i = 0;

    while(variable[i] != '\0' && variable[i] != ' '){
        if(variable[i] <= '9' && variable[i] >= '0'){
            ecc = ecc*10 + variable[i] - '0';
            i++;
        }
    }

    return ecc;
}


void removerEspacios(char *str) {
    int length = strlen(str);
    int i, j = 0;

    for (i = 0; i < length; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    
    str[j] = '\0';  // Agrega un carácter nulo al final para terminar la cadena.
}

void reiniciarString(char *str){
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = ' ';
        i++;
    }
    return;
    removerEspacios(str);
    
}

int length(char *str){
    int i = 1;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}


/* continuar parte gramatica */
bool gramaticaValida(char** automata, char* alfabeto, int* estadosFinales, int accEstFin, int accAlf, char* palabra) {
    int estadoAnterior = 0;
    int estadoActual = 0;
    int i = 0;

    while (palabra[i] != '\0') {
        estadoAnterior = estadoActual;
        estadoActual = automata[estadoActual][posicion_actual(palabra[i], alfabeto)];
        i++;
    }

    return es_final(estadoAnterior, estadosFinales, accEstFin);
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

    return 5;
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