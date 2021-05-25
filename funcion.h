#include "struct.h"

//char lexico_crteres(char *cuenta);
//char lexico_operac (token *buffer);
char lexico(char *cuenta);
char getfrom_matriz(token *pila, token *buffer);

lista_int *sintactico(token *pila, token *buffer);

token *init_buffer(char *cuenta);
token *add_tken(token *tkens, token *nuevo);
token *podar(token *pila);
token *traslado(token *pila, token *buffer, char c);
token *podar(token *pila);

lista_int *resolver(lista_int *lista, char oper);
lista_int *add_numero(lista_int *lista, int nro);

void mostrar(char *str, token *tkens);
