#ifndef ANALISADOR_SINTATICO_H
#define ANALISADOR_SINTATICO_H

#include "token.h"
#include <stack>
#include <map>
//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <string.h>
// #include <stdlib.h> 

#define N_ESTADOS 85
#define N_TERMINAIS 45 // sem contar com $
#define N_NAO_TERMINAIS 12
#define N_PRODUCOES 41
#define ESTADO_ACC 45

struct ItemDePilha{
    Token *token;
    int estado;
};
typedef std::stack<ItemDePilha> Pilha;

struct Producao{
    TipoToken nao_terminal;
    int n_tokens;
};
class Gramatica
{
    Producao producoes[N_PRODUCOES];

    public:
    
    Gramatica();
    int tamanho(int producao);
    TipoToken cabeca(int producao);
};

enum TipoAcao{
    AC_EMPILHA,
    AC_REDUZ,
    AC_GOTO,
    AC_ACC,
    AC_INVALIDA
};
struct Acao{
    TipoAcao tipo;
    union { int transicao, regra; };
    Acao();
    Acao(const char *celula);
};
typedef std::map<TipoToken, Acao> Estado;

class TabelaSLR
{
    Estado linhas[N_ESTADOS];
    static int estado_acc;

    public:

    static const int ACAO_INVALIDA = -1;

    TabelaSLR();
    bool erro(int estado, TipoToken entrada);
    int empilha(int estado, TipoToken entrada);
    int reduz(int estado, TipoToken entrada);
    int transicao(int estado, TipoToken n_terminal);
    bool aceita(int estado);
};

class ArvoreSintatica
{
    TabelaSLR tabela;
    Gramatica gramatica;
    Pilha pilha;

    public:

    ArvoreSintatica();
    bool adicionarToken(Token *entrada);
    bool encerrarConstrucao();
};

#endif