import os, sys
sys.path.append('./lib')
sys.path.append('./src/python/analysis')

import montecarlo # type: ignore
from visualize_lattice import LatticeVisualizer # type: ignore
import matplotlib.pyplot as plt
import numpy as np

ising = montecarlo.IsingModel(size=10, temperature=5)
ising.initialize_lattice()

N = 100

# Perform some MCMC
for step in range(N):
    ising.monte_carlo_step()

# Get and print lattice configuration
lattice = np.array(ising.get_lattice())  
# Compute and print energy and magnetization
energy = ising.calculate_total_energy()
magnetization = ising.calculate_magnetization()
print(f"Total Energy: {energy}")
print(f"Magnetization: {magnetization}")

# Plot the lattice
visualize = LatticeVisualizer(lattice)
visualize.plot(title="Spin Lattice",circle_color="gray",arrow_scale=2,arrow_alpha=1.0)