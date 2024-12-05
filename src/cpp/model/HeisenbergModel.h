#ifndef HEISENBERGMODEL_H
#define HEISENBERGMODEL_H

#include <vector>
#include <random>
#include <array>

class HeisenbergModel {
public:
    HeisenbergModel(int size, double temperature, double coupling_constant = 1.0, std::array<double, 3> external_field = {0.0, 0.0, 0.0});

    void initializeLattice();    // Initialize the lattice with random spin vectors
    void monteCarloStep();    // Perform a single Monte Carlo step
    const std::vector<std::vector<std::array<double, 3>>>& getLattice() const; // Get the lattice spins
    double computeEnergy() const;
    std::array<double, 3> computeMagnetization() const;

private:
    int size_;
    double temperature_;
    double coupling_constant_;
    std::array<double, 3> external_field_;
    std::vector<std::vector<std::array<double, 3>>> lattice_; // 3D spin vectors
    std::mt19937 rng_; // Random number generator

    // Helper functions
    int periodicBoundary(int index) const;
    double dotProduct(const std::array<double, 3>& a, const std::array<double, 3>& b) const;
    double computeSpinEnergy(int x, int y) const;
};

#endif // HEISENBERG_MODEL_H
