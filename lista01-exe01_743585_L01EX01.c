/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Lista 01 - Exercício 01 - Caça-palavras

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
#include <string.h>


/* máximo de linhas (m) e colunas (n) */
#define MAX 10

/* constantes booleanas */
#define VERDADEIRO	1
#define FALSO		0


/* Protótipos das funções */
void lerGrade(char grade[][MAX], int m, int n);
void imprimirGrade(char grade[][MAX], int m, int n);
/* <<< ESCREVA OS PROTOTIPOS DAS DEMAIS FUNCOES AQUI >>> */
int procurarHorizontal(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n);
int procurarVertical(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n);
int procurarDPrincipal(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n);
int procurarDSecundaria(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n);
void esconderMarcas(char grade[][MAX], int marcas[][MAX], int m, int n);
void inverterString(char* palavra);
/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */

int main(void)
{
	char grade[MAX][MAX]; 	/* matriz de letras do caça-palavras */
	int marcas[MAX][MAX]; 	/* cada posição vale 1 se é para esconder a letra na resposta, ou 0 caso contrário */
	int num_palavras;		/* qtde de palavras que usuário deseja procurar na grade */
	char palavra[MAX];		/* palavra que o usuário deseja buscar */
	int m, n;				/* dimensões da grade de letras */
	int i, j;				/* iteradores para percorrer linhas e colunas */
	int achou;				/* variavel que indica se palavra foi encontrada na grade (achou=1) ou não (achou=0)*/


	/* lê dimensão e a grade */
	scanf("%d %d", &m, &n);
	lerGrade(grade, m, n);


	/* marca todas as posições da grade como fora da resposta final */
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			marcas[i][j] = 1;
		}
	}


	/* lê número de palavras e procura cada uma delas na grade */
	scanf("%d", &num_palavras);

	/* para cada palavra desejada */
	for(i = 0; i < num_palavras; i++) {
		scanf("%s", palavra); // le a palavra desejada

		// procura em todas as linhas da grade
		achou = procurarHorizontal(palavra, grade, marcas, m, n);

		if (achou == FALSO) {

			// procura em todas as colunas da grade
			achou = procurarVertical(palavra, grade, marcas, m, n);

			if (achou == FALSO) {

				// procura na diagonal principal
				achou = procurarDPrincipal(palavra, grade, marcas, m, n);

				if (achou == FALSO) {

					// procura na diagonal secundária
					achou = procurarDSecundaria(palavra, grade, marcas, m, n);
					if (achou == FALSO) {

						// Inverte a palavra e reinicias as buscas
						inverterString(palavra);

						// procura em todas as linhas da grade
						achou = procurarHorizontal(palavra, grade, marcas, m, n);

						if (achou == FALSO)	{

							// procura em todas as colunas da grade
							achou = procurarVertical(palavra, grade, marcas, m, n);

							if (achou == FALSO) {

								// procura na diagonal principal
								achou = procurarDPrincipal(palavra, grade, marcas, m, n);

								if (achou == FALSO) {

									// procura na diagonal secundária
									achou = procurarDSecundaria(palavra, grade, marcas, m, n);
								}
							}
						}
					}
				}
			}
		}
	}

	// coloca '#' na grade no lugar de letras não usadas
	esconderMarcas(grade, marcas, m, n);

	// imprime a grade final
	imprimirGrade(grade, m, n);

	return 0;
}


/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

/* lerGrade: preenche grade lendo do teclado cada caractere */
void lerGrade(char grade[][MAX], int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)	{
		for (j = 0; j < n; j++) {
			do {
				scanf("%c", &grade[i][j]);
			/* ignora espaços e quebras de linha */
			} while (grade[i][j] == ' ' || grade[i][j] == '\n');
		}
	}
}


/* imprimirGrade: imprime a grade de caracteres */
void imprimirGrade(char grade[][MAX], int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++) {
	 	for (j = 0; j < n; j++) {
			printf("%c ", grade[i][j]);
		}
		printf("\n");
	}
}

/* <<< IMPLEMENTE AS DEMAIS FUNCOES AQUI >>> */

/* inverterString: inverte a ordem da string, p. ex, troca "AMOR" por "ROMA" */
void inverterString(char* palavra){

	char temp;
	int i = 0, j = 0;

	while(palavra[i] != '\0'){
		i++;
	}int k = i - 1;
	for(j = 0; j < i / 2; j++){
		temp = palavra[j];
		palavra[j] = palavra[k];
		palavra[k] = temp;
		k--;
	}
}

