#include <stdlib.h>
#include "funcion.h"

token *add_tken(token *tkens, token *nuevo){	
	token *inicio;

	if (tkens==NULL) return nuevo;

	inicio= tkens;
	
	while (tkens->sgte!=NULL)
		tkens= tkens->sgte;
	
	nuevo->sgte= NULL;
//	nuevo->back= tkens;
	tkens->sgte= nuevo;

	return inicio;
}
