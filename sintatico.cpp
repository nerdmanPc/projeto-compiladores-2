#include "sintatico.h"

Gramatica::Gramatica()
{
    producoes [0] = {TK_NT_PROGRAMA,     6};
    producoes [1] = {TK_NT_DECLARACOES,  2};
    producoes [2] = {TK_NT_DECLARACOES,  0};
    producoes [3] = {TK_NT_DECLARACAO,   4};
    producoes [4] = {TK_NT_BLOCO,        3};
    producoes [5] = {TK_NT_COMANDOS,     2};
    producoes [6] = {TK_NT_COMANDOS,     0};
    producoes [7] = {TK_NT_COMANDO,      1};
    producoes [8] = {TK_NT_COMANDO,      1};
    producoes [9] = {TK_NT_COMANDO,      1};
    producoes[10] = {TK_NT_COMANDO,      1};
    producoes[11] = {TK_NT_COMANDO,      1};
    producoes[12] = {TK_NT_ITERACAO,     5};
    producoes[13] = {TK_NT_LACO,         5};
    producoes[14] = {TK_NT_CONDICIONAL,  8};
    producoes[15] = {TK_NT_CONDICIONAL,  5};
    producoes[16] = {TK_NT_NUMEROS,      2};
    producoes[17] = {TK_NT_NUMEROS,      0};
    producoes[18] = {TK_NT_INSTRUCAO,    3};
    producoes[19] = {TK_NT_INSTRUCAO,    2};
    producoes[20] = {TK_NT_INSTRUCAO,    3};
    producoes[21] = {TK_NT_INSTRUCAO,    3};
    producoes[22] = {TK_NT_INSTRUCAO,    1};
    producoes[23] = {TK_NT_INSTRUCAO,    1};
    producoes[24] = {TK_NT_INSTRUCAO,    1};
    producoes[25] = {TK_NT_INSTRUCAO,    2};
    producoes[26] = {TK_NT_INSTRUCAO,    2};
    producoes[27] = {TK_NT_INSTRUCAO,    3};
    producoes[28] = {TK_NT_CONDICAO,     2};
    producoes[29] = {TK_NT_CONDICAO,     2};
    producoes[30] = {TK_NT_CONDICAO,     2};
    producoes[31] = {TK_NT_CONDICAO,     2};
    producoes[32] = {TK_NT_CONDICAO,     3};
    producoes[33] = {TK_NT_CONDICAO,     3};
    producoes[34] = {TK_NT_CONDICAO,     3};
    producoes[35] = {TK_NT_CONDICAO,     4};
    producoes[36] = {TK_NT_CONDICAO,     4};
    producoes[37] = {TK_NT_CONDICAO,     4};
    producoes[38] = {TK_NT_CONDICAO,     4};
    producoes[39] = {TK_NT_CONDICAO,     4};
    producoes[40] = {TK_NT_CONDICAO,     4};
}

int Gramatica::tamanho(int producao){
    return producoes[producao].n_tokens;
}

TipoToken Gramatica::cabeca(int producao){
    return producoes[producao].nao_terminal;
}

Acao::Acao(const char *celula){
    if ( (celula[0] == '\0') || (celula[0] == ' ') ){
        printf  ("ERRO: Programa tentou inicializar ação inválida.");
    }else if (celula[0] == 's'){
        tipo = AC_EMPILHA;
        sscanf(celula, "s%i", &transicao);
    }else if (celula[0] == 'r'){
        tipo = AC_REDUZ;
        sscanf(celula, "r%i", &regra);
    }else if (celula[0] >= '0' && celula[0] <= '9'){
        tipo = AC_GOTO;
        sscanf(celula, "%i", &transicao);
    }
}

Acao::Acao(){
    tipo = AC_INVALIDA;
    transicao = TabelaSLR::ACAO_INVALIDA;
}

