#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pilha.h"
#include "resolucao.h"
#include <time.h>

int main()
{

    char linha[201];
    int iterador, numeroDuvidinhas=0;
    fgets (linha, 201, stdin); //leio a linha dada na entrada padrão

    int resposta;
    scanf("%d", &resposta); //leio a resposta dada na entrada padrão

    for (iterador = 0; iterador < 201; iterador++){ //faço uma iteração na linha em busca do número de "?" existentes. ele será usado mais a frente.
        if (linha[iterador] == '?'){
            numeroDuvidinhas++;
        }
    }

    possibilidades(numeroDuvidinhas, linha, resposta); //envio, para a minha função principal que resolve o problema, o número de "?", a linha dada na entrada padrão e a resposta.

    return 0;
}
