# **Markov Chain Monte Carlo for Solid State Physics**

This project implements **Markov Chain Monte Carlo (MCMC)** methods to simulate and study systems in **solid-state physics** using **statistical physics** principles. The project focuses on modeling and analyzing the behavior of physical systems, such as the **Ising model**, and provides tools to integrate **machine learning algorithms** for extracting insights from simulation data.

<div align="center">
    
</div>

<p align="center">
  <img src="https://github.com/davidomanovic/mcmc-solid-state/blob/main/output/spin_lattice.png" alt="SpinLattice" width="35%">
  <img src="https://github.com/davidomanovic/mcmc-solid-state/blob/main/output/feature_importance.png" alt="Features" width="44.5%">

</p>


## **Overview**
The project is designed to:
- Simulate **physical phenomena** using Monte Carlo methods.
- Model systems like the **Ising model** on a lattice to study magnetism and phase transitions.
- Visualize lattice configurations and statistical quantities like magnetization and energy in Python.
- Provide a flexible platform for extending simulations with **machine learning algorithms** for predictive and exploratory analysis.

### **Features**
- **C++ Backend**: Computationally efficient implementation of simulation algorithms for lattice models.
- **Python Integration**: Use `pybind11` to expose C++ functionality for Python users.
- **Visualization**: Easy-to-use tools in Python for visualizing lattice configurations and statistical properties.
- **Future Machine Learning Integration**: Framework for training models on simulation results.

---

## **Project Goals**
1. **Simulate Physical Systems**:
   - Implement MCMC algorithms for models like the **Ising model** to explore phase transitions, magnetization, and energy fluctuations.
   - Support for **lattice-based statistical physics models**.

2. **Machine Learning for Physics** (Planned):
   - Train models to learn properties of physical systems from simulation data.
   - Predict behaviors like critical temperatures or classify phases of matter.

3. **Visualization**:
   - Visualize lattice configurations (e.g., spin alignment in the Ising model).
   - Plot statistical quantities (e.g., magnetization vs. temperature).

---

## **Installation**

### **Prerequisites**
- **C++ Compiler**:
  - GCC, Clang, or MSVC with support for C++17 or higher.
- **CMake** (3.14 or higher)
- **Python** (3.8 or higher)
- Required Python libraries: `matplotlib`, `numpy`, `pybind11`.

### **Setup Instructions**
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/mcmc-solid-state.git
   cd mcmc-solid-state
   
2. Configure and build the project:
   ```bash
   mkdir build
   cd build
   cmake .. -DPYTHON_EXECUTABLE=$(which python3)
   cmake --build .

3. Install dependencies for Python and my C++ compiled library (root directory)
   ```bash
   pip install -r requirements.txt
   pip install -e .

