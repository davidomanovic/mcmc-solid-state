#ifndef LATTICE_H
#define LATTICE_H

#include <vector>
#include <random>

class Lattice {
private:
    int size; // Lattice size (NxN)
    std::vector<std::vector<int>> spins; // Spin configuration
    std::mt19937 rng; // Random number generator

public:
    Lattice(int size);

    // Periodic boundary condition
    int periodicBoundary(int index) const;

    // Initialize lattice with random spins
    void initializeRandom();

    // Flip spin at position (x, y)
    void flipSpin(int x, int y);

    // Calculate lattice energy, magnetization
    double calculateTotalEnergy() const;
    double calculateMagnetization() const;

    // Getter methods
    const std::vector<std::vector<int>>& getSpins() const;
    int getSize() const;
    int getSpin(int x, int y) const;
};

#endif // LATTICE_H
