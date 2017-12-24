/* ================================================================== *
   Universidade Federal de Sao Carlos - UFSCar, Sorocaba

   Disciplina: Algoritmos e Programação 2

   Lista 04 - Exercício 01 - Polinomio

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
#include <math.h>

// Opcoes ***********************
#define SAIR               0
#define ADICIONAR_POLI     1
#define REMOVER_POLI	   2
#define SOMAR_POLI         3
#define SUBTRAIR_POLI      4
#define MULTIPLICAR_POLI   5
#define CALCULAR_POLI      6

// declaracoes de registros
/* <<< DEFINA OS REGISTROS AQUI >>> */
typedef struct _no{
   // int poli;
    int coef;
    int exp;
    struct _no *proximo;
}Polinomio;

// declaracoes das funcoes
/* <<< DECLARE OS PROTOTIPOS DAS FUNCOES AQUI >>> */
void adicionarPolinomio(Polinomio **pri, int coef, int exp);
int calcularPolinomio(Polinomio *pri, int x);
void removerPolinomio(Polinomio **pri, int exp);
void libera(Polinomio* resultado);
Polinomio* somarPolinomios(Polinomio *p1, Polinomio *p2);
Polinomio* subtrairPolinomios(Polinomio* pri1, Polinomio* pri2);
Polinomio* multiplicarPolinomios(Polinomio* pri1, Polinomio* pri2);
// void imprimir(Polinomio **pri);
/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */
int main() {

   int x, coef, exp, poliEscolhido, operando1, operando2;
   Polinomio *p1 = NULL;
   Polinomio *p2 = NULL;
   Polinomio *resultado = NULL;

   scanf("%d",&x);

   int opcao = 1;
   while(opcao != 0){
      scanf("%d",&opcao);
      switch(opcao){

         case ADICIONAR_POLI:
            scanf("%d %d %d", &poliEscolhido, &coef, &exp);
            poliEscolhido == 1 ? adicionarPolinomio(&p1,coef,exp) : adicionarPolinomio(&p2,coef,exp);
         break;

         case REMOVER_POLI:
            scanf("%d %d", &poliEscolhido, &exp);
            poliEscolhido == 1 ? removerPolinomio(&p1,exp) : removerPolinomio(&p2,exp);
         break;

         case SOMAR_POLI:
            if(resultado != NULL) libera(resultado);
            resultado = somarPolinomios(p1,p2);
         break;

         case SUBTRAIR_POLI:
            scanf("%d %d", &operando1, &operando2);
            if(resultado != NULL) libera(resultado);
            resultado = subtrairPolinomios(operando1 == 1 ? p1 : p2, operando2 == 2 ? p2 : p1);
         break;

         case MULTIPLICAR_POLI:
            if(resultado != NULL) libera(resultado);
            resultado = multiplicarPolinomios(p1,p2);
         break;

         case CALCULAR_POLI:
            scanf("%d",&poliEscolhido);
            switch(poliEscolhido) {
               case 1: printf("%d\n",calcularPolinomio(p1,x)); break;
               case 2: printf("%d\n",calcularPolinomio(p2,x)); break;
               case 3: printf("%d\n",calcularPolinomio(resultado,x)); break;
            }
         break;

      }
   }

   return (0);

}

/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

/* <<< IMPLEMENTE AS FUNCOES AQUI >>> */
void adicionarPolinomio(Polinomio **pri, int coef, int exp){
    int flag = 0, quantidade = 0;
    
    Polinomio *p = (Polinomio*)calloc(1,sizeof(Polinomio));
    p->coef = coef;
    p->exp = exp;
    p->proximo = NULL;
    Polinomio *verifica = *pri;
    while(verifica != NULL){
        //caso os expoentes sejam iguais devemos somar os coeficientes.
        if(verifica->exp == exp){
            verifica->coef += coef;
            return;
           // printf("passou aqui %d \n", verifica->coef);
        }
        verifica = verifica->proximo;
    }
    if(*pri == NULL){
        *pri = p;
    }else{
        Polinomio *pp = *pri;
        Polinomio *auxiliar = pp->proximo;
        //caso o exp inserido seja menor que o primeiro expoente da lista:
        if(pp->exp > exp){
            p->proximo = pp;
            *pri = p;
        }else{
            while(auxiliar!=NULL){
                if(auxiliar->exp > exp){
                    pp->proximo = p;
                    p->proximo = auxiliar;
                    flag = 1;
                    return;
                }
                auxiliar = auxiliar->proximo;
                pp = pp->proximo;
            }if(flag == 0){
                //printf("Ultimo if\n");
                pp->proximo = p;
            }
        }
    }
}

