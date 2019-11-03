#include "analisador-sintatico.h"

ArvoreSintatica::ArvoreSintatica(){/*
    pilha.push ({0, nullptr});
    gramatica [0] = {TK_NT_PROGRAMA,     6};
    gramatica [1] = {TK_NT_DECLARACOES,  2};
    gramatica [2] = {TK_NT_DECLARACOES,  0};
    gramatica [3] = {TK_NT_DECLARACAO,   4};
    gramatica [4] = {TK_NT_BLOCO,        3};
    gramatica [5] = {TK_NT_COMANDOS,     2};
    gramatica [6] = {TK_NT_COMANDOS,     0};
    gramatica [7] = {TK_NT_COMANDO,      1};
    gramatica [8] = {TK_NT_COMANDO,      1};
    gramatica [9] = {TK_NT_COMANDO,      1};
    gramatica[10] = {TK_NT_COMANDO,      1};
    gramatica[11] = {TK_NT_COMANDO,      1};
    gramatica[12] = {TK_NT_ITERACAO,     5};
    gramatica[13] = {TK_NT_LACO,         5};
    gramatica[14] = {TK_NT_CONDICIONAL,  8};
    gramatica[15] = {TK_NT_CONDICIONAL,  5};
    gramatica[16] = {TK_NT_NUMEROS,      2};
    gramatica[17] = {TK_NT_NUMEROS,      0};
    gramatica[18] = {TK_NT_INSTRUCAO,    3};
    gramatica[19] = {TK_NT_INSTRUCAO,    2};
    gramatica[20] = {TK_NT_INSTRUCAO,    3};
    gramatica[21] = {TK_NT_INSTRUCAO,    3};
    gramatica[22] = {TK_NT_INSTRUCAO,    1};
    gramatica[23] = {TK_NT_INSTRUCAO,    1};
    gramatica[24] = {TK_NT_INSTRUCAO,    1};
    gramatica[25] = {TK_NT_INSTRUCAO,    2};
    gramatica[26] = {TK_NT_INSTRUCAO,    2};
    gramatica[27] = {TK_NT_INSTRUCAO,    3};
    gramatica[28] = {TK_NT_CONDICAO,     2};
    gramatica[29] = {TK_NT_CONDICAO,     2};
    gramatica[30] = {TK_NT_CONDICAO,     2};
    gramatica[31] = {TK_NT_CONDICAO,     2};
    gramatica[32] = {TK_NT_CONDICAO,     3};
    gramatica[33] = {TK_NT_CONDICAO,     3};
    gramatica[34] = {TK_NT_CONDICAO,     3};
    gramatica[35] = {TK_NT_CONDICAO,     4};
    gramatica[36] = {TK_NT_CONDICAO,     4};
    gramatica[37] = {TK_NT_CONDICAO,     4};
    gramatica[38] = {TK_NT_CONDICAO,     4};
    gramatica[39] = {TK_NT_CONDICAO,     4};
    gramatica[40] = {TK_NT_CONDICAO,     4};
    
    for (int i=0; i<N_ESTADOS; i++){
        tabela_slr[i].init(i);
    }*/
}

bool ArvoreSintatica::adicionarToken(Token *entrada)
{
    entrada->setarTipo();

    if (tabela.erro(pilha.top().estado, entrada->tipo)){
        return false;
    }

    int estado_empilha = tabela.empilha(pilha.top().estado, entrada->tipo);
    if (estado_empilha != TabelaSLR::ACAO_INVALIDA){
        pilha.push( {entrada, estado_empilha} );
        return true;
    }

    int producao_reduz = tabela.reduz(pilha.top().estado, entrada->tipo);
    if (producao_reduz != TabelaSLR::ACAO_INVALIDA){
        Token *n_terminal = new Token( gramatica.cabeca(producao_reduz) );
        for (int i=0; i<gramatica.tamanho(producao_reduz); i++){
            n_terminal->adicionarFilho(pilha.top().token);
            pilha.pop();
        }
        pilha.push({ 
            n_terminal, 
            tabela.transicao(pilha.top().estado, n_terminal->tipo) 
        });
        return true;
    }

    return false;
}

void Estado::init (int id){
    //TODO
}