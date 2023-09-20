#include <stdio.h>
#include <stdbool.h>
int tranformador(char* variable);

int main() {
    char valor[6] = "2234" ;
    int resultado;
    printf("Ingrese un valor numerico: ");
    scanf("%s", valor); 

    resultado = tranformador(valor);
    
    printf("Resultado de su tranformacion: %d",resultado);

    return 0;

}

int tranformador(char* variable){
    int ecc = 0;
    int i = 0;

    while(variable[i] != '\0'){
        if(variable[i] <= '9' && variable[i] >= '0'){
            ecc = ecc*10 + variable[i] - '0';
            i++;
        }
    }

    return ecc;
}