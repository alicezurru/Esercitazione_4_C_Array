#include "Utils.hpp"

double dot(double *p1, double *p2, int n) {
    double prod = 0.0;
    for (int i=0;i<n;i++) {
        prod=prod+ *(p1+i) * *(p2+i);
    }
    return prod;
}
