#include <math.h>
#include "../include/densidades.h"

// Densidad constante
double densidad_constante(double x, double y, double z) {
    return 1.0;
}

// Densidad lineal: rho = x + y + z
double densidad_lineal(double x, double y, double z) {
    return x + y + z;
}

// Densidad gaussiana
double densidad_gaussiana(double x, double y, double z) {
    return exp(-(x*x + y*y + z*z));
}
