#include <stdio.h>
int length(char*);
int main(){
        char alfabeto[14] = {'0','1','2','3','4','5','6','7','8','9','+','-','*','/'};
        int eccAlf = 0;

        eccAlf = length(alfabeto);
        printf("longitud: %d ",eccAlf);
}

int length(char *str){
    int i = 1;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
