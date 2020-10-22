/* ALGORITMO: MÉTODO DA BISSEÇÃO
ALUNA: THAINA GOMES DE ARAUJO
MATÉRIA: ALGORITMOS NUMÉRICOS */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Função responsável por pegar a expressão que o usuário deseja
calcular */

float * getFuncao(int grau){
    float * funcao = (float*)calloc(grau+1, sizeof(float));
    if(funcao == NULL){
        printf("\n\tERRO DE ALOCACAO...\n");
        exit(1);
    }
    else{
        int i;
        for(i=0; i<= grau; i++){
            printf("\n\tENTRE COM O COEFICIENTE DE x^%d: ", i);
            scanf("%f", &funcao[i]);
        }
        for(i=grau; i>=0; i--){
            if(funcao[i] != 0){
                if(i == grau)printf("\n\tf(x) = %.2fx^%d ", funcao[i], i);
                else if(i == 0) printf("+ (%.2f)", funcao[i]);
                else{
                    printf("+ (%.2f)x^%d ", funcao[i], i);
                }
            }
        }
        return funcao;
    }
}

/* Função responsável por calcular o resultado de uma constante em uma f(x)*/

float CalculaFx(float * f, float x, int grau){
    float resultado = 0;
    int i;
    for(i=0; i<=grau; i++){
        resultado += f[i] * pow(x, i);
    }
    return resultado;
}

void MetodoDaBissecao(float * f, float a, float b, float e, int grau, int cont){
    float fx, fa, fb;
    if(b-a < e){
        fa = CalculaFx(f, a, grau);
        fb = CalculaFx(f, b, grau);
        printf("\t| %2.d | %.5f | %.5f | %.5f | %.5f | %.5f |\n\n", cont, a, b, fa, fb, (b-a));
    }
    else{
        float x = (a+b)/2;
        fx = CalculaFx(f, x, grau);
        fa = CalculaFx(f, a, grau);
        fb = CalculaFx(f, b, grau);
        printf("\t| %.2d | %.5f | %.5f | %.5f | %.5f | %.5f |\n\n", cont, a, b, fa, fb, (b-a));
        if(fx == 0) printf("\n\tA RAIZ DA EQUACAO EH: %.2f\n\n", x);
        else if((fx*fa) < 0) MetodoDaBissecao(f, a, x, e, grau, cont+1);
        else if((fx*fb) < 0) MetodoDaBissecao(f, x, b, e, grau, cont+1);
    }
}

int main(){
    int grau;
    printf("\n\tENTRE COM O GRAU DA EQUACAO f(x): ");
    scanf("%d", &grau);
    if(grau < 1){
        while(grau < 1){
            printf("\n\tNUMERO INVALIDO\n\tENTRE COM OUTRO VALOR: ");
            scanf("%d", &grau);
        }
    }
    float * f = getFuncao(grau);
    float e, a, b;
    printf("\n\n\tENTRE COM A APROXIMACAO DESEJADA: ");
    scanf("%f", &e);
    printf("\n\tENTRE COM O LIMITE INFERIOR DO INTERVALO: ");
    scanf("%f", &a);
    printf("\n\tENTRE COM O LIMITE SUPERIOR DO INTERVALO: ");
    scanf("%f", &b);
    printf("\n\n\t=================  RESULTADOS OBTIDOS  =================\n\n\t| k  |   a     |   b     |  f(a)   |   f(b)   |  (b-a)  | \n\n");
    MetodoDaBissecao(f, a, b, e, grau, 0);
    return 0;
}
