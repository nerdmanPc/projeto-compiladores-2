#include "token.h"

Token::Token(){
    lexema = "";
    tipo = TK_NULO;
}

Token::Token(TipoToken _tipo, int n_filhos){
    lexema = "";
    tipo = _tipo;
}

Token::Token(TipoToken _tipo, const std::string& _lexema){
    lexema = _lexema; //TO LOWERCASE
    if ((_tipo != TK_IDENTIFICADOR)){
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
        }else if (lexema == "entao") {
            tipo = TK_RW_ENTAO;
        }else if (lexema == "fimse") {
            tipo = TK_RW_FIMSE;
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
        }else if (lexema == "pare") {
            tipo = TK_RW_PARE;
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
        }else{
            tipo = TK_IDENTIFICADOR;
        }
    }
}

void Token::adicionarFilho(Token *filho){
    filhos.push_front(filho);
}

void Token::print(){
    printf("Token %d, '%s'\n", (int) tipo, lexema.c_str());
}

TipoToken tokenPorNome(const char *_celula)
{
    std::string celula(_celula);
    if (celula == "programainicio"){
        return TK_RW_PROGRAMAINICIO;
    }else if (celula == "execucaoinicio") {
        return TK_RW_EXECUCAOINICIO;
    }else if (celula == "fimexecucao") {
        return TK_RW_FIMEXECUCAO;
    }else if (celula == "fimprograma") {
        return TK_RW_FIMPROGRAMA;
    }else if (celula == "definainstrucao") {
        return TK_RW_DEFINAINSTRUCAO;
    }else if (celula == "como") {
        return TK_RW_COMO;
    }else if (celula == "inicio") {
        return TK_RW_INICIO;
    }else if (celula == "fim") {
        return TK_RW_FIM;
    }else if (celula == "repita") {
        return TK_RW_REPITA;
    }else if (celula == "vezes") {
        return TK_RW_VEZES;
    }else if (celula == "fimrepita") {
        return TK_RW_FIMREPITA;
    }else if (celula == "enquanto") {
        return TK_RW_ENQUANTO;
    }else if (celula == "faca") {
        return TK_RW_FACA;
    }else if (celula == "fimpara") {
        return TK_RW_FIMPARA;
    }else if (celula == "se") {
        return TK_RW_SE;
    }else if (celula == "entao") {
        return TK_RW_ENTAO;
    }else if (celula == "fimse") {
        return TK_RW_FIMSE;
    }else if (celula == "senao") {
        return TK_RW_SENAO;
    }else if (celula == "fimsenao") {
        return TK_RW_FIMSENAO;
    }else if (celula == "mova") {
        return TK_RW_MOVA;
    }else if (celula == "passos") {
        return TK_RW_PASSOS;
    }else if (celula == "vire") {
        return TK_RW_VIRE;
    }else if (celula == "para") {
        return TK_RW_PARA;
    }else if (celula == "esquerda") {
        return TK_RW_ESQUERDA;
    }else if (celula == "direita") {
        return TK_RW_DIREITA;
    }else if (celula == "pare") {
        return TK_RW_PARE;
    }else if (celula == "finalize") {
        return TK_RW_FINALIZE;
    }else if (celula == "apague") {
        return TK_RW_APAGUE;
    }else if (celula == "lampada") {
        return TK_RW_LAMPADA;
    }else if (celula == "acenda") {
        return TK_RW_ACENDA;
    }else if (celula == "aguarde") {
        return TK_RW_AGUARDE;
    }else if (celula == "ate") {
        return TK_RW_ATE;
    }else if (celula == "robo") {
        return TK_RW_ROBO;
    }else if (celula == "pronto") {
        return TK_RW_PRONTO;
    }else if (celula == "ocupado") {
        return TK_RW_OCUPADO;
    }else if (celula == "parado") {
        return TK_RW_PARADO;
    }else if (celula == "movimentando") {
        return TK_RW_MOVIMENTANDO;
    }else if (celula == "frente") {
        return TK_RW_FRENTE;
    }else if (celula == "bloqueada") {
        return TK_RW_BLOQUEADA;
    }else if (celula == "acesa") {
        return TK_RW_ACESA;
    }else if (celula == "a") {
        return TK_RW_A;
    }else if (celula == "apagada") {
        return TK_RW_APAGADA;
    }else if (celula == "identificador") {
        return TK_IDENTIFICADOR;
    }else if (celula == "numero") {
        return TK_NUMERO;
    }else if (celula == "Programa") {
        return TK_NT_PROGRAMA;
    }else if (celula == "Declaracoes") {
        return TK_NT_DECLARACOES;
    }else if (celula == "Declaracao") {
        return TK_NT_DECLARACAO;
    }else if (celula == "Bloco") {
        return TK_NT_BLOCO;
    }else if (celula == "Comandos") {
        return TK_NT_COMANDOS;
    }else if (celula == "Comando") {
        return TK_NT_COMANDO;
    }else if (celula == "Iteracao") {
        return TK_NT_ITERACAO;
    }else if (celula == "Laco") {
        return TK_NT_LACO;
    }else if (celula == "Condicional") {
        return TK_NT_NUMEROS;
    }else if (celula == "Numeros") {
        return TK_NT_NUMEROS;
    }else if (celula == "Instrucao") {
        return TK_NT_INSTRUCAO;
    }else if (celula == "Condicao") {
        return TK_NT_CONDICAO;
    }else if (celula == "$") {
        return TK_EOF;
    }else{
        return TK_NULO;
    }
}