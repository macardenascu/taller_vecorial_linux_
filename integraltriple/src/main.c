#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/densidades.h"
#include "../include/integracion.h"

int main() {

    srand(time(NULL));

    Limites lim;
    int opcion, n_puntos;
    FuncDensidad funcion_seleccionada;
    const char *nombre_densidad;

    printf("--- Calculadora de Centro de Masa (Monte Carlo) ---\n");

    printf("Ingrese limites X (min max): ");
    scanf("%lf %lf", &lim.x_min, &lim.x_max);

    printf("Ingrese limites Y (min max): ");
    scanf("%lf %lf", &lim.y_min, &lim.y_max);

    printf("Ingrese limites Z (min max): ");
    scanf("%lf %lf", &lim.z_min, &lim.z_max);

    printf("Numero de muestras N: ");
    scanf("%d", &n_puntos);

    printf("\nSeleccione densidad:\n");
    printf("1. Constante\n");
    printf("2. Lineal\n");
    printf("3. Gaussiana\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1: funcion_seleccionada = densidad_constante; nombre_densidad = "Constante"; break;
        case 2: funcion_seleccionada = densidad_lineal;    nombre_densidad = "Lineal";    break;
        case 3: funcion_seleccionada = densidad_gaussiana; nombre_densidad = "Gaussiana"; break;
        default: printf("Opcion invalida.\n"); return 1;
    }

    double M, cx, cy, cz;

    clock_t start = clock();
    calcular_monte_carlo(funcion_seleccionada, lim, n_puntos, &M, &cx, &cy, &cz);
    clock_t end = clock();

    double tiempo_seg = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n--- Resultados ---\n");
    printf("Masa Total: %f\n", M);
    printf("Centro de Masa: (%f, %f, %f)\n", cx, cy, cz);
    printf("Tiempo: %f segundos\n", tiempo_seg);

    FILE *fp = fopen("resultados.csv", "a");
    if (!fp) {
        printf("Error al abrir resultados.csv\n");
        return 1;
    }

    fprintf(fp,
        "MonteCarlo,%s,%d,%d,%d,%.6f,%.6f,%.6f,%.6f,%.6f\n",
        nombre_densidad, n_puntos, n_puntos, n_puntos,
        M, cx, cy, cz, tiempo_seg
    );

    fclose(fp);
    printf("Datos guardados en resultados.csv\n");

    return 0;
}
