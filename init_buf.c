#include <stdlib.h>
#include "funcion.h"

token *init_buffer(char *argv) {
//	Esta func. elabora un conj. de tokens a partir de una
//	cadena de caracteres: la cuenta 
//
	char *cuenta= (char *)argv;
	token *buff= NULL, *nuevo;
	int carac;

	carac= *cuenta;

	do {
		if (carac >='0' && carac <='9') {
		// Viendo si *cuenta apunta a un nro.
		//
			nuevo= malloc(sizeof(token));
			nuevo->type = TK_NUMB;
			nuevo->valor= atof(cuenta);

			buff= add_tken(buff, nuevo);
			// 
			// Mover ptr 'cuenta' hasta prox operac matem.
			while ((*cuenta >='0' && *cuenta <='9') || *cuenta=='.')
				cuenta++; 	
		}
		else if (carac >=42 && carac <=47) {	// Si 'carac' es una operacion aritmetica..
			nuevo= malloc(sizeof(token));
			nuevo->type = TK_OPER;
			nuevo->valor= *cuenta;

			buff= add_tken(buff, nuevo);
			cuenta++;
		}
		else if (carac=='(' || carac==')') {
			nuevo= malloc(sizeof(token));
			nuevo->type = TK_PRNT;
			nuevo->valor= *cuenta;

			buff= add_tken(buff, nuevo);
			cuenta++;
		}
		else	return NULL;

	} while ( (carac= *cuenta) );

	nuevo= malloc(sizeof(token));		// Agrego al final del *buff
	nuevo->type = TK_OPER;			// el token '$'
	nuevo->valor= '$';
	buff= add_tken(buff, nuevo);

	return buff; 
}
