#ifndef ANALISADOR_SINTATICO_H
#define ANALISADOR_SINTATICO_H

#include "token.h"
#include <stack>

#define N_ESTADOS 84
#define N_TERMINAIS 45 // sem contar com $
#define N_NAO_TERMINAIS 12
#define N_PRODUCOES 41

struct ItemDePilha{
    int estado;
    Token *token;
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



class ArvoreSintatica{
    static const int estado_acc = 45;

    static Estado tabela_slr[N_ESTADOS];
    static Producao gramatica[N_PRODUCOES];

    Pilha pilha;

    //pilha, raiz, tabela
public:
    ArvoreSintatica();
    bool adicionarToken(Token *entrada);
    bool encerrarConstrucao();
    ~ArvoreSintatica();
};

#endif