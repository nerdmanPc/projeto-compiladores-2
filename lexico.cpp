#include <stdio.h>
#include <string.h>
#include "token.h"
#include "log.h"
#include "sintatico.h"

using namespace std;

int linha = 1, coluna = 0;


string palavrasChaves[100] = {
	"programainicio", "execucaoinicio", "fimexecucao", "fimprograma", 
	"definainstrucao", "como", 
	"inicio", "fim", 
	"repita", "vezes", "fimrepita", 
	"enquanto", "faca", "fimpara", 
	"se", "entao", "fimse", "senao", "fimsenao", 
	"mova", "passos", "Vire", "Para", "Pare", "Finalize", "Apague", "Lampada", "Acenda", "Aguarde", "Ate", 
	"Robo", "Pronto", "Ocupado", "Parado", "Movimentando", "Frente", "Bloqueada", "Acessa", "a", "Esquerda", "Direita"
};

bool ehDigito(char entrada){
		if(entrada >= 48 && entrada <= 57)
		return true;
	return false;
}

bool ehLetra(char entrada){
		if ( (entrada >= 'A' && entrada <= 'Z') || (entrada >= 'a' && entrada <= 'z') )
		return true;
	return false;
}

bool ehIdentificador(char entrada){
	if (ehLetra(entrada) || ehDigito(entrada)){
		return true;
	}
	return false;
}

int main(int argc, char **argv){
	Token *token;
	FILE* arquivo = NULL;
	if (argc >= 1) {
		arquivo = fopen(argv[1], "r");
			}
	if (arquivo == NULL){
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}
	string lexema = "";
	char entrada;
	ArvoreSintatica arvore;
	do{
		entrada = getc(arquivo);
		lexema += entrada;
		coluna++;
		if (entrada == ' ' || entrada == '	'){
			coluna++;
			lexema ="";
		}else if (entrada == EOF){
			break;
		}else if (entrada == '\n'){
			linha++;
			lexema = "";
			coluna = 0;
		}else if (entrada == '#'){
			while(1){
				entrada = getc(arquivo);
				if (entrada == '\n')
					break;
			}
			linha++;
			coluna = 0;
		}else if (ehDigito(entrada)){
			do{
				entrada = getc(arquivo);
				lexema += entrada;
				coluna++;
			}while (ehDigito(entrada));
			if (entrada== '\n' || entrada== ' ' || entrada == EOF || entrada == '#' || entrada == '\t'){
				token = new Token(TK_NUMERO, lexema);
				token->print();
				arvore.adicionarToken(token);
				token = NULL;
							}else if (!ehDigito(entrada)){
				erro_lexico(linha, coluna, "Símbolo mal formado.");
				while(1){
					entrada = getc(arquivo);
					coluna++;
					if (entrada == ' ' || entrada == '\n')
						break;
					if (entrada == '\n'){
						break;
					}
				}
			}
			lexema= "";
			if(entrada == '\n')
				linha++;
		}else if (ehLetra(entrada)){
			do{
				entrada = getc(arquivo);
				lexema+= entrada;
				coluna++;
			}while (ehIdentificador(entrada));
			if (entrada== '\n' || entrada== ' ' || entrada== EOF || entrada== '#'){
				token = new Token(TK_IDENTIFICADOR, lexema);
				token->print();
				arvore.adicionarToken(token);
				token = NULL;
			}else if (!ehIdentificador(entrada)){
				erro_lexico(linha, coluna, "Símbolo mal formado.");
			while(1){
					entrada = getc(arquivo);
					coluna++;
					if (entrada == ' ' || entrada == '\n')
						break;
				}
			}
			lexema = "";
			if(entrada == '\n'){
				linha++;
				coluna = 0;
			}
		}else{
			erro_lexico(linha, coluna, "Símbolo mal formado.");
			while (1){
				entrada = getc(arquivo);
				if (entrada == ' '|| entrada == '	'){
					break;
				}
				if (entrada == '\n'){
					linha++;
					coluna = 0;
					break;
				}
			}
		}
		lexema="";
	} while(entrada != EOF);
	bool sucesso = arvore.encerrarConstrucao();
	
	fclose(arquivo);
	return 0;
}
