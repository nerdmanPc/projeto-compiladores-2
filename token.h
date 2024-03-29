#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <list>
#include <stdio.h>


enum TipoToken: int 
{
	TK_NULO = 0,

	TK_IDENTIFICADOR,
	TK_NUMERO,
	
	TK_RW_PROGRAMAINICIO,
	TK_RW_EXECUCAOINICIO,
	TK_RW_FIMEXECUCAO,
	TK_RW_FIMPROGRAMA,
	TK_RW_DEFINAINSTRUCAO,
	TK_RW_COMO,
	TK_RW_INICIO,
	TK_RW_FIM,
	TK_RW_REPITA,
	TK_RW_VEZES,
	TK_RW_FIMREPITA,
	TK_RW_ENQUANTO,
	TK_RW_FACA,
	TK_RW_FIMPARA,
	TK_RW_SE,
	TK_RW_ENTAO,
	TK_RW_FIMSE,
	TK_RW_SENAO,
	TK_RW_FIMSENAO,
	TK_RW_MOVA,
	TK_RW_PASSOS,
	TK_RW_VIRE,
	TK_RW_PARA,
	TK_RW_ESQUERDA,
	TK_RW_DIREITA,
	TK_RW_PARE,
	TK_RW_FINALIZE,
	TK_RW_APAGUE,
	TK_RW_LAMPADA,
	TK_RW_ACENDA,
	TK_RW_AGUARDE,
	TK_RW_ATE,
	TK_RW_ROBO,
	TK_RW_PRONTO,
	TK_RW_OCUPADO,
	TK_RW_PARADO,
	TK_RW_MOVIMENTANDO,
	TK_RW_FRENTE,
	TK_RW_BLOQUEADA,
	TK_RW_ACESA,
	TK_RW_A,
	TK_RW_APAGADA,

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
	TK_NT_CONDICAO,

	TK_EOF
};

struct Token
{
	std::string lexema;
	TipoToken tipo;
	std::list<Token*> filhos;

	Token();
	Token(TipoToken tipo, const std::string& lexema); //Para terminais
	Token(TipoToken tipo, int n_filhos); //Para não terminais
	void adicionarFilho(Token *filho); 
	void print();
	//void setarTipo();
};

TipoToken tokenPorNome(const char *celula);

#endif