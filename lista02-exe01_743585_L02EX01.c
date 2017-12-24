/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 01 - Coeficiente Binomial

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

#include <stdio.h>

double fatorial(double n);

int main(){

    double n, k;

    scanf("%lf %lf", &n, &k);

    printf("%0.0lf\n", fatorial(n) / (fatorial(k) * fatorial(n - k)));

    return 0;
}

double fatorial(double n){

    if(n == 0){
        return 1;
    }else{
        return n * fatorial(n - 1);
    }
}
