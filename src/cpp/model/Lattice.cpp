#include "Lattice.h"
#include <cmath>

Lattice::Lattice(int size)
    : size(size), spins(size, std::vector<int>(size, 1)), rng(std::random_device{}()) {}

void Lattice::initializeRandom() {
    std::uniform_int_distribution<int> dist(0, 1);
    for (auto& row : spins) {
        for (auto& spin : row) {
            spin = dist(rng) == 0 ? -1 : 1; // Randomly set to +1 or -1
        }
    }
}

int Lattice::getSize() const {
    return size;
}

int Lattice::periodicBoundary(int index) const {
    if (index < 0) return size - 1;
    if (index >= size) return 0;
    return index;
}

int Lattice::getSpin(int x, int y) const {
    return spins[x][y];
}

void Lattice::flipSpin(int x, int y) {
    spins[x][y] *= -1;
}

double Lattice::calculateTotalEnergy() const {
    double energy = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int spin = spins[i][j];
            int neighborSum = spins[periodicBoundary(i - 1)][j] +
                              spins[periodicBoundary(i + 1)][j] +
                              spins[i][periodicBoundary(j - 1)] +
                              spins[i][periodicBoundary(j + 1)];
            energy -= spin * neighborSum;
        }
    }
    return energy / 2.0; // Avoid double-counting pairs
}

double Lattice::calculateMagnetization() const {
    double magnetization = 0.0;
    for (const auto& row : spins) {
        for (int spin : row) {
            magnetization += spin;
        }
    }
    return magnetization / (size * size);
}

const std::vector<std::vector<int>>& Lattice::getSpins() const {
    return spins;
}
