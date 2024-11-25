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

# Get the dimensions of the lattice
rows, cols = lattice.shape

# Create a grid of coordinates
x, y = np.meshgrid(np.arange(cols), np.arange(rows))

# Define arrow directions: up for +1, down for -1
u = np.zeros_like(lattice)  # No horizontal movement
v = lattice  # Vertical direction is based on spin value (+1 or -1)

# Create the plot
plt.figure(figsize=(8, 8))
plt.quiver(x, y, u, v, angles='xy', scale_units='xy', scale=2, pivot='middle', color="black")
plt.scatter(x, y, s=500, facecolors='blue', edgecolors='black', linewidths=1, zorder=3, alpha=0.5)
plt.gca().invert_yaxis()  # Invert y-axis to align with matrix indexing
plt.xticks(np.arange(cols))
plt.yticks(np.arange(rows))
plt.title("Lattice Configuration (Up and Down Spins)")
plt.grid(visible=True, linestyle="--", color="gray", alpha=0.5)
plt.show()