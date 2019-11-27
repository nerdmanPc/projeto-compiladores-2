#ifndef ANALISADOR_SINTATICO_H
#define ANALISADOR_SINTATICO_H

#include "token.h"
#include <stack>
#include <map>

#define N_ESTADOS 84
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
    AC_REDUZ
};
struct Acao{
    TipoAcao tipo;
    union { int transicao, regra; };
};
typedef std::map<TipoToken, Acao> Estado;

class TabelaSLR
{
    Estado linhas[N_ESTADOS];

    public:

    static const int estado_acc = 45;
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
    static TabelaSLR tabela;
    static Gramatica gramatica;
    Pilha pilha;

    public:

    ArvoreSintatica();
    bool adicionarToken(Token *entrada);
    bool encerrarConstrucao();
};

#endif