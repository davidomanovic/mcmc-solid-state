#include "HeisenbergModel.h"
#include <cmath>
#include <numeric>

// Constructor
HeisenbergModel::HeisenbergModel(int size, double temperature, double coupling_constant, std::array<double, 3> external_field)
    : size_(size), temperature_(temperature), coupling_constant_(coupling_constant), external_field_(external_field), rng_(std::random_device{}()) {
    lattice_.resize(size, std::vector<std::array<double, 3>>(size, {1.0, 0.0, 0.0})); // Default spins pointing in x-direction
}

// Initialize the lattice with random spin directions
void HeisenbergModel::initializeLattice() {
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    for (auto& row : lattice_) {
        for (auto& spin : row) {
            spin[0] = dist(rng_);
            spin[1] = dist(rng_);
            spin[2] = dist(rng_);
            double norm = std::sqrt(dotProduct(spin, spin)); // Normalize spin
            for (auto& component : spin) {
                component /= norm;
            }
        }
    }
}

// Perform a single Monte Carlo step
void HeisenbergModel::monteCarloStep() {
    std::uniform_int_distribution<int> dist_pos(0, size_ - 1);
    std::uniform_real_distribution<double> dist_prob(0.0, 1.0);

    int x = dist_pos(rng_);
    int y = dist_pos(rng_);
    std::array<double, 3> old_spin = lattice_[x][y];

    // Generate a random new spin direction
    std::array<double, 3> new_spin = {dist_prob(rng_) * 2 - 1, dist_prob(rng_) * 2 - 1, dist_prob(rng_) * 2 - 1};
    double norm = std::sqrt(dotProduct(new_spin, new_spin));
    for (auto& component : new_spin) {
        component /= norm;
    }

    double old_energy = computeSpinEnergy(x, y);
    lattice_[x][y] = new_spin;
    double new_energy = computeSpinEnergy(x, y);

    // Metropolis criterion
    double delta_energy = new_energy - old_energy;
    if (delta_energy > 0 && std::exp(-delta_energy / temperature_) < dist_prob(rng_)) {
        lattice_[x][y] = old_spin; // Revert to old spin
    }
}

// Compute the energy of a single spin
double HeisenbergModel::computeSpinEnergy(int x, int y) const {
    const auto& spin = lattice_[x][y];
    double interaction_energy = 0.0;

    // Sum interactions with neighbors
    interaction_energy -= coupling_constant_ * dotProduct(spin, lattice_[periodicBoundary(x - 1)][y]);
    interaction_energy -= coupling_constant_ * dotProduct(spin, lattice_[periodicBoundary(x + 1)][y]);
    interaction_energy -= coupling_constant_ * dotProduct(spin, lattice_[x][periodicBoundary(y - 1)]);
    interaction_energy -= coupling_constant_ * dotProduct(spin, lattice_[x][periodicBoundary(y + 1)]);

    // Add external field contribution
    interaction_energy -= dotProduct(spin, external_field_);
    return interaction_energy;
}

// Compute the total energy of the system
double HeisenbergModel::computeEnergy() const {
    double total_energy = 0.0;
    for (int x = 0; x < size_; ++x) {
        for (int y = 0; y < size_; ++y) {
            total_energy += computeSpinEnergy(x, y);
        }
    }
    return total_energy / 2.0; // Avoid double counting
}

// Compute the total magnetization of the system
std::array<double, 3> HeisenbergModel::computeMagnetization() const {
    std::array<double, 3> total_magnetization = {0.0, 0.0, 0.0};
    for (const auto& row : lattice_) {
        for (const auto& spin : row) {
            for (int i = 0; i < 3; ++i) {
                total_magnetization[i] += spin[i];
            }
        }
    }
    for (auto& component : total_magnetization) {
        component /= (size_ * size_);
    }
    return total_magnetization;
}

// Periodic boundary condition helper
int HeisenbergModel::periodicBoundary(int index) const {
    if (index < 0) return size_ - 1;
    if (index >= size_) return 0;
    return index;
}

// Dot product helper
double HeisenbergModel::dotProduct(const std::array<double, 3>& a, const std::array<double, 3>& b) const {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// Get the lattice
const std::vector<std::vector<std::array<double, 3>>>& HeisenbergModel::getLattice() const {
    return lattice_;
}
