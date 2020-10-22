/* ALGORITMO: MÉTODO PONTO FIXO
ALUNA: THAINA GOMES DE ARAUJO
MATÉRIA: ALGORITMOS NUMÉRICOS */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Função responsável por pegar a expressão que o usuário deseja
calcular */

float * getFuncaoFx(int grau){
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

/* Função responsável por pegar a expressão que o usuário deseja
calcular */

float * getFuncaoPhiX(int grau){
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
                if(i == grau)printf("\n\tphi(x) = %.2fx^%d ", funcao[i], i);
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

/* Função que realiza as interações do método Ponto fixo */

void MetodoPontoFixo(float * f, float * phi, float x, float e, int grau, int cont){
    float fx;
    if(cont == 0)fx = CalculaFx(f, x, grau);
    else{
        x = CalculaFx(phi, x, grau);
        fx = CalculaFx(f, x, grau);
    }
    if(fabs(fx) < e){
        printf("\t| %.2d | %.8f | %.8f |\n\n", cont, x, fx);
    }
    else{
        printf("\t| %.2d | %.8f | %.8f |\n\n", cont, x, fx);
        MetodoPontoFixo(f, phi, x, e, grau, cont+1);
    }
}

int main(){
    int grau, grau1;
    printf("\n\tENTRE COM O GRAU DA EQUACAO f(x): ");
    scanf("%d", &grau);
    if(grau < 1){
        while(grau < 1){
            printf("\n\tNUMERO INVALIDO\n\tENTRE COM OUTRO VALOR: ");
            scanf("%d", &grau);
        }
    }
    float * f = getFuncaoFx(grau);
    printf("\n\n\tENTRE COM O GRAU DA FUNCAO phi(x): ");
    scanf("%d", &grau1);
    float * phi = getFuncaoPhiX(grau1);
    float e, a, b;
    printf("\n\n\tENTRE COM A APROXIMACAO DESEJADA: ");
    scanf("%f", &e);
    printf("\n\tENTRE COM O LIMITE INFERIOR DO INTERVALO: ");
    scanf("%f", &a);
    printf("\n\tENTRE COM O LIMITE SUPERIOR DO INTERVALO: ");
    scanf("%f", &b);
    printf("\n\n\t======  RESULTADOS OBTIDOS  ======\n\n\t| k  |     x      |     f(x)    |\n\n");
    float x = 0.5*(b+a);
    MetodoPontoFixo(f, phi, x, e, grau, 0);
    return 0;
}