TabelaSLR::TabelaSLR()
{
    FILE *arquivo = fopen("tabela_slr.csv", "r");
    if (arquivo == NULL){
        printf("ERRO: Tabela SLR não encontrada.\n");
        return;
    }

    char *tex_linha = NULL;
    size_t cap_linha = 0;
    size_t tam_linha = getline(&tex_linha, &cap_linha, arquivo);

    TipoToken tokens[N_TERMINAIS + N_NAO_TERMINAIS + 2];

    char *celula = strtok(tex_linha, ","); //Celula = "State": Ignorar
    celula = strtok(NULL, ","); //Lê primeira coluna útil
    int coluna = 0;
    while(celula != NULL){
        tokens[coluna] = tokenPorNome(celula);
        coluna++;
        celula = strtok(NULL, ",\n");
    }

    tam_linha = getline(&tex_linha, &cap_linha, arquivo);
    int linha = 0;
    while (tam_linha != EOF){
        celula = strtok(tex_linha, ","); //Consome a célula dos Estados
        celula = strtok(NULL, ",\n"); //Lê a primeira coluna útil
        coluna = 0;
        while(celula != NULL){
            if (celula[0] != ' ' && celula[0] != '\0'){
                linhas [linha] [tokens[coluna]] = Acao(celula); 
            }
            celula = strtok(NULL, ",\n");
            coluna++;
        }
        linha++;
        tam_linha = getline(&tex_linha, &cap_linha, arquivo);
    }

    if (tex_linha){
        free(tex_linha);
    }
    fclose(arquivo);
    return;
    //TODO
}

bool TabelaSLR::erro(int estado, TipoToken entrada){
    auto n_elementos = linhas[estado].count(entrada);
    return n_elementos == 0; 
}

int TabelaSLR::empilha(int estado, TipoToken entrada){
    auto celula = linhas[estado].find(entrada);
    if (celula == linhas[estado].end() || celula->second.tipo != AC_EMPILHA){
        return ACAO_INVALIDA;
    }
    return celula->second.transicao;
}

int TabelaSLR::reduz(int estado, TipoToken entrada){
    auto celula = linhas[estado].find(entrada);
    if (celula == linhas[estado].end() || celula->second.tipo != AC_REDUZ){
        return ACAO_INVALIDA;
    }
    return celula->second.regra;
}

int TabelaSLR::transicao(int estado, TipoToken n_terminal){
    auto celula = linhas[estado].find(n_terminal);
    if (celula == linhas[estado].end()){
        return ACAO_INVALIDA;
    }
    return celula->second.transicao;
}

bool TabelaSLR::aceita(int estado){
    return linhas[estado][TK_EOF].tipo == AC_ACC;
}

bool ArvoreSintatica::adicionarToken(Token *entrada)
{
    if (tabela.erro(pilha.top().estado, entrada->tipo)){
        return false;
    }

    int estado_empilha = tabela.empilha(pilha.top().estado, entrada->tipo);
    if (estado_empilha != TabelaSLR::ACAO_INVALIDA)
    {
        pilha.push( {entrada, estado_empilha} );
        return true;
    }

    int producao_reduz = tabela.reduz(pilha.top().estado, entrada->tipo);
    if (producao_reduz != TabelaSLR::ACAO_INVALIDA)
    {
        Token *n_terminal = new Token( 
            gramatica.cabeca(producao_reduz), 
            gramatica.tamanho(producao_reduz) );
        for (int i=0; i<gramatica.tamanho(producao_reduz); i++)
        {
            n_terminal->adicionarFilho(pilha.top().token);
            pilha.pop();
        }
        pilha.push({ 
            n_terminal, 
            tabela.transicao(pilha.top().estado, n_terminal->tipo) });
        return true;
    }
    return false;
}

bool ArvoreSintatica::encerrarConstrucao(){
    return tabela.aceita(pilha.top().estado);
}

ArvoreSintatica::ArvoreSintatica(){
    pilha = Pilha();
    pilha.push ( {nullptr, 0} );
    gramatica = Gramatica();
    tabela = TabelaSLR();
}