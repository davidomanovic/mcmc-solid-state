#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "Lattice.h"
#include <random>

class MonteCarlo {
private:
    double temperature; // System temperature
    std::mt19937 rng; // Random number generator
    std::uniform_real_distribution<double> dist; // Uniform distribution for Metropolis

public:
    MonteCarlo(double temperature);

    // Perform one Monte Carlo step on the lattice
    void performStep(Lattice& lattice);

    // Set temperature
    void setTemperature(double temp);
};

#endif // MONTECARLO_H
