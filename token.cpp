#include "token.h"

Token::Token(){
    lexema = "";
    tipo = TK_NULO;
}

Token::Token(TipoToken _tipo, int n_filhos){
    lexema = "";
    tipo = _tipo;
}

Token::Token(TipoToken _tipo, std::string _lexema){
    lexema = _lexema; //TO LOWERCASE
    if (_tipo != TK_IDENTIFICADOR){
        tipo = _tipo;
    } else {
        if (lexema == "programainicio"){
            tipo = TK_RW_PROGRAMAINICIO;
        }else if (lexema == "execucaoinicio") {
            tipo = TK_RW_EXECUCAOINICIO;
        }else if (lexema == "fimexecucao") {
            tipo = TK_RW_FIMEXECUCAO;
        }else if (lexema == "fimprograma") {
            tipo = TK_RW_FIMPROGRAMA;
        }else if (lexema == "definainstrucao") {
            tipo = TK_RW_DEFINAINSTRUCAO;
        }else if (lexema == "como") {
            tipo = TK_RW_COMO;
        }else if (lexema == "inicio") {
            tipo = TK_RW_INICIO;
        }else if (lexema == "fim") {
            tipo = TK_RW_FIM;
        }else if (lexema == "repita") {
            tipo = TK_RW_REPITA;
        }else if (lexema == "vezes") {
            tipo = TK_RW_VEZES;
        }else if (lexema == "fimrepita") {
            tipo = TK_RW_FIMREPITA;
        }else if (lexema == "enquanto") {
            tipo = TK_RW_ENQUANTO;
        }else if (lexema == "faca") {
            tipo = TK_RW_FACA;
        }else if (lexema == "fimpara") {
            tipo = TK_RW_FIMPARA;
        }else if (lexema == "se") {
            tipo = TK_RW_SE;
        }else if (lexema == "senao") {
            tipo = TK_RW_SENAO;
        }else if (lexema == "fimsenao") {
            tipo = TK_RW_FIMSENAO;
        }else if (lexema == "mova") {
            tipo = TK_RW_MOVA;
        }else if (lexema == "passos") {
            tipo = TK_RW_PASSOS;
        }else if (lexema == "vire") {
            tipo = TK_RW_VIRE;
        }else if (lexema == "para") {
            tipo = TK_RW_PARA;
        }else if (lexema == "esquerda") {
            tipo = TK_RW_ESQUERDA;
        }else if (lexema == "direita") {
            tipo = TK_RW_DIREITA;
        }else if (lexema == "finalize") {
            tipo = TK_RW_FINALIZE;
        }else if (lexema == "apague") {
            tipo = TK_RW_APAGUE;
        }else if (lexema == "lampada") {
            tipo = TK_RW_LAMPADA;
        }else if (lexema == "acenda") {
            tipo = TK_RW_ACENDA;
        }else if (lexema == "aguarde") {
            tipo = TK_RW_AGUARDE;
        }else if (lexema == "ate") {
            tipo = TK_RW_ATE;
        }else if (lexema == "robo") {
            tipo = TK_RW_ROBO;
        }else if (lexema == "pronto") {
            tipo = TK_RW_PRONTO;
        }else if (lexema == "ocupado") {
            tipo = TK_RW_OCUPADO;
        }else if (lexema == "parado") {
            tipo = TK_RW_PARADO;
        }else if (lexema == "movimentando") {
            tipo = TK_RW_MOVIMENTANDO;
        }else if (lexema == "frente") {
            tipo = TK_RW_FRENTE;
        }else if (lexema == "bloqueada") {
            tipo = TK_RW_BLOQUEADA;
        }else if (lexema == "acesa") {
            tipo = TK_RW_ACESA;
        }else if (lexema == "a") {
            tipo = TK_RW_A;
        }else if (lexema == "apagada") {
            tipo = TK_RW_APAGADA;
        }
    }
}

void Token::adicionarFilho(Token *filho){
    filhos.push_front(filho);
}

/*
void Token::setarTipo(){
    if (lexema == "num") {  //TODO GIGANTE
        tipo = TK_NUMERO;
    } else if ("identificador") {
        //TODO
    } else if ("identificador") {
        //TODO
    }
}
*/