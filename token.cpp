#include "token.h"

Token::Token(){
    nome = "";
    valor = "";
    tipo = TK_NULO;
}

Token::Token(TipoToken _tipo, int n_filhos){
    nome = "";
    valor = "";
    tipo = _tipo;
}
void Token::adicionarFilho(Token *filho){
    filhos.push_front(filho);
}
void Token::setarTipo(){
    if (nome == "num") {
        tipo = TK_NUMERO;
    } else if ("identificador") {
        //TODO
    } else if ("identificador") {
        //TODO
    }
}