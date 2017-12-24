/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Algoritmos e Programação 2

	Lista 02 - Exercício 03 - Conversao Binaria

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

int converter(int n);

#include <stdio.h>

int main(){

	int n;

	scanf("%d", &n);

	if(n == 0){
		printf("%d", n);
	}
	
	converter(n);

	return 0;
}

int converter(int n){
	if(n == 0){
		return 0;
	}else{
		converter(n / 2);
		printf("%d", n % 2);
	}


}
