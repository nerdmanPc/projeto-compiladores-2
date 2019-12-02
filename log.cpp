#include "log.h"

void erro_lexico(int linha, int coluna, const char *mensagem){
    printf("Erro léxico na linha %i, coluna %i: %s\n", linha, coluna, mensagem);
}