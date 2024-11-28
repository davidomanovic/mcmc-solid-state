import os, sys
sys.path.append('./lib')  # Ensure Python can find the compiled file

import numpy as np
import montecarlo as mc  # Your Ising Model module #type:ignore

temperatures = np.linspace(1.0, 25, 100)
lattices = []
labels = []

for T in temperatures:
    ising_model = mc.IsingModel(size=100, temperature=T)
    ising_model.initialize_lattice()

    # Perform Monte Carlo steps and save each lattice with its label
    for _ in range(100):
        ising_model.monte_carlo_step()
        lattice = ising_model.get_lattice()
        lattices.append(lattice)
        labels.append(0 if T < 2.5 else 1)  # Label based on temperature range

# Verify dimensions
print(f"Number of lattices: {len(lattices)}")
print(f"Number of labels: {len(labels)}")

np.savez('data/labeled_lattices.npz', lattices=lattices, labels=labels) # save simulated data as npz