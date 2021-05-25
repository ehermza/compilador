//	
//	COMPILADOR -ANALIZADOR LEXICO & SINTACTICO
//	PARA VERIFICAR Y RESOLVER OPERACIONES ARITMETICAS
//	Ultima modificacion: 28-04-08
//	Autor: Ezequiel Hernandez  [ezequielher]
//	E-mail: ezequielhernan@yahoo.com -Web: http://ezequielher.wordpress.com

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  any later version.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funcion.h"
#define SINTC "ERROR SINTACTICO: Encontrado por matriz de precedencia\n"

int main(int argc, char *argv[])
{
	token *pila, *buffer;
	lista_int *lista;
	char *cuenta= argv[1];
	float respuesta;
	int val;
	char *str= malloc(sizeof(char)*512);

	if (argc!= 2) {
		puts("Argumentos mal ingresados");
		fprintf(stderr, "Modo de ejecucion: %s 'cuenta'\n", argv[0]);
		return ERRORES;
	}
	sprintf(str, "\nRESOLVER CUENTA: %s\n", cuenta);
	puts(str);

	if (val= lexico(cuenta)) {
		fprintf(stderr, "ERROR LEXICO: Signo '%c' es invalido\n", val);
		return ERRORES;
	}
	buffer= init_buffer(cuenta);

	pila= malloc(sizeof(token));
	pila->type = TK_OPER;
	pila->valor= '$';

	if ((lista= sintactico(pila, buffer))== NULL) {
		fprintf(stderr, SINTC);
		return ERRORES;
	}
	
	respuesta= lista->valor;
	fprintf(stdout, "Respuesta: %.5f\n", respuesta);
	free(str);

	return 0;
}
