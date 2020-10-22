/* ALGORITMO: MÉTODO DE ILLINOIS
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

/* Função que realiza as interações do método Illinois */
void MetodoIllinois(float * f, float a, float b, float e, int grau, int cont, float x, int itsma, int itsmb){
    float fx = CalculaFx(f, x, grau);
    float fa = CalculaFx(f, a, grau);
    float fb = CalculaFx(f, b, grau);
    if((fabs(fx)<e) && (fabs(b-a)<e)){
        printf("\t| %.2d | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f |\n\n", cont, a, b, fa, fb, (b-a), x, fx);
    }
    else{
        if((itsma < 2) && (itsmb < 2)) x = ((a*fb)-(b*fa))/(fb-fa);
        if(itsma >= 2) x = ((a*fb)-(b*0.5*fa))/(fb-(0.5*fa));
        if(itsmb >= 2) x = ((a*0.5*fb)-(b*fa))/((fb*0.5)-fa);
        printf("\t| %.2d | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f |\n\n", cont, a, b, fa, fb, (b-a), x, fx);
        if((fx*fa) < 0) MetodoIllinois(f, a, x, e, grau, cont+1, x, itsma+1, 0);
        else MetodoIllinois(f, x, b, e, grau, cont+1, x, 0, itsmb+1);
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
    printf("\n\n\t===========================  RESULTADOS OBTIDOS  ===========================\n\n\t| k  |   a     |   b     |  f(a)   |   f(b)   |  (b-a)  |    x    |   f(x)  |\n\n");
    float fa, fb;
    fa = CalculaFx(f, a, grau);
    fb = CalculaFx(f, b, grau);
    float x = ((a*fb)-(b*fa))/(fb-fa);
    MetodoIllinois(f, a, b, e, grau, 0, x, 0, 0);
    return 0;
}