/* procurarHorizontal: procura a palavra nas linhas da grade. Remove as marcas, se a palavra for
encontrada e retorna VERDADEIRO ou FALSO se a palavra foi encontrada ou nao */
int procurarHorizontal(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n){
	int i, j, achou = 0, contador = 0, k = 0, length = 0, l = 0;

	while(palavra[length] != '\0'){
		length++;
	}
	for(i = 0; i < m; i++){
		k = 0;
		contador = 0;
		for(j = 0; j < n; j++){
			if(grade[i][j] == palavra[k]){
				contador++;
				k++;
				if(contador == length){
					achou = 1;
					l = j - length + 1;
					while(l <= j){
						marcas[i][l] = 0;
						l++;
					}
					return 1;
				}
			}else{
				k = 0;
				contador = 0;
				if(grade[i][j] == palavra[k]){
					contador++;
					k++;
					if(contador == length){
						achou = 1;
						l = j - length + 1;
						while(l <= j){
							marcas[i][l] = 0;
							l++;
						}
						return 1;
					}
				}
			}
		}
	}


	if(achou == 0){
		return 0;
	}else{
		return 1;
	}
}

/* procurarVertical: procura a palavra nas colunas da grade. Remove as marcas, se a palavra for
encontrada e retorna VERDADEIRO ou FALSO se a palavra foi encontrada ou nao */
int procurarVertical(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n){
	 int i, j, achou = 0, contador = 0, k = 0, length = 0, l = 0;

	 while(palavra[length] != '\0'){
		 length++;
	 }
	 for(j = 0; j < m; j++){
		 k = 0;
		 contador = 0;
		 for(i = 0; i < n; i++){
			 if(grade[i][j] == palavra[k]){
				 contador++;
				 k++;
				 if(contador == length){
					 achou = 1;
					 l = i - length + 1;
 					while(l <= i){
 						marcas[l][j] = 0;
 						l++;
 					}
 					return 1;
 				}
 			}else{
 				k = 0;
 				contador = 0;
 				if(grade[i][j] == palavra[k]){
 					contador++;
 					k++;
 					if(contador == length){
 						achou = 1;
 						l = i - length + 1;
 						while(l <= i){
 							marcas[l][j] = 0;
 							l++;
 						}
 						return 1;
 					}
 				}
 			}
		}
	}

	 if(achou == 0){
		 return 0;
	 }else{
		 return 1;
	 }
 }

/* procurarDPrincipal: procura a palavra na diagonal principal da grade. Remove as marcas, se a palavra for
encontrada e retorna VERDADEIRO ou FALSO se a palavra foi encontrada ou nao */
int procurarDPrincipal(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n){
	int i, j = 0, achou = 0, contador = 0, k = 0, length = 0, l = 0, c = 0;

	while(palavra[length] != '\0'){
		length++;
	}
	for(i = 0; i < m; i++, j++){
		if(grade[i][j] == palavra[k]){
			contador++;
			k++;
			if(contador == length){
				achou = 1;
				l = j - length + 1;
				//c = i - length + 1;

				while(l <= j){
					marcas[l][l] = 0;
					l++;
					//c++;
				}
				return 1;
			}
		}else{
			k = 0;
			contador = 0;
			if(contador == length){
				achou = 1;
				l = j - length + 1;
			//	c = i - length + 1;

				while(l <= j){
					marcas[l][l] = 0;
					l++;
					//c++;

				}
				return 1;
			}
		}
	}if(achou == 0){
		return 0;
	}else{
		return 1;
	}

}

/* procurarDSecundaria: procura a palavra na diagonal secundaria da grade. Remove as marcas, se a palavra for
encontrada e retorna VERDADEIRO ou FALSO se a palavra foi encontrada ou nao */
int procurarDSecundaria(char* palavra, char grade[][MAX], int marcas[][MAX], int m, int n){
	int i, j = n, achou = 0, contador = 0, k = 0, length = 0, l = 0, c = 0;

	while(palavra[length] != '\0'){
		length++;
	}
	for(i = 0; i > 0; i++, j--){
		if(grade[i][j] == palavra[k]){
			contador++;
			k++;

			if(contador == length){
				achou = 1;
				l = length;
				c = i - length + 1;

				while(l >= 0){
					marcas[c][l] = 0;
					c++;
					l--;
				}
				return 1;
			}
		}else{
			k = 0;
			contador = 0;

			if(contador == length){
				achou = 1;
				l = length;
				c = i - length + 1;

				while(l >= 0){
					marcas[c][l] = 0;
					c++;
					l--;
				}
				return 1;
			}
		}

	}if(achou == 0){
		return 0;
	}else{
		return 1;
	}
}

/* esconderMarcas: substitui caracteres da grade por '#' onde estiver marcado */
void esconderMarcas(char grade[][MAX], int marcas[][MAX], int m, int n){
	int i, j;

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(marcas[i][j] == 1){
				grade[i][j] = '#';
			}
		}
	}
}
