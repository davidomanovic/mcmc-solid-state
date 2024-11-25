import sys
sys.path.append('./src/cpp/model')

import montecarlo
import matplotlib.pyplot as plt
import numpy as np

# 10x10 grid
ising = montecarlo.IsingModel(size=10, temperature=4)

# Initialize the lattice with random spins
ising.initialize_lattice()

N = 1000

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