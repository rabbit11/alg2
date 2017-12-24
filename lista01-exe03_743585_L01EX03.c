/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Lista 01 - Exercício 03 - Validacao de e-mails

	Instrucoes
	----------

	Este arquivo contem o codigo que auxiliara no desenvolvimento do
	exercicio. Voce precisara completar as partes requisitadas.

* ================================================================== *
	Dados do aluno:

	RA:743585
	Nome: Pedro de Souza Vieira Coelho

* ================================================================== */

#include <stdio.h>
#include <string.h>

int email_valido(char email[]);
int numeropos(char* email);
int simbconsecu(char* email);
int simbposi(char* email);
int caracter(char* email);
int server(char* email);
int at(char* email);
int size(char* email);

int main() {
    int tamanho;
    char email[51];

    while (scanf("%d", &tamanho) && tamanho > 0) {
        scanf(" %50[^\n]", email);

        if (email_valido(email))
            printf("Valido\n");
        else
            printf("Invalido\n");
    }

    return (0);
}

int email_valido(char email[]) {

    /* IMPLEMENTE SEU CODIGO AQUI */
    if(size(email) == 0 || at(email) == 0 || server(email) == 0 || caracter(email) == 0
        || simbposi(email) == 0 || simbconsecu(email) == 0 || numeropos(email) == 0){
        return 0;
    }else{
        return 1;
    }
    /* Esta funcao deve retornar 1 caso o e-mail seja valido e 0 caso contrario */
    /* É permitido criar outras funcoes para auxiliar na validacao do e-mail */

}

int size(char* email){
    int tamanho = 0;

    tamanho = strlen(email);

    if(tamanho > 50){
        return 0;
    }else{
        return 1;
    }
}

int at(char* email){
    int i = 0, contador = 0, size;

    size = strlen(email);

    for(i = 0; i < size; i++){
        if(email[i] == '@'){
            contador++;
        //    printf("infinito\n");
        }
    }if(contador == 1){
        return 1;
    }else{
    //    printf("at zuado\n");
        return 0;
    }
}

int server(char* email){
    int i = 0, tamanhoende = 0, j = 0, size = 0;
    char temp[51];

    size = strlen(email);

    while(email[i] != '@'){
        i++;
    }i++;
    tamanhoende = size - i;
    for(j = 0; j < tamanhoende; j++, i++){
        temp[j] = email[i];
        //printf("infinito server\n");
    }temp[j] = '\0';
    if(strcmp(temp, "email.abc") == 0){
        return 1;
    }else if(strcmp(temp, "email.abc.br") == 0){
        return 1;
    }else if(strcmp(temp, "abcmail.xyz.br") == 0){
        return 1;
    }else if(strcmp(temp, "abcweb.asd.br") == 0){
        return 1;
    }else if(strcmp(temp, "asdmail.xyz") == 0){
        return 1;
    }
    else{
        //printf("entrou no else\n");
        //printf("%s\n", temp);
        return 0;
    }
}

int caracter(char* email){
    int i = 0, size = 0;

    size = strlen(email);

    for(i = 0; i < size; i++){
        if(email[i] == '.' || email[i] == ',' || email[i] == '-' || email[i] == '_'
        || email[i] == '@' || (email[i] >= '0'  && email[i] <= '9') || (email[i] >= 'a' && email[i] <= 'z')){

         }else{
             return 0;
         }
    }
    return 1;
}

int simbposi(char* email){
    int size = 0, i = 0;

    size = strlen(email);

    while(email[i] != '@'){
        i++;

    }
    //printf("%c\n", email[i]);

    if(email[0] == '.' || email[0] == ',' || email[0] == '-' || email[0] == '_'){
        return 0;
    }if(email[i - 1] == '.' || email[i - 1] == ',' || email[i - 1] == '-' || email[i - 1] == '_'){
        return 0;
    }
    else{
        return 1;
    }
}

int simbconsecu(char* email){
    int i = 0, size = 0;

    size = strlen(email);

    for(i = 0; i < size; i++){
        if(email[i] == '.' || email[i] == ',' || email[i] == '-' || email[i] == '_'){
            //printf("entrou no primeiro if\n");
            if(email[i + 1] == '.' || email[i + 1] == ',' || email[i + 1] == '-' || email[i + 1] == '_'){
                return 0;
            }
        }
    }
    return 1;
}

int numeropos(char* email){
    int i = 0, size = 0;

    size = strlen(email);

    if((email[0] >= '0' && email[0] <= '9')){
        return 0;
    }

    for(i = 0; i < size; i++){
        if(email[i] == '.' || email[i] == ',' || email[i] == '-' || email[i] == '_'){
            if((email[i + 1] >= '0' && email[i + 1] <= '9')){
                return 0;
            }
        }
    }
    return 1;
}
