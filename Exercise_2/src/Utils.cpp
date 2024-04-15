#include "Utils.hpp"

double dot(const double* const& p1, const double* const& p2,const unsigned int n) {
    double prod = 0.0;
    for (unsigned int i=0;i<n;i++) {
        prod=prod+ p1[i] * p2[i];
    }
    return prod;
}
