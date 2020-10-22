/* ALGORITMO: MÉTODO NEWTON-RAPHSON
ALUNA: THAINA GOMES DE ARAUJO
MATÉRIA: ALGORITMOS NUMÉRICOS */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Função responsável por pegar a expressão que o usuário deseja
encontrar as raizes */

float getFx(float x){
    return (pow(x,3) - (9*x) + 3);
}

/* Função responsável por pegar a expressão auxiliar para o método
de Newton-Raphson */

float getDerivadaFx(float x){
        return (3*pow(x, 2) - 9);
}

/* Função que realiza as interações do método de Newton-Raphson*/

void MetodoNewtonRaphson(float x, float e, int cont){
    float fx;
    if(cont == 0)fx = getFx(x);
    else{
        x = x - (getFx(x)/getDerivadaFx(x));
        fx = getFx(x);
    }
    if(fabs(fx) < e){
        printf("\t| %.2d | %.8f | %.8f |\n\n", cont, x, fx);
    }
    else{
        printf("\t| %.2d | %.8f | %.8f |\n\n", cont, x, fx);
        MetodoNewtonRaphson(x, e, cont+1);
    }
}

int main(){
    float e, a, b;
    printf("\n\n\tENTRE COM A APROXIMACAO DESEJADA: ");
    scanf("%f", &e);
    printf("\n\tENTRE COM O LIMITE INFERIOR DO INTERVALO: ");
    scanf("%f", &a);
    printf("\n\tENTRE COM O LIMITE SUPERIOR DO INTERVALO: ");
    scanf("%f", &b);
    printf("\n\n\t======  RESULTADOS OBTIDOS  ======\n\n\t| k  |     x      |     f(x)    |\n\n");
    float x = 0.5*(b+a);
    MetodoNewtonRaphson(x, e, 0);
    return 0;
}
