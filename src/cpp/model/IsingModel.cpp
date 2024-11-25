#include "IsingModel.h"

IsingModel::IsingModel(int size, double temperature)
    : lattice(size), monteCarlo(temperature) {}

void IsingModel::initializeLattice() {
    lattice.initializeRandom();
}

void IsingModel::monteCarloStep() {
    monteCarlo.performStep(lattice);
}

double IsingModel::calculateTotalEnergy() {
    return lattice.calculateTotalEnergy();
}

double IsingModel::calculateMagnetization() {
    return lattice.calculateMagnetization();
}

const Lattice& IsingModel::getLattice() const {
    return lattice;
}

void IsingModel::setTemperature(double temp) {
    monteCarlo.setTemperature(temp);
}
