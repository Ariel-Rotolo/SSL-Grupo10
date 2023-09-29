#include <stdio.h>
#include <stdbool.h> 
#include <string.h>


int tranformador(char*);
void removerEspacios(char*);
void reiniciarString(char*);
int length(char*);

bool gramaticaValida(char[][15],char*,int*,int,int,char*);
int posicion_actual(char,char*,int,int);
bool es_final(int,int*,int);

int main(){
    char entrada[] = "2+2+2 / 2 * 2 + 2";
    char valorNumericoString[20];
    char operador, operadoaux;
    int valorEntero = 0 , eccTotal = 0,eccAux = 0;
    int i = 1;
    int j = 0;
     
    char automata[][15] =  {{7,2,2,2,2,2,2,2,2,2,1,1,7,7,7},
                            {7,2,2,2,2,2,2,2,2,2,7,7,7,7,7},
                            {2,2,2,2,2,2,2,2,2,2,1,1,3,4,7},
                            {7,2,2,2,2,2,2,2,2,2,7,7,7,7,7},
                            {7,5,5,5,5,5,5,5,5,5,7,7,7,7,7},
                            {7,5,5,5,5,5,5,5,5,5,1,1,6,4,7},
                            {7,5,5,5,5,5,5,5,5,5,7,7,7,7,7},
                            {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}};

    int estadosFinales[] = {2,5};
    int accEstFin = 2;
    char alfabeto[14] = {'0','1','2','3','4','5','6','7','8','9','+','-','*','/'};
    int accAlf = 14;
    int inicio = 0;
    removerEspacios(entrada);
  

    if(!gramaticaValida(automata,alfabeto,estadosFinales,accEstFin,accAlf,entrada)){
        printf("Su cuenta tiene algun error por lo tanto no es valida");
        return 0;
    }

    
    int longitudArray = length(entrada);
    // si empieza con +/- o con numero
    if (entrada[0] != '-' && entrada[0] != '+'){
        operador = '+';
        valorNumericoString[0] = entrada[0];
        j = 1;
    }else{
        operador = entrada[0];
    }

    while (i < longitudArray){        

        while(entrada[i] <= '9' && entrada[i] >= '0'){
            valorNumericoString[j++] = entrada[i++];
        }

        valorEntero = tranformador(valorNumericoString);
        
        if(i < longitudArray){
            operadoaux = entrada[i++];
            if(operadoaux == '*' || operadoaux == '/'){
                eccAux = valorEntero;
                while (operadoaux == '*' || operadoaux == '/'){
                    reiniciarString(valorNumericoString);
                    j = 0;
                    while(entrada[i] <= '9' && entrada[i] >= '0'){
                        valorNumericoString[j++] = entrada[i++];    
                    }
                    valorEntero = tranformador(valorNumericoString);


                    if(operadoaux == '*'){
                        eccAux = eccAux * valorEntero;
                    }else{ 
                        eccAux = eccAux / valorEntero;
                    }
                        operadoaux = entrada[i++];
                        reiniciarString(valorNumericoString);
                }
            }else{   
                eccAux = valorEntero;
            } 
        }else{
            eccAux = valorEntero;
        }
        
        if(operador == '+'){
            eccTotal = eccTotal + eccAux;
        }else{
            eccTotal = eccTotal - eccAux;
        }
        eccAux = 0;
        operador = operadoaux;
        j = 0;
        
        reiniciarString(valorNumericoString);
    }
    printf("valor de i: %d\n",i);
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
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}


/* continuar parte gramatica */
bool gramaticaValida(char automata[][15], char* alfabeto, int* estadosFinales, int accEstFin, int accAlf, char* palabra) {
    int estadoAnterior = 0;
    int estadoActual = 0;
    int i = 0;

    while (palabra[i] != '\0') {
        estadoAnterior = estadoActual;
        estadoActual = automata[estadoActual][posicion_actual(palabra[i], alfabeto,7,14)];
        i++;
    }
    return es_final(estadoActual, estadosFinales, accEstFin);
}


int posicion_actual(char elemento,char* alfabeto,int estadoDeRechazo,int accAlf) {
    int i;
    for (i = 0; i < accAlf; i++) {
        if (alfabeto[i] == elemento) {
            return i;
        }
    }
    return accAlf;
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