// Leia uma velocidade em m/s, calcule e escreva esta velocidade em km/h. (km/h = m/s * 3.6)

#include <stdio.h>

float main() {
    float velocidade_ms;
    printf("Velocidade em m/s: ");
    scanf("%f", &velocidade_ms);

    printf("Velocidade em km/h: %f", velocidade_ms * 3.6);

    return 0;
}