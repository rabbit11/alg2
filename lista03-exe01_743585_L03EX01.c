/* ================================================================== *
   Universidade Federal de Sao Carlos - UFSCar, Sorocaba

   Disciplina: Algoritmos e Programação 2

   Lista 03 - Exercício 01 - Calculadora Geométrica

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
#include <math.h>

// matematica
#define PI acos(-1)

// menu de opcoes
#define CIRCULO   1
#define ESFERA    2
#define RETANGULO 3
#define CUBO      4
#define CONE      5
#define PIRAMIDE  6
#define SAIR      0


// declaracoes das funcoes
/* <<< DECLARE OS PROTOTIPOS DAS FUNCOES AQUI >>> */
void calcularCirculo(float raio, float *area, float *circunferencia);
void calcularEsfera(float raio, float *volume, float *areaSuperficie);
void calcularRetangulo(float largura, float comprimento, float *area, float *perimetro);
void calcularCubo(float aresta, float *volume, float *areaSuperficie, float *diagonal);
void calcularCone(float raio, float altura, float *volume, float *areaSuperficie);
void calcularPiramide( float comprimento, float largura, float altura, float *superficieLateral, float *volume);

/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */
int main()
{
   int opcao;     // opcao selecionada pelo usuario

   // variaveis utilizadas pelas rotinas de calculo
   float raio, area, perimetro, circunferencia, areaSuperficie,
          volume, largura, comprimento, superficieLateral,
          aresta, diagonal, altura;

   scanf("%d", &opcao);

   while (opcao != SAIR)
   {
      switch(opcao)
      {

         case CIRCULO:
            raio, area, perimetro = 0;
            scanf("%f", &raio);
            calcularCirculo(raio, &area, &circunferencia);
            printf("%.2f %.2f\n", area, circunferencia);

         break;

         case ESFERA:
            raio, volume, areaSuperficie = 0;
            scanf("%f", &raio);
            calcularEsfera(raio, &volume, &areaSuperficie);
            printf("%.2f %.2f\n", volume, areaSuperficie);

         break;

         case RETANGULO:
            largura, comprimento, area, perimetro = 0;
            scanf("%f %f", &largura, &comprimento);
            calcularRetangulo(largura, comprimento, &area, &perimetro);
            printf("%.2f %.2f\n", area, perimetro);

         break;

         case CUBO:
            aresta, volume, areaSuperficie, diagonal = 0;
            scanf("%f", &aresta);
            calcularCubo(aresta, &volume, &areaSuperficie, &diagonal);
            printf("%.2f %.2f %.2f\n", volume, areaSuperficie, diagonal);

         break;

         case CONE:
            raio, altura, volume, areaSuperficie = 0;
            scanf("%f %f", &raio, &altura);
            calcularCone(raio, altura, &volume, &areaSuperficie);
            printf("%.2f %.2f\n", volume, areaSuperficie);

         break;

         case PIRAMIDE:
            comprimento, largura, altura, superficieLateral, volume = 0;
            scanf("%f %f %f", &comprimento, &largura, &altura);
            calcularPiramide(comprimento, largura, altura, &superficieLateral, &volume);
            printf("%.2f %.2f\n", superficieLateral, volume);

         break;

      }

      scanf("%d", &opcao);
   }

   return 0;
}

/* ------------------------- */
/* IMPLEMENTACAO DAS FUNCOES */
/* ------------------------- */

/* <<< IMPLEMENTE AS FUNCOES AQUI >>> */
void calcularCirculo(float raio, float *area, float *circunferencia){

    *area = PI * (raio * raio);
    *circunferencia = PI * 2 * raio;

}
void calcularEsfera(float raio, float *volume, float *areaSuperficie){

    *volume = (4 * PI * (raio * raio * raio)) / 3.0f;
    *areaSuperficie = 4 * PI * (raio * raio);
}
void calcularRetangulo(float largura, float comprimento, float *area, float *perimetro){

    *area = largura * comprimento;
    *perimetro = 2 * largura + 2 * comprimento;
}
void calcularCubo(float aresta, float *volume, float *areaSuperficie, float *diagonal){

    *volume = aresta * aresta * aresta;
    *areaSuperficie = 6 * (aresta * aresta);
    *diagonal = aresta * sqrt(3);
}

void calcularCone(float raio, float altura, float *volume, float *areaSuperficie){

    *volume = PI * (raio * raio) * (altura / 3.0f);
    *areaSuperficie = (PI * raio) * (raio + sqrt((altura * altura) + (raio * raio)));

}

void calcularPiramide(float comprimento, float largura, float altura, float *superficieLateral, float *volume){

    *superficieLateral = comprimento * (sqrt(((largura / 2) * (largura / 2)) + (altura * altura))) + largura * sqrt(((comprimento / 2.0f)
    * (comprimento / 2.0f)) + (altura * altura));
    *volume = (altura * largura * comprimento) / 3.0f ;
}
