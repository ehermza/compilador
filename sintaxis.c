#include <stdlib.h>
#include <stdio.h> 
#include "funcion.h"

lista_int *sintactico(token *pila, token *buff)
{	
	int oper;
	lista_int *lista= NULL;
	lista_int *nuevo;
	char carac= getfrom_matriz(pila, buff);
	// getfrom_matriz: Retorna signo desde matriz de presedencia.
	// Retornara uno de estos valores: <, >, =, f, e
	//
	while (carac!='e' && carac!='f') 
	{
					// Se realizara una accion determinada segun
		if (carac=='>') {	// el valor devuelto por matriz de precedencia
//			fputs("Signo > podando..\n", stdout);
			switch (pila->type) 
			{
			case TK_OPER:			// Si podo una operac. aritmetica
				oper = pila->valor;	// apuntada en pila: Resolver()
				lista= resolver(lista, oper);
//				fprintf(stdout, "resolver operacion: %c\n", oper);
				break;
			case TK_NUMB:			
				nuevo= malloc(sizeof(lista_int));	// Si podo un numero apuntado
				nuevo->valor= pila->valor;		// en pila: Almacenarlo en *lista
				nuevo->back= lista;
				lista= nuevo;
//				fprintf(stdout, "almaceno valor: %d\n", numb);
				break;
			}
			pila = podar(pila);	// Retroceder ptr *pila 2 casilleros
		}
		else if (carac=='<' || carac=='=') {	// pasar valor apuntado por *buffer a *pila;
			pila= traslado(pila, buff, carac);
			buff= buff->sgte;
		}
		else 
			return NULL;
							// Comparar valores apuntados por *pila && *buff
		carac= getfrom_matriz(pila, buff);	// y la fc. devolvera el signo devuelto por matriz
	}

	if (carac=='e') return NULL; 	// Matriz de precedencia devolvio un error sintactico
	
	return lista;
}
