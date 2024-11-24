#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "expressao.h"

// Função auxiliar para verificar se um caractere é um operador
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Função auxiliar para calcular operações de 2 operandos
float performOperation(float operand1, float operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        default: return 0;
    }
}

// Função auxiliar para calcular operações de 1 operando
float performUnaryOperation(float operand, char operator) {
    switch (operator) {
        case 'r': return sqrt(operand);  // Raiz quadrada
        case 's': return sin(operand);   // Seno
        case 'c': return cos(operand);   // Cosseno
        case 't': return tan(operand);   // Tangente
        case 'l': return log10(operand); // Logaritmo base 10
        default: return 0;
    }
}

// Função para avaliar uma expressão pós-fixada
float getValor(char *Str) {
    float stack[512];
    int top = -1;
    char *token = strtok(Str, " ");
    
    while (token != NULL) {
        if (isOperator(token[0]) && strlen(token) == 1) {
            float operand2 = stack[top--];
            float operand1 = stack[top--];
            stack[++top] = performOperation(operand1, operand2, token[0]);
        } else if (isalpha(token[0])) {
            float operand = stack[top--];
            stack[++top] = performUnaryOperation(operand, token[0]);
        } else {
            stack[++top] = atof(token);
        }
        token = strtok(NULL, " ");
    }

    return stack[top];
}

// Função para converter uma expressão pós-fixada em pré-fixada
char *getFormaInFixa(char *Str) {
    // Esta função será responsável pela conversão, podendo ser complexa
    // O algoritmo de conversão seria semelhante ao de infixa para pós-fixada, mas adaptado para pré-fixada
    // Aqui, implementamos de forma simplificada
    // Este código não está completamente implementado, pois seria necessário um algoritmo
    // complexo que manipula pilhas para conversão.

    return Str;
}