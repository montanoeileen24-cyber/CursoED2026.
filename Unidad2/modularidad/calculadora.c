#include <stdio.h>
#include <math.h>
#include "areas.h"
#include "volumenes.h"

/* Funciones de áreas */
float areaCirculo(float radio){
    return M_PI * radio * radio;
}

float areaCuadrado(float lado){
    return lado * lado;
}

/* Funciones de volúmenes */
float volumenEsfera(float radio){
    return (4.0/3.0) * M_PI * radio * radio * radio;
}

float volumenCubo(float lado){
    return lado * lado * lado;
}

int main(){

    float radio = 3;
    float lado = 4;

    printf("Area del circulo: %.2f\n", areaCirculo(radio));
    printf("Area del cuadrado: %.2f\n", areaCuadrado(lado));

    printf("Volumen de la esfera: %.2f\n", volumenEsfera(radio));
    printf("Volumen del cubo: %.2f\n", volumenCubo(lado));

    return 0;
}