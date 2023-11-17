%{
    #include <stdio.h>  // Incluye la libreria para el printf()
    #include <stdlib.h>
    #include <errno.h>  // Para errno
    #include <string.h>
    #include "parser.tab.h" // Incluyo el Header con la definición de los tokens que Bison genera automaticamente con el flag -d
%}

%option noyywrap

ID          [a-zA-Z][a-zA-Z0-9]{0,31}
NUMERO      [0-9]+

%%

"inicio"        { printf("<INICIO>\n"); return INICIO; }
"fin"           { printf("<FIN>\n"); return FIN; }
"leer"          { printf("<LEER> "); return LEER; }
"escribir"      { printf("<ESCRIBIR> "); return ESCRIBIR; }

{ID}            { printf("<ID: %s> ", yytext); return ID; }
{NUMERO}        {
                    errno = 0;
                    long valor = strtol(yytext, NULL, 10);
                    if (errno) {
                        perror("Error semantico");
                        exit(1);
                    } else {
                        printf("<NUMERO: %ld> ", valor);
                        return NUMERO;
                    }
                }

":="            { printf("<ASIGNACION> "); return ASIGNACION; }
";"             { printf("<PUNTOYCOMA>\n"); return PUNTOYCOMA; }
"("             { printf("<PARENTESISIZQ> "); return PARENTESISIZQ; }
")"             { printf("<PARENTESISDER> "); return PARENTESISDER; }
"+"             { printf("<SUMA> "); return SUMA; }
"-"             { printf("<RESTA> "); return RESTA; }
","             { printf("<COMA> "); return COMA; }

[ \t\n]         ; // Ignora espacios en blanco, tabulaciones y saltos de linea

.               { printf("Token no reconocido: %s\n", yytext); }

<<EOF>>         { yyterminate(); }

%%

/* El codigo comentado sirve para compilar con flex solamente porque sino hay 2 definiciones de main y no compila con bison
int main() {

    int i = 0;
    
    while(yylex()) // Sale del while cuando llega a EOF porque yyterminate() retorna 0
        i++;

    printf("Fin de archivo... Cantidad de Tokens: %d \n", i);
    
    return 0;
}
*/
