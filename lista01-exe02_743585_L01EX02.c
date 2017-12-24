/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Lista 01 - Exercício 02 - Cadastro de alunos

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
#include <stdlib.h>
#include <string.h>

// menu de opcoes
#define INSERIR 			1
#define ALTERAR 			2
#define REMOVER 			3
#define BUSCAR 				4
#define LISTAR				5
#define LISTARPORNOME		6
#define SAIR 				0

// frases pre-definidas para saida
#define FRASE_ALUNO_NAO_ENCONTRADO "Cadastro nao encontrado!\n"
#define FRASE_CADASTRO_CHEIO "O limite de alunos foi atingido!\n"
#define FRASE_CADASTRO_VAZIO "Nao ha nenhum aluno cadastrado!\n"
#define FRASE_JACADASTRADO "Aluno ja cadastrado!\n"

// Limitantes
#define TAM_NOME 1000	// tamamnho maximo do nome do aluno
#define MAX_ALUNOS 100 	// quantidade maxima de alunos


// Definicoes dos registros para armazenar dados de um aluno
/* <<< DEFINA OS REGISTROS AQUI >>> */
typedef struct data{
	int dia;
	int mes;
	int ano;
}data;

typedef struct aluno{
	int ra;
	char nome[100];
	int creditos;
	data dataIngresso;
}aluno;

//Declaracoes das funcoes
int inserir (aluno Alunos[], int qtAlunos, aluno novoAluno);
/* <<< ESCREVA OS PROTOTIPOS DAS DEMAIS FUNCOES AQUI >>> */
void listar (aluno Alunos[], int qtAlunos);
int alterar(aluno Alunos[], int qtAlunos, int ra);
int remover(aluno Alunos[], int qtAlunos, int ra);
int buscar(aluno Alunos[], int qtAlunos, int ra);
void listarPorNome(aluno Alunos[], int qtAlunos);

/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */
int main(){

	int opcao;
	int qtAlunos=0, indice, retorno;
	int ra;
	aluno Alunos[MAX_ALUNOS];
	aluno novoAluno;

	do {
		scanf("%d",&opcao);

		switch(opcao){

			case INSERIR:
				scanf("%d %d/%d/%d %d %[^\n]s", &(novoAluno.ra),
				&(novoAluno.dataIngresso.dia), &(novoAluno.dataIngresso.mes), &(novoAluno.dataIngresso.ano),
				&(novoAluno.creditos),(novoAluno.nome));

				retorno = inserir(Alunos, qtAlunos, novoAluno);
				if (retorno == 1)
					qtAlunos++;
				else if (retorno == -1)
					printf(FRASE_CADASTRO_CHEIO);
				else
					printf(FRASE_JACADASTRADO);

				break;


			case ALTERAR:
				scanf("%d",&ra);

				if (alterar(Alunos, qtAlunos, ra) == 0)
					printf(FRASE_ALUNO_NAO_ENCONTRADO);

				break;


			case REMOVER:
				scanf("%d",&ra);

				if (remover(Alunos, qtAlunos, ra))
					qtAlunos--;
				else
					printf(FRASE_ALUNO_NAO_ENCONTRADO);

				break;


			case BUSCAR:
				scanf("%d",&ra);

				indice = (buscar(Alunos, qtAlunos, ra));

				if (indice != -1){
					printf("%06d - ",Alunos[indice].ra);
					printf("%s - ",Alunos[indice].nome);
					printf("%02d/%02d/%04d - ",Alunos[indice].dataIngresso.dia, Alunos[indice].dataIngresso.mes, Alunos[indice].dataIngresso.ano);
					printf("%04d\n",Alunos[indice].creditos);
				} else
					printf(FRASE_ALUNO_NAO_ENCONTRADO);

				break;


			case LISTAR:

				if (qtAlunos > 0)
					listar(Alunos, qtAlunos);
				else
					printf(FRASE_CADASTRO_VAZIO);
				break;


			case LISTARPORNOME:

				if (qtAlunos > 0)
					listarPorNome(Alunos, qtAlunos);
				else
					printf(FRASE_CADASTRO_VAZIO);
				break;


		}
	} while(opcao != 0);


	return (0);

}

/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

