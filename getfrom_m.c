#include <stdio.h>
#include "struct.h"

char getfrom_matriz(token *pila, token *buff)
{
	char *ptrO;
	char ptron[8]= {'+','-','*','/','i','(',')','$'};
	int pos_pila=0, pos_buff=0;
	char char_p, char_b;

	// MATRIZ DE PRECEDENCIA
	char tabla[8][8]= {	
		{'>','>','<','<','<','<','>','>'},
		{'>','>','<','<','<','<','>','>'},
		{'>','>','>','>','<','<','>','>'},
		{'>','>','>','>','<','<','>','>'},
		{'>','>','>','>','e','e','>','>'},
		{'<','<','<','<','<','<','=','e'},
		{'>','>','>','>','e','e','>','>'},
		{'<','<','<','<','<','<','e','f'} 
	};

	char_p= pila->valor;
	char_b= buff->valor;
	if (pila->type== TK_NUMB) char_p= 'i';
	if (buff->type== TK_NUMB) char_b= 'i';

	ptrO = ptron;
	while ( *ptrO++ != char_p )
		pos_pila++;

	ptrO = ptron;
	while ( *ptrO++ != char_b )
		pos_buff++;

	return tabla[pos_pila][pos_buff];
}
