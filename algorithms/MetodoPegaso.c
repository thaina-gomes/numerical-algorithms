/* ALGORITMO: MÉTODO DE PÉGASO
ALUNA: THAINA GOMES DE ARAUJO
MATÉRIA: ALGORITMOS NUMÉRICOS */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Função responsável por fornecer valores resultantes da função, cujo x é
passado como parâmetro */
float CalculaFx(float x){
    //return (cos(x)-x);
    return ((2*pow(x,3)) - cos(x+1) - 3);
}

/* Função que realiza as iterações do método de Pégaso*/
void MetodoPegaso(float a, float b, float tol, int IterMax){
    float fa, fb, fx, x, deltaX, CondErro = 0, raiz = 0, modDeltaX, modFx;
    int iter = 0;
    fa = CalculaFx(a);
    fb = CalculaFx(b);
    x = b;
    fx = fb;

    while(1){
        deltaX = ((-fx)/(fb-fa))*(b-a);
        x += deltaX;
        fx = CalculaFx(x);
        printf("\n\t|    %.2d     | %.9f |   %.9f   | %.9f |   %.9f  | %.9f |   %.9f |  %.9f  |\n", iter, a, fa, b, fb, x, fx, deltaX);
        modDeltaX = deltaX > 0 ? deltaX : -deltaX;
        modFx = fx > 0 ? fx : -fx;
        if((modDeltaX <= tol && modFx <= tol) || (iter == IterMax)) break;
        if((fx*fb) < 0){
            a = b;
            fa = fb;
        }
        else fa = (fa*fb)/(fb+fx);
        b = x;
        fb = fx;
        iter += 1;
    }
    raiz = x;
    modDeltaX = deltaX > 0 ? deltaX : -deltaX;
    modFx = fx > 0 ? fx : -fx;
    if( modDeltaX <= tol && modFx <= tol) CondErro = 0;
    else CondErro = 1;
    printf("\n\tRAIZ = %.6f\n\tCONDICAO DE ERRO = %d\n", raiz, CondErro);
}

int main(){
    int nIter;
    float a, b, tol;
    printf("\n\tENTRE COM O LIMITE INFERIOR DO INTERVALO: ");
    scanf("%f", &a);
    printf("\n\tENTRE COM O LIMITE SUPERIOR DO INTERVALO: ");
    scanf("%f", &b);
    printf("\n\tENTRE COM A TOLERANCIA DESEJADA: ");
    scanf("%f", &tol);
    printf("\n\tENTRE COM A QUANTIDADE MAXIMA DE ITERACOES: ");
    scanf("%d", &nIter);
    printf("\n\t========================================= RESULTADOS OBTIDOS =========================================\n\n\t| ITERACOES |    a     |      f(a)    |    b     |      f(b)    |    x     |    f(x)    |   deltaX    |\n");
    MetodoPegaso(a, b, tol, nIter);
}
