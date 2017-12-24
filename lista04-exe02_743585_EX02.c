#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int num;
    struct _no *proximo;
}no;

typedef struct{
    no *primeiro;
}lista;

void inicializa(lista *x);
void libera(lista *x);
void inserir(int valor, lista *x);
int procura(int valor, lista*x);
void remover(int valor, lista *x);
void imprimir(lista *x);

int main(){
    int opcao, i = 0, j = 0;
    lista x;
    
    inicializa(&x);
    
    scanf("%d", &opcao);

    while(opcao != 0){
        //scanf("%d", &opcao);
        if(opcao == 1){
            inserir(0, &x);
        }else if(opcao == 2){
            i = procura(0, &x);
            printf("%d\n", i);
        }else if(opcao == 3){
             remover(0, &x);
        }else if(opcao == 4){
             imprimir(&x);
             
             printf("\n");
         }
         scanf("%d", &opcao);
    }if(opcao == 0){
        libera(&x);    
    }
    return 0;
}
void inicializa(lista *x){
    x->primeiro = NULL;
}
void libera(lista *x){
    no *p = x->primeiro;
    if(p == NULL){
        return;
    }
    no *pp = p->proximo;
    while(p!=NULL){
        pp = p->proximo;
        free(p);
        p = pp;
    }
    x->primeiro = NULL;
}
void inserir(int valor, lista *x){
    int flag = 0, quantidade = 0;
    scanf("%d", &valor);
    
    no *p = (no*)calloc(1,sizeof(no));
    p->num = valor;
    p->proximo = NULL;
    no *verifica = x->primeiro;
    while(verifica != NULL){
        if(verifica->num == valor){
            return;
        }
        verifica = verifica->proximo;
    }
    
    if(x->primeiro == NULL){
        //printf("primeiro == NULL\n");
        x->primeiro = p;
    }else{
        no *pp = x->primeiro;
        no *auxiliar = pp->proximo;
        if(pp->num > valor){
            p->proximo = pp;
            x->primeiro = p;
        }else{
            while(auxiliar!=NULL){
                if(auxiliar->num > valor){
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
int procura(int valor, lista*x){
    int i = 0, flag = 0;

    scanf("%d", &valor);

    no *pp = x->primeiro;
    while(pp!= NULL){ // ou pp->proximo != NULL?
        if(pp->num == valor){
            return i;
        }
        pp = pp->proximo;
        i++;
    }
    return -1;
}
void remover(int valor, lista *x){
    scanf("%d", &valor);

    no *p = x->primeiro;
    if(p == NULL){
        return;
    }
    no *pp = p->proximo;
    
    if(p->num == valor){
        x->primeiro = p->proximo;
        free(p);
    }
    else{
        while(pp!= NULL){
            if(pp->num == valor){
                p->proximo = pp->proximo;
                free(pp);
            }
            pp = pp->proximo;
            p = p->proximo;
        }
    }
}
void imprimir(lista *x){
    no *p = x->primeiro;
    
    while(p!=NULL){
        printf("%d ", p->num);
        p = p->proximo;
    }
}

