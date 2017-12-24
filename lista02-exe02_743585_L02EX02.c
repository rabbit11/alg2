/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 02 - Conjectura de Collatz

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA: 743585
	Nome: Pedro de Souza Vieira Coelho

* ================================================================== */

/* <<< ESCREVA SEU CODIGO AQUI >>> */

unsigned long collatz(unsigned long n);

#include <stdio.h>

int main(){

    unsigned long n;

    scanf("%lu", &n);

    printf("%lu ", n);

    printf("%lu ", collatz(n));

    return 0;
}

unsigned long collatz(unsigned long n){

    if(n / 2 == 1){
        return 1;
    }
    else if(n % 2 == 0){
        printf("%lu ", n / 2);

        return collatz(n / 2);
    }else{
        printf("%lu ", 3 * n + 1);

        return collatz(3 * n + 1);
    }

}
