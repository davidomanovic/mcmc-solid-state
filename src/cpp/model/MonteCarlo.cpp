#include "MonteCarlo.h"
#include <cmath>

MonteCarlo::MonteCarlo(double temperature)
    : temperature(temperature), rng(std::random_device{}()), dist(0.0, 1.0) {}

void MonteCarlo::performStep(Lattice& lattice) {
    std::uniform_int_distribution<int> posDist(0, lattice.getSize() - 1);

    int size = lattice.getSize();
    for (int step = 0; step < size * size; ++step) {
        int x = posDist(rng);
        int y = posDist(rng);

        int spin = lattice.getSpin(x, y);
        int neighborSum = lattice.getSpin(x, lattice.periodicBoundary(y - 1)) +
                          lattice.getSpin(x, lattice.periodicBoundary(y + 1)) +
                          lattice.getSpin(lattice.periodicBoundary(x - 1), y) +
                          lattice.getSpin(lattice.periodicBoundary(x + 1), y);
        int deltaE = 2 * spin * neighborSum;

        if (deltaE <= 0 || dist(rng) < std::exp(-deltaE / temperature)) {
            lattice.flipSpin(x, y);
        }
    }
}

void MonteCarlo::setTemperature(double temp) {
    temperature = temp;
}
