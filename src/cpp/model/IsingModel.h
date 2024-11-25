#ifndef ISINGMODEL_H
#define ISINGMODEL_H

#include "Lattice.h"
#include "MonteCarlo.h"

class IsingModel {
private:
    Lattice lattice;
    MonteCarlo monteCarlo;

public:
    IsingModel(int size, double temperature);

    // Initialize lattice
    void initializeLattice();

    // Perform a single Monte Carlo step
    void monteCarloStep();

    // Calculate total energy of the system
    double calculateTotalEnergy();

    // Calculate total magnetization of the system
    double calculateMagnetization();

    // Get the lattice configuration
    const Lattice& getLattice() const;

    // Set temperature for the system
    void setTemperature(double temp);
};

#endif // ISINGMODEL_H
