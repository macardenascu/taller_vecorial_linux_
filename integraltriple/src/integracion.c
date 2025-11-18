#include <stdlib.h>
#include "integracion.h"

// Genera un número aleatorio uniforme en [min, max]
static double random_range(double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min);
}

void calcular_monte_carlo(FuncDensidad rho, Limites lim, int n_puntos,
                          double *masa, double *cm_x, double *cm_y, double *cm_z) {

    if (n_puntos <= 0) {
        *masa = *cm_x = *cm_y = *cm_z = 0.0;
        return;
    }

    double sum_rho = 0.0;
    double sum_x_rho = 0.0;
    double sum_y_rho = 0.0;
    double sum_z_rho = 0.0;

    double volumen = (lim.x_max - lim.x_min) *
                     (lim.y_max - lim.y_min) *
                     (lim.z_max - lim.z_min);

    for (int i = 0; i < n_puntos; i++) {
        double x = random_range(lim.x_min, lim.x_max);
        double y = random_range(lim.y_min, lim.y_max);
        double z = random_range(lim.z_min, lim.z_max);

        double r = rho(x, y, z);

        sum_rho   += r;
        sum_x_rho += x * r;
        sum_y_rho += y * r;
        sum_z_rho += z * r;
    }

    *masa = volumen * (sum_rho / n_puntos);

    *cm_x = (volumen * (sum_x_rho / n_puntos)) / *masa;
    *cm_y = (volumen * (sum_y_rho / n_puntos)) / *masa;
    *cm_z = (volumen * (sum_z_rho / n_puntos)) / *masa;
}
