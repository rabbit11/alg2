/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 04 - Recursao em Matrizes

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA: 743585
	Nome: Pedro de Souza Vieira Coelho

* ================================================================== */

#include <stdio.h>

#define MAX 100

#define OPCAO_OBTER_MENOR   1
#define OPCAO_OBTER_MAIOR   2
#define OPCAO_OBTER_SOMA    3
#define OPCAO_NOVA_MATRIZ   4
#define OPCAO_SAIR          5

int m, n;
int matriz[MAX][MAX];

int obter_menor(int i);
int obter_maior(int i);
int obter_soma(int i);

int main() {
    int i, j, opcao, nova_matriz;

    while (scanf("%d %d", &m, &n) > 0 && m > 0 && n > 0) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j)
                scanf("%d", &matriz[i][j]);
        }

        nova_matriz = 0;
        while (!nova_matriz && scanf("%d", &opcao) > 0) {
            switch(opcao) {
            case OPCAO_OBTER_MENOR:
                printf("%d\n", obter_menor(0));
                break;
            case OPCAO_OBTER_MAIOR:
                printf("%d\n", obter_maior(0));
                break;
            case OPCAO_OBTER_SOMA:
                printf("%d\n", obter_soma(0));
                break;
            case OPCAO_NOVA_MATRIZ:
                nova_matriz = 1;
                break;
            case OPCAO_SAIR:
                return 0;
            }
        }
    }

    return (0);
}

int obter_menor(int i) {

    /*         IMPLEMENTE AQUI        */
    if(i == (n * m) - 1){
        return matriz[i/m][i%m];
    }
    else{
        int menor = obter_menor(i + 1);
        if(menor < matriz[i/m][i%m]){
            return menor;
        }else{
            return matriz[i/m][i%m];
        }
    }

    /* Esta funcao deve ser recursiva */

}

int obter_maior(int i) {

    /*         IMPLEMENTE AQUI        */
    if(i == (n * m) - 1){
        return matriz[i/m][i%m];
    }
    else{
        int maior = obter_maior(i + 1);
        if(maior > matriz[i/m][i%m]){
            return maior;
        }else{
            return matriz[i/m][i%m];
        }
    }
    /* Esta funcao deve ser recursiva */

}

int obter_soma(int i) {

    /*         IMPLEMENTE AQUI        */
    if(i == (n * m) - 1){
        return matriz[i/m][i%m];
    }
    else{
        return matriz[i/m][i%m] + obter_soma(i + 1);
    }
    /* Esta funcao deve ser recursiva */

}
