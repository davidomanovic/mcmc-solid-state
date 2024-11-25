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

    // Get the size of the lattice
    int getSize() const;

    // Access spin at a specific position
    int getSpin(int x, int y) const;

    // Flip spin at position (x, y)
    void flipSpin(int x, int y);

    // Calculate total energy of the lattice
    double calculateTotalEnergy() const;

    // Calculate total magnetization of the lattice
    double calculateMagnetization() const;

    // Getterrr
    const std::vector<std::vector<int>>& getSpins() const;

};

#endif // LATTICE_H
