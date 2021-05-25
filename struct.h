#define TK_SIGN 29	// Signo devuelto por matriz de precedencia
#define TK_NUMB 32	// Valor numerico de tipo Entero
#define TK_OPER 33	// Operacion aritmetica
#define TK_PRNT 36	// Parentesis
#define ERRORES 17

typedef struct Token {
	float valor;
	int type;
	struct Token *sgte;
	struct Token *back;
} token;

typedef struct Lista {
	float valor;
	struct Lista *back;
} lista_int;
