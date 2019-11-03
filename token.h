#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TipoToken{
	TK_ID,
	TK_NUM,
	TK_RW,
	TK_NT_PROGRAMA,
	TK_NT_DECLARACOES,
	TK_NT_DECLARACAO,
	TK_NT_BLOCO,
	TK_NT_COMANDOS,
	TK_NT_COMANDO,
	TK_NT_ITERACAO,
	TK_NT_LACO,
	TK_NT_CONDICIONAL,
	TK_NT_NUMEROS,
	TK_NT_INSTRUCAO,
	TK_NT_CONDICAO  //TODO
};

typedef struct {
	std::string nome = "";
	std::string valor = "";
	TipoToken tipo;
} Token;

#endif