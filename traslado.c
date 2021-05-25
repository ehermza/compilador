#include <stdlib.h>
#include "struct.h"

token *traslado(token *pila, token *buff, char carac) 
{
	int tipo;
	token *nuevo;

	if (carac=='=') tipo= TK_OPER;
	if (carac=='<') tipo= TK_SIGN;

	// Ingreso a pila el primer valor del *buff
	nuevo= malloc(sizeof(token));
	nuevo->type = buff->type;
	nuevo->valor= buff->valor;
	nuevo->back = pila;

	pila->sgte = nuevo;
	pila= pila->sgte;

	return pila;
}
