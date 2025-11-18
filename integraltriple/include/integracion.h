#ifndef INTEGRACION_H
#define INTEGRACION_H

// Estructura de límites para la región rectangular
typedef struct {
    double x_min, x_max;
    double y_min, y_max;
    double z_min, z_max;
} Limites;

// Tipo de dato para puntero a función de densidad
typedef double (*FuncDensidad)(double, double, double);

// Cálculo de masa y centro de masa por Monte Carlo
void calcular_monte_carlo(FuncDensidad rho, Limites lim, int n_puntos,
                          double *masa, double *cm_x, double *cm_y, double *cm_z);

#endif
