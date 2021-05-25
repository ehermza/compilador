
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 7

//	ezequielher -Fecha: 18-04-08
// 	ANALIZADOR LEXICO PARA OPERACIONES MATEMATICAS
// 	CON MATRIZ DE TRANSICIONES P/ AUTOMATAS
//

const int cant[SIZE]= {5,2,1,8,1,2,6};
int ptros[SIZE];
const char crteres[]= {	'D','+','-','(','$','D','(','D','D','.','+','-','*','/',')','$',
			'D','D','(','+','-','*','/',')','$'};
const int estados[]= {3,2,2,1,7,3,1,3,3,4,5,5,5,5,6,7,3,3,1,5,5,5,5,6,7};

void llenar_ptros(){
	int i, acum= 0;
	int tamano= SIZE;

	for (i=0; i<tamano; i++) {
		ptros[i]= acum;
		acum= acum + cant[i];
	}
}

int get_estado(int stado, char crter)
{
	int cont;
	char valor;
	
	if (isdigit(crter))
		valor= 'D';
	else	valor= crter;
	
	int i;
	int max= cant[stado];
	int posic= ptros[stado];
	char resp= 'E';

	for (i=0; i<max; i++) {
		if (crteres[posic]==valor) {
			resp= estados[posic];
			break;
		}
		else	posic++;
	}
	return resp;
}
//int main(int argc, char *argv[])
int lexico(char *cuenta)
{
	llenar_ptros();

	char crter;
	int resp, stado= 0;
//	strcat(cuenta, "$");

	while (crter= *cuenta++) {
//		printf("stado:%d crter:%c \n", stado, crter);
		stado= get_estado(stado, crter);
		if (stado=='E' || stado==7) break;
	}	

	return crter;
}
