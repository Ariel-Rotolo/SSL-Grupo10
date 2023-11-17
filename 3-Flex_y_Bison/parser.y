%{
   #include <stdio.h>
   int yylex(); // Defino el prototipo de yylex para que Bison pueda llamar correctamente a Flex
   int yyerror(char const *); // Defino yyerror que llama Bison automaticamente en caso de error
%}

%token ID NUMERO LEER ESCRIBIR INICIO FIN ASIGNACION PUNTOYCOMA PARENTESISIZQ PARENTESISDER SUMA RESTA COMA

%%

programa: INICIO lista_sentencias FIN;

lista_sentencias: /* permite cero sentencias */ | lista_sentencias sentencia PUNTOYCOMA;

sentencia: asignacion | lectura | escritura;

asignacion: ID ASIGNACION expresion | error_asignacion;

lectura: LEER PARENTESISIZQ lista_ids PARENTESISDER | error_lectura;

escritura: ESCRIBIR PARENTESISIZQ lista_expresiones PARENTESISDER | error_escritura;

lista_ids: ID | lista_ids COMA ID;

lista_expresiones: expresion | lista_expresiones COMA expresion;

expresion: operando | expresion SUMA operando | expresion RESTA operando;

operando: ID | NUMERO | PARENTESISIZQ expresion PARENTESISDER;

error_asignacion: ID ASIGNACION error { yyerror("Error en la asignacion"); };

error_lectura: LEER PARENTESISIZQ error PARENTESISDER { yyerror("Error de lectura"); };

error_escritura: ESCRIBIR PARENTESISIZQ error PARENTESISDER { yyerror("Error de escritura"); };

%%

int main() {
   if(yyparse() == 0) // Devuelve 0 exitosamente de lo contrario devuelve 1
      printf("Análisis sintáctico exitoso!\n");
   return 0;
}

int yyerror(const char* mensaje) {
   fprintf(stderr, "Error Sintáctico: %s\n", mensaje);
   return 1;
}