int calcularPolinomio(Polinomio *pri, int x){
    int saida = 0;
    Polinomio *aux = pri;
    
    while(aux != NULL){
       // printf("%d\n ", saida);
        saida += pow(x, aux->exp) * aux->coef;
        aux = aux->proximo;
    }
    return saida;
}

void removerPolinomio(Polinomio **pri, int exp){
    Polinomio *p = *pri;
    //caso o primeiro da lista seja nula, a lista e nula portanto nao ha termos a serem removidos
    if(p == NULL){
        return;
    }
    Polinomio *pp = p->proximo;
    //caso o primeiro elemento da lista seja o que procuramos:
    if(p->exp == exp){
        *pri = p->proximo;
        free(p);
    }
    else{
        //busca pelo elemento que queremos remover
        while(pp!= NULL && p!=NULL){
            if(pp->exp == exp){
                p->proximo = pp->proximo;
                free(pp);
            }
            pp = pp->proximo;
            p = p->proximo;
        }
    }
}
void libera(Polinomio *resultado){
    Polinomio *p = resultado;
    Polinomio *aux = p->proximo;
    
    while(aux != NULL){
        aux = aux->proximo;
        free(p);
        p = aux;
    }
}

Polinomio* somarPolinomios(Polinomio *pri1, Polinomio *pri2){
    Polinomio *p = pri1;
    Polinomio *pp = pri2;
    Polinomio *p3 = (Polinomio*)calloc(1,sizeof(Polinomio));
    p3->proximo = NULL;
    Polinomio *resultado;
    resultado = NULL;
   //podemos reciclar a funcao de adicionar polinomios criada anteriormente desde que todos os casos 
   //tenham sido tratados.
    while(p!= NULL){
        adicionarPolinomio(&resultado, p->coef, p->exp);
        p = p->proximo;
    }while(pp!= NULL){
        adicionarPolinomio(&resultado, pp->coef, pp->exp);
        pp = pp->proximo;
    }
    return resultado;
}

Polinomio* subtrairPolinomios(Polinomio* pri1, Polinomio* pri2){
    Polinomio *p = pri1;
    Polinomio *pp = pri2;
    Polinomio *p3 = (Polinomio*)calloc(1,sizeof(Polinomio));
    p3->proximo = NULL;
    Polinomio *resultado;
    resultado = NULL;
    //podemos assim reutilizar o mesmo principio utilizado na funcao de soma, apenas multiplicando o
    //coeficiente da segunda funcao por -1 para que seja efetuada a subtracao.
    while(p!= NULL){
        adicionarPolinomio(&resultado, p->coef, p->exp);
        p = p->proximo;
    }while(pp!= NULL){
        adicionarPolinomio(&resultado, -1 * pp->coef, pp->exp);
        pp = pp->proximo;
    }
    return resultado;
}
Polinomio* multiplicarPolinomios(Polinomio* pri1, Polinomio* pri2){
    Polinomio *p = pri1;
    Polinomio *pp = pri2;
    Polinomio *p3 = (Polinomio*)calloc(1,sizeof(Polinomio));
    p3->proximo = NULL;
    Polinomio *resultado;
    resultado = NULL;

    while(p!= NULL){
        pp = pri2; //reset necessario para que a multiplicacao seja efetuada em todos os termos do segundo polinomio pelo primeiro,
            while(pp!= NULL){
                adicionarPolinomio(&resultado, p->coef * pp->coef, p->exp + pp->exp);
                pp = pp->proximo;
            }
        p = p->proximo;
    }

    return resultado;
}
// void imprimir( Polinomio** pri ) {
// 	Polinomio *p = *pri;
// 	while( p ) {
// 		printf("%d %d \n", p->coef, p->exp);
// 		p = p->proximo;
// 	}
// }