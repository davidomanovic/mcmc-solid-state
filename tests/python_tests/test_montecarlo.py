import montecarlo

# Create an Ising model with a 10x10 lattice and temperature of 2.5
ising = montecarlo.IsingModel(size=10, temperature=2.5)

# Initialize the lattice with random spins
ising.initialize_lattice()

# Perform some Monte Carlo steps
for step in range(100):
    ising.monte_carlo_step()

# Get and print lattice configuration
lattice = ising.get_lattice()
print("Lattice configuration:")
for row in lattice:
    print(row)

# Compute and print energy and magnetization
energy = ising.calculate_total_energy()
magnetization = ising.calculate_magnetization()
print(f"Total Energy: {energy}")
print(f"Magnetization: {magnetization}")