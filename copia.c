#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "funcion.h"
#include "servicio.h"
#define SINTC "La Matriz de Precedencia encontro un ERROR SINTACTICO\n"

int comp_main(char cuenta_ind[])
{
	token *pila, *buffer;
	lista_int *lista;
	char *cuenta= cuenta_ind;
	float respuesta;
	int val;
	char *str= malloc(sizeof(char)*512);

	// bloquear fd_arch
	if (pthread_mutex_lock(&mutex)!= 0) {
		perror("pthread_mutex_lock()");
		return 1;
	}
	sprintf(str, "\nRESOLVER CUENTA: %s\n", cuenta);
	putc(10, stdout);
	write(fd_arch, str, strlen(str));

//	if (val= lexico_crteres(cuenta)) {
	if (val= lexico(cuenta)) {
		sprintf(str, "\tERROR LEXICO: Signo '%c' es invalido\n", val);
		write(fd_arch, str, strlen(str));
		if (pthread_mutex_unlock(&mutex)!= 0)  
			perror("pthread_mutex_unlock()");
		return ERRORES;
	}
	buffer= init_buffer(cuenta);
/*
	if ((val= lexico_operac(buffer))!= 0) {
		sprintf(str, "\tERROR LEXICO: Otra operac. antes de '%c' \n", val);
		write(fd_arch, str, strlen(str));
		if(pthread_mutex_unlock(&mutex) != 0)  
			perror("pthread_mutex_unlock()");
		return ERRORES;
	}
*/
	pila= malloc(sizeof(token));
	pila->type = TK_OPER;
	pila->valor= '$';

	if ((lista= sintactico(pila, buffer))== NULL) {
		write(fd_arch, SINTC, sizeof SINTC -1);
		if(pthread_mutex_unlock(&mutex) != 0)  
			perror("pthread_mutex_unlock()");
		return ERRORES;
	}
	
	respuesta= lista->valor;
	sprintf(str, "\tRespuesta: %.5f\n", respuesta);
	write(fd_arch, str, strlen(str));
	free(str);

	if(pthread_mutex_unlock(&mutex)!= 0) {
		perror("pthread_mutex_unlock()");
		return 1;
	}
	return 0;
}
