/* ================================================================== *
   Dados do aluno:

   RA: 743585
   Nome: Pedro de Souza Vieira Coelho

* ================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Opcoes ***********************
#define SAIR               0
#define INSERIR            1
#define PROCURAR 	       2
#define PROCURAR_NOME      3
#define POSICAO            4
#define REMOVER            5
#define IMPRIMIR           6

//implementacao da struct utilizada
typedef struct _no{
    int ra;
    char nome[201];
    int ano;
    struct _no *anterior;
    struct _no *proximo;
}no;
//////////////////////////////////////

//prototipo das funcoes implementadas:
void libera(no *primeiro);
void inserir(no **primeiro, int ra, char *nome, int ano);
void procurar(no *primeiro, int ra);
void procurarnome(no *primeiro, char *nome);
int posicao(no *primeiro, int ra);
void remover(no **primeiro, int ra);
void imprimir(no *primeiro);
//////////////////////////////////////

int main(){
    int opcao, ra, ano;
    char nome[201];
    no *primeiro = NULL;

    while(opcao != 0){
        scanf("%d", &opcao);

        switch(opcao){
            case INSERIR:
                scanf("%d", &ra);
                scanf("\n%[^\n]s", nome);
                //talvez utilizar um gets aqui
                scanf("%d", &ano);
                inserir(&primeiro, ra, nome, ano);
            break;

            case PROCURAR:
                 scanf("%d", &ra);
                 procurar(primeiro, ra);
            break;

            case PROCURAR_NOME:
                 scanf("\n%[^\n]s", nome);
                 //talvez utilisar um gets aqui
                 procurarnome(primeiro, nome);
            break;
            
            case POSICAO:
                scanf("%d", &ra);
                int x = 0;
                x = posicao(primeiro, ra);
                if(x == 0){
                    printf("INEXISTENTE\n");
                }else{
                    printf("%d\n", x);
                }
            break;

            case REMOVER:
                scanf("%d", &ra);
                remover(&primeiro, ra);
            break;

            case IMPRIMIR:
                imprimir(primeiro);
            break;

            case SAIR:
                libera(primeiro);
            break;
        }
    }

    return 0;
}
//insere os elementos na lista de maneira ja ordenada segundo o ra
void inserir(no **primeiro, int ra, char *nome, int ano){
    int flag = 0, k = 0;
    
    no *p = (no*)calloc(1,sizeof(no));
    p->ra = ra;
    strcpy(p->nome, nome);
    p->ano = ano;
    p->anterior = NULL;
    p->proximo = NULL;
    no *verifica = *primeiro;

    while(verifica != NULL){ //verificaçao se o primeiro é igual ao ra inserido
        if(verifica->ra == ra){
            printf("REPETIDO\n");
            return;
        }
        verifica = verifica->proximo;
    }
    if(*primeiro == NULL){
        //printf("primeiro == NULL\n");
        *primeiro = p;
    }else{
        no *pp = *primeiro;
        no *aux = pp->proximo;
        // verificacao caso o RA inserido seja menor que o primeiro
        if(pp->ra > ra){
            p->anterior = NULL; 
            p->proximo = pp;
            pp->anterior = p;
            *primeiro = p;
        }else{
            // verificacao caso o RA inserido nao seja menor que o primeiro
            while(aux!=NULL){
                if(aux->ra > ra){
                    p->anterior = aux->anterior;
                    aux->anterior->proximo = p;
                    p->proximo = aux;
                    aux->anterior = p;
                    flag = 1;
                    return;
                }
                aux = aux->proximo;
                pp = pp->proximo;
            }if(flag == 0){
                //printf("Ultimo if\n");
                p->anterior = pp;
                pp->proximo = p;
            }
        }
    }

}
//imprime todos os elementos da lista
void imprimir(no *primeiro){
    no *aux = primeiro;

    while(aux){
        if(aux != NULL){
            printf("%d ", aux->ra);
        }
        aux = aux->proximo;
    }
    printf("\n");

}
//imprime o ano e o nome do aluno desejado, usando como procura seu RA
void procurar(no *primeiro, int ra){
    no *aux = primeiro;
    int flag = 0;

    while(aux){
        if(aux->ra == ra){
            int i = 0;
            while(aux->nome[i] != '\0'){
                printf("%c", aux->nome[i]);
                i++;
                flag =1 ;
            }
            printf(" %d\n", aux->ano);
        }
        aux = aux->proximo;
    }
    if(flag == 0){
        printf("INEXISTENTE\n");
    }
}
//procura e imprime os RAs desejados utilizando o nome como busca
void procurarnome(no *primeiro, char *nome){
    no *aux = primeiro;
    int flag = 0, flag2 = 0;

//verificacao caso a lista seja nula
    
    while(aux != NULL){
        if(strcmp(nome,aux->nome) == 0){
            if(!flag2){
                printf("%d", aux->ra);
                flag = 1;
                flag2 = 1;
            }else{
                printf(" %d", aux->ra);
            }
        }
        aux = aux->proximo;
    }
    if(flag == 0){
        printf("INEXISTENTE");
    }
    printf("\n");
}
//encontra a posicao do aluno na lista, utilizando como busca seu RA
int posicao(no *primeiro, int ra){
    no *aux = primeiro;
    int posicao = 0;
    
    while(aux){
        if(aux->ra == ra){
            posicao++;
            return posicao;
        }else{
            posicao++;
        }
        aux = aux->proximo;
    }
}

void remover(no **primeiro, int ra){
    no *aux = *primeiro;

    //verificacao caso a lista seja nula
    if(aux == NULL){
        return;
    }else{
         no *p = aux->proximo;
        while(aux != NULL){
            if(aux->ra == ra){
                //mantendo a lista ligada e removendo o termo desejado
                //caso o termo desejado esteja no meio da lista
                if(aux->anterior != NULL && aux->proximo != NULL){
                    aux->anterior->proximo = aux->proximo;
                    aux->proximo->anterior = aux->anterior;
                    free(aux);
                    return;
                //caso o termo desejado seja o primeiro da lista
                }else if(aux->anterior == NULL && aux->proximo != NULL){
                    *primeiro = aux->proximo;
                    aux->proximo->anterior = NULL;
                    free(aux);
                    return;
                //caso o termo desejado seja o ultimo termo da lista    
                }else if(aux->anterior != NULL && aux->proximo == NULL){
                    aux->anterior->proximo = NULL;
                    free(aux);
                    return; 
                }
                //caso a lista tenha apenas um único termo
                else{
                    *primeiro = NULL;
                    free(aux);
                    return;
                }
            }
            aux = aux->proximo;
        }
    }
}
//remove todos os elementos da lista
void libera(no *primeiro){
    no *aux = primeiro;
    while(aux){
		no *pp = aux->proximo;
		free(aux);
		aux = pp;  
    }       
}