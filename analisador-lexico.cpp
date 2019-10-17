#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char lexema[101];
int linha = 1, coluna = 0;

FILE *arquivo, *fopen();

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

typedef struct {
	string nome="";
	string valor="";
}Tokens;

bool ehDigito(char entrada){
	//'0' a '9' -> 48 a 57
	if(entrada >= 48 && entrada <= 57)
		return true;
	return false;
}

bool ehLetra(char entrada){
	// 'A' a 'Z' -> 65 a 90, 'a' a 'z' -> 97 a 122
	if (entrada >= 65 && entrada <= 90 || entrada >= 97 && entrada <= 122)
		return true;
	return false;
}

bool ehIdentificador(char entrada){
	if (ehLetra(entrada) || ehDigito(entrada)){
		return true;
	}
	return false;
}

int main(){
	Tokens token;
	FILE* arquivo = fopen("teste_correto2.txt", "r");// mudar nome do arquivo para cada teste
	//printf ("teste_correto2\n");//usado para identificar as imagens de retorno
	if (arquivo == NULL){
		printf("Erro ao abrir o exemplo.");
		return 1;
	}
	
	string lexema = "";
	char entrada;
	
	do{
		entrada = getc(arquivo);
		lexema+= entrada;
		coluna++;
		
		if (entrada == ' ' || entrada == '	'){
			coluna++;
			lexema ="";
		}
		
		else if (entrada == EOF){
			//FIM DO ARQUIVO
		}
		else if (entrada == '\n'){
			linha++;
			lexema = "";
			coluna = 0;
		}
		else if (entrada == '#'){
			while(1){
				entrada = getc(arquivo);
				if (entrada == '\n')
					break;
			}
			linha++;
			coluna = 0;
		}
		
		else if (ehDigito(entrada)){
			do{
				entrada = getc(arquivo);
				lexema+= entrada;
				coluna++;
			}while (ehDigito(entrada));
			
			if (entrada== '\n' || entrada== ' ' || entrada== EOF || entrada== '#'){
				token.nome = "num";
				token.valor = lexema;
				cout <<"Token:Linha: "<<linha <<":Coluna: "<<coluna<<":Tipo "<<token.nome <<": "<<token.valor<<"\n";
			}
			
			else if (!ehDigito(entrada)){
				cout <<"Erro:Linha: "<<linha <<":Coluna: "<<coluna<<":Digito: " <<lexema <<" mal formado, simbolo "<<entrada <<" nao pertence ao alfabeto\n";
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
		}
		
		else if (ehLetra(entrada)){
			do{
				entrada = getc(arquivo);
				lexema+= entrada;
				coluna++;
			}while (ehIdentificador(entrada));
			
			if (entrada== '\n' || entrada== ' ' || entrada== EOF || entrada== '#'){
				token.nome = "identificador";
				token.valor = lexema;
				cout <<"Token:Linha: "<<linha <<":Coluna: "<<coluna<<":Tipo "<<token.nome <<": "<<token.valor<<"\n";
			}
			
			else if (!ehIdentificador(entrada)){
				cout <<"Erro:Linha: "<<linha <<":Coluna: "<<coluna<<" Identificador: " <<lexema <<" mal formado, caracter "<<entrada <<" nao pertence ao alfabeto\n";
				while(1){
					entrada = getc(arquivo);
					coluna++;
					if (entrada == ' ' || entrada == '\n')
						break;
				}
			}
				
			//cout<<"lexema: "<<lexema <<", linha: "<<linha<<"\n";
			
			lexema = "";
			if(entrada == '\n'){
				linha++;
				coluna = 0;
			}
			
		}
		
		else{
			cout <<"Erro:Linha:"<<linha <<": Coluna:"<<coluna<<": Simbolo:"<<entrada <<" nao pertence ao vocabulario.\n";
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
			/*	else{
					coluna++;
				}*/
			}
		}
		lexema="";
		
	} while(entrada != EOF);
	
	fclose(arquivo);
	return 0;
}
