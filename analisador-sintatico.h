#ifndef ANALISADOR_SINTATICO_H
#define ANALISADOR_SINTATICO_H

#include "token.h"
#include <stack>

#define N_ESTADOS 84
#define N_TERMINAIS 45 // sem contar com $
#define N_NAO_TERMINAIS 12
#define N_PRODUCOES 41

struct ItemDePilha{
    Token *token;
    int estado;
};

typedef std::stack<ItemDePilha> Pilha;

struct Producao{
    TipoToken nao_terminal;
    int n_tokens;
};

struct Estado{
    struct Acao{
        bool shift;
        union{
            int estado, regra;
        };
    };
    Acao acao[N_TERMINAIS];
    int go_to[N_NAO_TERMINAIS];

    void init (int id);
};

class Gramatica{

public:
    int tamanho(int producao);
    TipoToken cabeca(int producao);
};

class TabelaSLR{

public:
    static const int ACAO_INVALIDA = -1;

    bool erro(int estado, TipoToken entrada);
    int empilha(int estado, TipoToken entrada);
    int reduz(int estado, TipoToken entrada);
    int transicao(int estado, TipoToken n_terminal);
    bool aceita(int estado);
};


class ArvoreSintatica{
    static TabelaSLR tabela;
    static Gramatica gramatica;

    Pilha pilha;

public:
    ArvoreSintatica();
    bool adicionarToken(Token *entrada);
    bool encerrarConstrucao();
    ~ArvoreSintatica();
};

#endif