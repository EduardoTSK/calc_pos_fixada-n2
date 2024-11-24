#include <stdio.h>
#include "expressao.h"

int main() {
    char posFixa[512];
    Expressao expressao;

    // Teste 1
    snprintf(posFixa, sizeof(posFixa), "3 4 + 5 *");
    expressao.Valor = getValor(posFixa);
    printf("Resultado da expressão %s = %.2f\n", posFixa, expressao.Valor);
    
    // Teste 2
    snprintf(posFixa, sizeof(posFixa), "7 2 * 4 +");
    expressao.Valor = getValor(posFixa);
    printf("Resultado da expressão %s = %.2f\n", posFixa, expressao.Valor);
    
    // Teste 3
    snprintf(posFixa, sizeof(posFixa), "8 5 2 4 + * +");
    expressao.Valor = getValor(posFixa);
    printf("Resultado da expressão %s = %.2f\n", posFixa, expressao.Valor);
    
    // Teste 4
    snprintf(posFixa, sizeof(posFixa), "6 2 / 3 + 4 *");
    expressao.Valor = getValor(posFixa);
    printf("Resultado da expressão %s = %.2f\n", posFixa, expressao.Valor);
    
    // Teste 5
    snprintf(posFixa, sizeof(posFixa), "9 5 2 8 * 4 + * +");
    expressao.Valor = getValor(posFixa);
    printf("Resultado da expressão %s = %.2f\n", posFixa, expressao.Valor);

    return 0;
}