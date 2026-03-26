#include <stdio.h>

#define MAX 100

// Prototipos
void registrarDatos(int vec[], int *n);
void mostrarArreglo(int vec[], int n);
void burbuja(int vec[], int n);
void seleccion(int vec[], int n);
void insercion(int vec[], int n);

int main() {
    int vec[MAX];
    int n = 0;
    int opcion;
    int datosIngresados = 0;

    do {
        printf("\n===== MENU =====\n");

        if (!datosIngresados) {
            printf("1. Registrar datos\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);

            if (opcion == 1) {
                registrarDatos(vec, &n);
                datosIngresados = 1;
            } else {
                printf("⚠️ Primero debes ingresar datos.\n");
            }

        } else {
            printf("1. Registrar datos\n");
            printf("2. Mostrar arreglo\n");
            printf("3. Ordenar por Burbuja\n");
            printf("4. Ordenar por Seleccion\n");
            printf("5. Ordenar por Insercion\n");
            printf("6. Salir\n");

            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    registrarDatos(vec, &n);
                    break;

                case 2:
                    mostrarArreglo(vec, n);
                    break;

                case 3:
                    burbuja(vec, n);
                    break;

                case 4:
                    seleccion(vec, n);
                    break;

                case 5:
                    insercion(vec, n);
                    break;

                case 6:
                    printf("Saliendo...\n");
                    break;

                default:
                    printf("Opcion invalida\n");
            }
        }

    } while (opcion != 6);

    return 0;
}

// ================= FUNCIONES =================

void registrarDatos(int vec[], int *n) {
    printf("\nCuantos datos desea ingresar?: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Dato %d: ", i + 1);
        scanf("%d", &vec[i]);
    }
}

void mostrarArreglo(int vec[], int n) {
    printf("\nArreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// ===== BURBUJA =====
void burbuja(int vec[], int n) {
    int temp;

    printf("\n--- Metodo Burbuja ---\n");

    for (int i = 0; i < n - 1; i++) {
        printf("\nPasada %d:\n", i + 1);

        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                // intercambio
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;

                printf("Intercambio: ");
                mostrarArreglo(vec, n);
            }
        }
    }

    printf("\nResultado final:\n");
    mostrarArreglo(vec, n);
}

// ===== SELECCION =====
void seleccion(int vec[], int n) {
    int min, temp;

    printf("\n--- Metodo Seleccion ---\n");

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }

        if (min != i) {
            temp = vec[i];
            vec[i] = vec[min];
            vec[min] = temp;

            printf("Intercambio en posicion %d: ", i);
            mostrarArreglo(vec, n);
        }

        printf("Fin de pasada %d\n", i + 1);
    }

    printf("\nResultado final:\n");
    mostrarArreglo(vec, n);
}

// ===== INSERCION =====
void insercion(int vec[], int n) {
    int clave, j;

    printf("\n--- Metodo Insercion ---\n");

    for (int i = 1; i < n; i++) {
        clave = vec[i];
        j = i - 1;

        printf("\nInsertando %d:\n", clave);

        while (j >= 0 && vec[j] > clave) {
            vec[j + 1] = vec[j];
            j--;

            printf("Movimiento: ");
            mostrarArreglo(vec, n);
        }

        vec[j + 1] = clave;

        printf("Fin de pasada %d: ", i);
        mostrarArreglo(vec, n);
    }

    printf("\nResultado final:\n");
    mostrarArreglo(vec, n);
}