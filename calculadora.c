// Estrutura geral do código, onde define como cada operação é efetuada.

#include <stdio.h>

double adicao(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as operações de adição.
    return primeiroNumero + segundoNumero;
}

double subtracao(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as operações de subtração.
    return primeiroNumero - segundoNumero;
}

double multiplicacao(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as as operações de multiplicação.
    return primeiroNumero * segundoNumero;
}

double divisao(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as operações de divisão.
    return primeiroNumero / segundoNumero;
}

double modulo(double primeiroNumero) { // Instrução de como serão feitas as operações que extrairão o módulo de um número.
    double mod;
        if(primeiroNumero >= 0) {}
            else {
                mod = primeiroNumero * -1;
            }
        if(primeiroNumero < 0) {}
            else {
                mod = primeiroNumero;
            }
    return mod;
}

double fatorial(double primeiroNumero) { // Instrução de como serão feitas as operações de fatorial.
    double fat = 1;
        for (int i = 1; i <= primeiroNumero; ++i) {
            fat *= i;
        }
    return fat;
}

double exponencial(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as operações de exponenciais.
    double exp = 1;
        for(int i = 0; i < segundoNumero; i++) {
            exp *= primeiroNumero;
                if(segundoNumero == 0) {
                    exp = 1;
                }
        }
    return exp;
}

double exponencialNatural(double primeiroNumero) { // Instrução de como serão feitas as operações de exponenciais naturais.
    double expNat = 0, divisor, dividendo;
        for(int i = 0; i < 20; i++){
            dividendo = exponencial(primeiroNumero,i);
            divisor = fatorial(i);
            expNat += dividendo / divisor;
        }
    return expNat;
}

double logaritmoNatural(double primeiroNumero) { // Instrução de como serão feitas as operações de logaritmos naturais.
    double logNat = 0;
        for(int i = 0; i < 20; i++) {
            logNat += (1.0 / (2 * i + 1.0)) * exponencial(((primeiroNumero - 1.0) / (primeiroNumero + 1.0)), (2.0 * i + 1.0));
        }
    return 2 * logNat;
}

double logaritmo(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as operações de logaritmos.
    return logaritmoNatural(primeiroNumero) / logaritmoNatural(segundoNumero);
}

double raiz(double primeiroNumero, double segundoNumero) { // Instrução de como serão feitas as operações de rais y-ésimas.
    return exponencialNatural((1/segundoNumero) * logaritmoNatural(primeiroNumero));
}

double seno(double primeiroNumero) { // Instrução de como serão feitas as operações seno.
    double sen = 0, dividendo, divisor;
        for(int i = 0; i < 20; i++) {
            dividendo = exponencial(-1.0, i);
            divisor = fatorial(2.0 * i + 1.0);
            sen += (dividendo / divisor) * exponencial(primeiroNumero,  2.0 * i + 1.0);
        }
    return sen;
}

double cosseno(double primeiroNumero) { // Instrução de como serão feitas as operações cosseno.
    double cos = 0, dividendo, divisor;
        for(int i = 0; i < 20; i++) {
            dividendo = exponencial(-1.0, i);
            divisor = fatorial(2.0 * i);
            cos += (dividendo / divisor) * exponencial(primeiroNumero, 2.0 * i);
        }
    return cos;
}

double tangente(double primeiroNumero) {
    return seno(primeiroNumero) / cosseno(primeiroNumero);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Como dito anteriormente, a parte acima era responsável por definir como cada operação era feita. Já a parte abaixo, será responsável por apresentar o resultado ao usuário.

int main() {
    char operacao;
    double primeiroNumero, segundoNumero, resultado;

    scanf("%c", &operacao);
        if (operacao == '+') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                resultado = adicao(primeiroNumero, segundoNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == '-') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                resultado = subtracao(primeiroNumero, segundoNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == '*') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                resultado = multiplicacao(primeiroNumero, segundoNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == '/') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                resultado = divisao(primeiroNumero, segundoNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == 'm') {
            scanf("%lf", &primeiroNumero);
                resultado = modulo(primeiroNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == 'f') {
            scanf("%lf", &primeiroNumero);
                if (primeiroNumero > 0) { // Esse "if" limitará para que o resultado seja dado apenas para casos onde o número colhido for maior que 0.
                    resultado = fatorial(primeiroNumero);
                        printf("%0.2f", resultado);
                }
        }

        if (operacao == 'e') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                resultado = exponencial(primeiroNumero, segundoNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == 'n') {
            scanf("%lf", &primeiroNumero);
                resultado = exponencialNatural(primeiroNumero);
                    printf("%0.2f", resultado);
        }

        if (operacao == 'g') {
            scanf("%lf", &primeiroNumero);
                if (primeiroNumero > 0) {
                    resultado = logaritmoNatural(primeiroNumero);
                        printf("%.2f", resultado);
                }
        }

        if (operacao == 'l') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                if (primeiroNumero > 0 && segundoNumero > 0) {
                    resultado = logaritmo(primeiroNumero, segundoNumero);
                        printf("%.2f", resultado);
                }  
        }

        if (operacao == 'r') {
            scanf("%lf %lf", &primeiroNumero, &segundoNumero);
                if (primeiroNumero > 0 && segundoNumero > 0) {
                    resultado = raiz(primeiroNumero, segundoNumero);
                        printf("%.2f", resultado);
                }
        }

        if (operacao == 's') {
            scanf("%lf", &primeiroNumero);
                resultado = seno(primeiroNumero);
                    printf("%.2f", resultado);
        }

        if (operacao == 'c') {
            scanf("%lf", &primeiroNumero);
                resultado = cosseno(primeiroNumero);
                    printf("%.2f", resultado);
        }

        if (operacao == 't') {
            scanf("%lf", &primeiroNumero);
                resultado = tangente(primeiroNumero);
                    printf("%.2f", resultado);
        }

    return 0;
}