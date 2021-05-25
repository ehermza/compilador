#include <stdlib.h>
#include "funcion.h"

token *podar(token *pila)
{
	int vlor_p = pila->valor;

	if (vlor_p ==')') {
//		pila= pila->back;
		pila= pila->back;
	}
//	pila= pila->back;	// podando
	pila= pila->back;	// podando

	pila->sgte= NULL;

	return pila;
}
