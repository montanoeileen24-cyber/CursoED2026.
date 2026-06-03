/******************************************************************************
 * ASIGNATURA: Estructura de Datos
 * PROGRAMA: Ingeniería de Sistemas
 * UNIVERSIDAD: Universidad del Pacífico
 * * AUTORES: 
 * - Saira Lucía Gutiérrez Orobio
 * - [Nombre de Integrante 2]
 * - [Nombre de Integrante 3]
 * - [Nombre de Integrante 4]
 * * TALLER - UNIDAD 5: Métodos de ordenamiento eficientes y búsqueda binaria
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30

// --- VARIABLES GLOBALES (Para evitar complicaciones con parámetros) ---
int pesos[MAX_CONTENEDORES];
int Ncon = 0;        // Cantidad actual de contenedores registrados
int ordenado = 0;    // Bandera: 0 = desordenado, 1 = ordenado

// --- PROTOTIPOS DE FUNCIONES ---
void registrarManualmente();
void generarAleatorio();
void mostrarContenedores();
void ordenarShell();
void ordenarQuickSort(int bajo, int alto);
void iniciarQuickSort();
void ordenarMergeSort(int izq, int der);
void merge(int izq, int medio, int der);
void iniciarMergeSort();
void buscarBinario();

int main() {
    int opcion;
    
    // Inicializar la semilla para los números aleatorios
    srand(time(NULL));

    do {
        printf("\n==================================================\n");
        printf("      SISTEMA DE ORGANIZACION DE CONTENEDORES\n");
        printf("                  MUELLE DE CARGA\n");
        printf("==================================================\n");
        printf("1. Registrar peso de contenedores manualmente\n");
        printf("2. Generar pesos aleatorios de contenedores\n");
        printf("3. Mostrar contenedores registrados\n");
        printf("4. Ordenar contenedores Metodo 1 (ShellSort)\n");
        printf("5. Ordenar contenedores Metodo 2 (QuickSort)\n");
        printf("6. Ordenar contenedores Metodo 3 (MergeSort)\n");
        printf("7. Buscar contenedor (Busqueda Binaria)\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarManualmente();
                break;
            case 2:
                generarAleatorio();
                break;
            case 3:
                mostrarContenedores();
                break;
            case 4:
                ordenarShell();
                break;
            case 5:
                iniciarQuickSort();
                break;
            case 6:
                iniciarMergeSort();
                break;
            case 7:
                buscarBinario();
                break;
            case 8:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 8);

    return 0;
}

// 1. REGISTRO MANUAL
void registrarManualmente() {
    printf("Ingresa el numero de contenedores (max %d): ", MAX_CONTENEDORES);
    scanf("%d", &Ncon);

    if (Ncon < 1 || Ncon > MAX_CONTENEDORES) {
        printf("Cantidad no valida.\n");
        Ncon = 0;
        return;
    }

    for (int i = 0; i < Ncon; i++) {
        printf("Ingrese el peso del contenedor %d (en kg): ", i + 1);
        scanf("%d", &pesos[i]);
    }
    
    ordenado = 0; // Al ingresar nuevos datos, el arreglo deja de estar ordenado seguro
    printf("Pesos registrados exitosamente.\n");
}

// 2. GENERACIÓN ALEATORIA
void generarAleatorio() {
    printf("Ingresa el numero de contenedores a generar (max %d): ", MAX_CONTENEDORES);
    scanf("%d", &Ncon);

    if (Ncon < 1 || Ncon > MAX_CONTENEDORES) {
        printf("Cantidad no valida.\n");
        Ncon = 0;
        return;
    }

    for (int i = 0; i < Ncon; i++) {
        // Genera pesos aleatorios realistas entre 1000 kg y 30000 kg
        pesos[i] = 1000 + rand() % 29001; 
    }

    ordenado = 0; // Se marca como desordenado
    printf("Pesos aleatorios generados de forma exitosa.\n");
}

// 3. MOSTRAR ARREGLO
void mostrarContenedores() {
    if (Ncon == 0) {
        printf("No hay contenedores registrados en el patio.\n");
        return;
    }

    printf("\nEstado actual del arreglo (Bandera Ordenado = %d):\n", ordenado);
    for (int i = 0; i < Ncon; i++) {
        printf("[%d]: %d kg\n", i, pesos[i]);
    }
    printf("\n");
}

// 4. MÉTODO 1: SHELLSORT
void ordenarShell() {
    if (Ncon == 0) {
        printf("No hay datos para ordenar.\n");
        return;
    }

    // Algoritmo ShellSort
    for (int intervalo = Ncon / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < Ncon; i++) {
            int temp = pesos[i];
            int j;
            for (j = i; j >= intervalo && pesos[j - intervalo] > temp; j -= intervalo) {
                pesos[j] = pesos[j - intervalo];
            }
            pesos[j] = temp;
        }
    }

    ordenado = 1; // ¡Arreglo ordenado con éxito!
    printf("Contenedores ordenados usando ShellSort.\n");
}

// 5. MÉTODO 2: QUICKSORT (Lógica Interna y Auxiliar)
void ordenarQuickSort(int bajo, int alto) {
    if (bajo < alto) {
        int pivote = pesos[alto]; // Elegimos el último elemento como pivote
        int i = (bajo - 1);

        for (int j = bajo; j < alto; j++) {
            if (pesos[j] < pivote) {
                i++;
                int temp = pesos[i];
                pesos[i] = pesos[j];
                pesos[j] = temp;
            }
        }
        int temp = pesos[i + 1];
        pesos[i + 1] = pesos[alto];
        pesos[alto] = temp;

        int pi = i + 1;

        // Llamadas recursivas
        ordenarQuickSort(bajo, pi - 1);
        ordenarQuickSort(pi + 1, alto);
    }
}

// Función envoltura para QuickSort para que el menú no necesite parámetros
void iniciarQuickSort() {
    if (Ncon == 0) {
        printf("No hay datos para ordenar.\n");
        return;
    }
    ordenarQuickSort(0, Ncon - 1);
    ordenado = 1;
    printf("Contenedores ordenados usando QuickSort.\n");
}

// 6. MÉTODO 3: MERGESORT (Lógica Interna y Auxiliares)
void merge(int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    int L[MAX_CONTENEDORES], R[MAX_CONTENEDORES];

    for (int i = 0; i < n1; i++) L[i] = pesos[izq + i];
    for (int j = 0; j < n2; j++) R[j] = pesos[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            pesos[k] = L[i];
            i++;
        } else {
            pesos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        pesos[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        pesos[k] = R[j];
        j++;
        k++;
    }
}

void ordenarMergeSort(int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        ordenarMergeSort(izq, medio);
        ordenarMergeSort(medio + 1, der);
        merge(izq, medio, der);
    }
}

// Función envoltura para MergeSort para mantener el menú limpio
void iniciarMergeSort() {
    if (Ncon == 0) {
        printf("No hay datos para ordenar.\n");
        return;
    }
    ordenarMergeSort(0, Ncon - 1);
    ordenado = 1;
    printf("Contenedores ordenados usando MergeSort.\n");
}

// 7. BÚSQUEDA BINARIA
void buscarBinario() {
    if (Ncon == 0) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    // REQUISITO OBLIGATORIO DEL TALLER: Verificar la bandera
    if (ordenado == 0) {
        printf("ERROR: El arreglo NO esta ordenado. Debe ejecutar un metodo de ordenamiento antes de buscar.\n");
        return;
    }

    int pesoBuscar;
    printf("Ingrese el peso del contenedor que desea buscar: ");
    scanf("%d", &pesoBuscar);

    int inicio = 0;
    int fin = Ncon - 1;
    int encontrado = -1;

    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;

        if (pesos[mitad] == pesoBuscar) {
            encontrado = mitad;
            break; // Lo encontramos, salimos del ciclo
        }
        if (pesos[mitad] < pesoBuscar) {
            inicio = mitad + 1; // Buscar en la mitad derecha
        } else {
            fin = mitad - 1;    // Buscar en la mitad izquierda
        }
    }

    if (encontrado != -1) {
        printf("¡Contenedor encontrado! El peso %d kg esta en la posicion [%d] del arreglo.\n", pesoBuscar, encontrado);
    } else {
        printf("El contenedor con peso %d kg no se encuentra en el patio.\n", pesoBuscar);
    }
}