// listar(): lista todos os registros em ordem crescente de RA
void listar (aluno Alunos[], int qtAlunos){
	int i = 0, j= 0;
	aluno temp;

	for(i = 0; i < qtAlunos; i++){
		for(j = 0; j < qtAlunos - i - 1; j++){
			if(Alunos[j].ra > Alunos[j + 1].ra){
				temp = Alunos[j];
				Alunos[j] = Alunos[j + 1];
				Alunos[j + 1] = temp;
			}
		}
	}
	for (i=0; i<qtAlunos; i++){
		printf("%06d - ",Alunos[i].ra);
		printf("%s - ",Alunos[i].nome);
		printf("%02d/%02d/%04d - ",Alunos[i].dataIngresso.dia, Alunos[i].dataIngresso.mes, Alunos[i].dataIngresso.ano);
		printf("%04d\n",Alunos[i].creditos);
	}
}

/* <<< IMPLEMENTE AS DEMAIS FUNCOES AQUI >>> */

// inserir(): retorna 1 se o cadastro foi efetuado com sucesso, -1 caso não haja espaço suficiente ou 0 caso
// o RA já esteja cadastrado
int inserir(aluno* Alunos, int qtAlunos, aluno novoAluno){
	int i = 0, j = 0, ans = 1;

	for(i = 0; i < qtAlunos; i++){
		if(novoAluno.ra == Alunos[i].ra){
			ans = 0;
		}
	}if(qtAlunos == MAX_ALUNOS){
		ans = -1;
	}else if(ans == 1){

		Alunos[qtAlunos].ra = novoAluno.ra;
		Alunos[qtAlunos].dataIngresso.dia = novoAluno.dataIngresso.dia;
		Alunos[qtAlunos].dataIngresso.mes = novoAluno.dataIngresso.mes;
		Alunos[qtAlunos].dataIngresso.ano = novoAluno.dataIngresso.ano;
		Alunos[qtAlunos].creditos = novoAluno.creditos;
		strcpy(Alunos[qtAlunos].nome, novoAluno.nome);
		qtAlunos++;
	}
	return ans;
}
// alterar(): retorna 1 se a alteracao foi efetuada com sucesso ou 0 caso não o registro não tenha sido encontrado
int alterar(aluno* Alunos, int qtAlunos, int ra){
	int i = 0, ans = 0;

	for(i = 0; i < qtAlunos; i++){
		if(ra == Alunos[i].ra){
			scanf("%d/%d/%d %d %[^\n]s", &Alunos[i].dataIngresso.dia, &Alunos[i].dataIngresso.mes,
			&Alunos[i].dataIngresso.ano, &Alunos[i].creditos, Alunos[i].nome);

			ans = 1;
		}
	}
	return ans;
}
// remover(): retorna 1 se a remocao foi efetuada com sucesso ou 0 caso não o registro não tenha sido encontrado
int remover(aluno* Alunos, int qtAlunos, int ra){
	int i = 0, ans = 0;

	for(i = 0; i < qtAlunos; i++){
		if(ra == Alunos[i].ra){
			for(i = 0; i < qtAlunos; i++){
				if(ra == Alunos[i].ra){
					aluno temp;
					temp = Alunos[qtAlunos - 1];
					Alunos[qtAlunos - 1] = Alunos[i];
					Alunos[i] = temp;
					ans = 1;
					return 1;
				}Alunos[qtAlunos].ra = 0;
				
			}
		}
	}
	return ans;
}
// buscar(): retorna o índice do registro caso ele tenha sido encontrado ou -1 caso contrario
int buscar(aluno* Alunos, int qtAlunos, int ra){
	int i = 0, ans = -1;

	for(i = 0; i < qtAlunos; i++){
		if(ra == Alunos[i].ra){
			ans = i;
		}
	}
	return ans;
}
// listarPorNome(): lista todos os registros em ordem alfabetica
void listarPorNome(aluno* Alunos, int qtAlunos){
	int i = 0, j = 0;
	aluno temp;

	for(i = 0; i < qtAlunos; i++){
		for(j = 0; j < qtAlunos - i - 1; j++){
			if(Alunos[j].nome[0] > Alunos[j + 1].nome[0]){
				temp = Alunos[j];
				Alunos[j] = Alunos[j + 1];
				Alunos[j + 1] = temp;
			}
		}
	}for(i = 0; i < qtAlunos; i++){
		printf("%06d - ",Alunos[i].ra);
		printf("%s - ",Alunos[i].nome);
		printf("%02d/%02d/%04d - ",Alunos[i].dataIngresso.dia, Alunos[i].dataIngresso.mes, Alunos[i].dataIngresso.ano);
		printf("%04d\n",Alunos[i].creditos);
	}
}
