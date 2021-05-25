#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

lista_int *resolver(lista_int *lista, char operac) {
	float vlor1, vlor2, respues;
	lista_int *nuevo= malloc (sizeof(lista_int));
	
	vlor2= lista->valor;
	lista= lista->back;
	vlor1= lista->valor;
	lista= lista->back;

	switch (operac) {

	case '+':
		respues= vlor1 + vlor2;
		break;
	case '-':
		respues= vlor1 - vlor2;
		break;
	case '*':
		respues= vlor1 * vlor2;
		break;
	case '/':
		respues= vlor1 / vlor2;
		break;
	}
	
	nuevo->valor= respues;
	nuevo->back= lista;

	return nuevo;	
}
