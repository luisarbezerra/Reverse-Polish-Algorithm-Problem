#include "resolucao.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int validacao(char linha[], int resultado){ //aqui, recebo a linha temporária e o resultado dado na entrada padrão.
    struct pilha *numeros = criaPilha(); //para esta parte, resolvi incrementar a lógica da Notação Polonesa Invertida seguindo a incrementação de uma pilha. crio uma pilha, no caso dado.

    int resultadoPossibilidades; //esta variável será a que guardará o resultado daquela possibilidade, ou seja, daquela linha temporária recebida para validar se sua resposta bate com a dada na entrada padrão.

    char *token = strtok (linha, " "); //uso do método do strtok para tokenizar a linha temporária que recebi. inicio aqui para fazer a primeira leitura da linha temporária dada e separar o token assim que chegar no " ".
    while(token != NULL){ //enquanto o token não for nulo, ou seja, não tiver chegado no fim da leitura da linha temporária.
        if(token[0] == '*' || token[0] == '+'){ //caso o token seja um dos operadores, desempilharei os últimos dois números da pilha, farei a soma e colocarei novamente nela.
            int n1 = desempilhaElemento(numeros);
            int n2 = desempilhaElemento(numeros);
            if (token[0] == '*'){
                empilhaElemento(n1*n2, numeros);
            } else {
                empilhaElemento (n1+n2, numeros);
            }
        }
        else{
            empilhaElemento(atoi(token), numeros); //caso a leitura do token seja um token que não é * ou +, e não seja NULL (primeira condição, a do while), este token será convertido em inteiro e colocado na pilha.
        }
        token = strtok(NULL, " "); //após a decisão sob o token, andaremos para o próximo token.
    }

    resultadoPossibilidades = desempilhaElemento(numeros); //após toda operação, teremos somente um número final na pilha, que corresponde ao número final da operação dada na linha temporária.
    if(resultadoPossibilidades == resultado){ //caso o resultado desta dada possibilidade bata com o resultado esperado dado na entrada padrão, retorno 1 (true). caso contrário, retorno 0 (falso)
        return 1;
    }
    return 0;
}

void imprimeSinais(int mascaraBits[], int tamanho){ //recebo a máscara de bits e o número de "?", ou seja, tamanho da máscara.
    int j = 0; //farei uma iteração até o tamanho final da mascara de bits para printar os sinais.
    while(j != tamanho){ //a cada posição, vejo qual o valor 0 ou 1 está apresentado. seguindo isso, printo o + ou *, dependendo do número apresentado que ele representa.
        if(mascaraBits[j] == 1){
            printf("*");
        } else{
            printf("+");
        }
        j++;
    }
    printf("\n");
}

void possibilidades(int numeroDuvidinha, char linha [], int resultado){

    int i, k, cont; //cont é um contador que irá servir de índice na transformação de um número em uma máscara de bits.
    int  numeroPossibilidades; //numero das opções de possibilidades existentes para o problema.
    int mascaraBits[numeroDuvidinha]; //vetor de inteiros que tem o tamanho do número de "?" da linha, iremos fazer a máscara de bit nele.
    char linhaTemp[201]; //linha cópia de "linha", uma vez que não quero alterar ou mexer nela.
    int kbits; //índice para percorrer o vetor da máscara de bits. nome se dá ao iterador "k" que percorre os "bits" da máscara.


    for(i = 0; i < pow(2,numeroDuvidinha); i++){ //este "for" percorre todas as possibilidades possíveis da máscara de bits, ou seja, 2^n, no caso, 2 elevado ao número de "?". é quantas vezes refarei a máscara de bits.
        numeroPossibilidades = i; //para não mexermos no "i" e atrapalhar o for, uso esta variável para guardar a possibilidade que estamos.
        cont = numeroDuvidinha - 1; //recebe o número de "?" diminuido de 1, já que ele é um contador que inicia do 0.
        k = 0, kbits = 0; //iteradores inicializados.

        while(cont >= 0){ // monta a máscara, baseado em qual possibilidade está (em binario). ex: possibilidade 14, vai ter o 14 em binário.
        //aqui dentro, converto o número dado em binário por meio do % e /. Começo da direita pra esquerda, já que é como posicionamos os números para criar em bits. por isso começo com o cont no final.
            mascaraBits[cont] = numeroPossibilidades % 2; //0 ou 1. uso a variável que é a copia de "i", já que "i" é o número de 0 até o número total de possibilidades que temos. nesta proposta, quero transformar cada um dos números de possibilidades em número binário, assim terei todas as variações possíveis! transformo o 0 em binário, 1 em binário, etc.
            numeroPossibilidades = numeroPossibilidades/2; //levo pra próxima casa.
            cont--; //ando a casa. o cont mostra em qual casa da mascara de bits tou, posicao no vetor (de trás pra frente, já que começamos no "numeroduvidinha-1").
        }

        while(linha[k] != '\0'){ //aqui, a máscara de bits será "revelada" na linha, ou seja, a linhaTemp (que será a cópia da linha, porém com + e *) receberá a máscara em formato convertido de + e *.
            if(linha[k] == '?'){ //encontrando "?" na linha, conferirei na minha máscara (agora da esquerda para a direita) qual o operador que deverá ali estar. sendo 0 o + e 1 o *.
                if(mascaraBits[kbits] == 0){
                    linhaTemp[k] = '+'; //aqui, coloco na linhaTemp a cópia da linha, porém recebendo o sinal + seguindo a máscara. (0)
                    kbits++; //ando no vetor de inteiros que corresponde à máscara de bits para pegar o próximo 0 ou 1 (que será o próximo "?" em * ou +, quando encontrado).
                }
                else{
                    linhaTemp[k] = '*'; //aqui, coloco na linhaTemp a cópia da linha, porém recebendo o sinal * seguindo a máscara. (1)
                    kbits++; //ando no vetor de inteiros que corresponde à máscara de bits para pegar o próximo 0 ou 1 (que será o próximo "?" em * ou +, quando encontrado).
                }
            } else {
                linhaTemp[k] = linha[k]; //caso não seja "?", copiarei para a linhaTemp a parte da linha que falta, independentemente do que for.
            }
            k++;
        }
        linhaTemp[k] = '\0'; //ultimo caractere adicionado na linha temporária, cópia da linha original.

        if(validacao(linhaTemp,resultado) == 1){ //aqui, chamo a função validação para a linha temporária que criei, que já possui os sinais + e - em si, e envio também o resultado esperado para aquela linha. o retorno será um int que, sendo true, irá imprimir a máscara de bits correspondendo aos sinais colocados naquela linha temporária!
            imprimeSinais(mascaraBits, numeroDuvidinha); //envio a máscara e o número de "?" para fazer um iterador e imprimir na saída padrão.
        }
    }
}
