#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "IsingModel.h"

namespace py = pybind11;

// Bindings for the IsingModel class and its related functionality
PYBIND11_MODULE(montecarlo, m) {
    m.doc() = "Python bindings for the Ising Model simulation using pybind11";

    // Bind the IsingModel class
    py::class_<IsingModel>(m, "IsingModel")
        .def(py::init<int, double>(), "Initialize the Ising Model",
             py::arg("size"), py::arg("temperature"))
        .def("initialize_lattice", &IsingModel::initializeLattice, "Initialize the lattice with random spins")
        .def("monte_carlo_step", &IsingModel::monteCarloStep, "Perform a single Monte Carlo step")
        .def("calculate_total_energy", &IsingModel::calculateTotalEnergy, "Calculate the total energy of the system")
        .def("calculate_magnetization", &IsingModel::calculateMagnetization, "Calculate the total magnetization of the system")
        .def("set_temperature", &IsingModel::setTemperature, "Set the system temperature", py::arg("temperature"))
        .def("get_lattice", [](const IsingModel& model) {
            const auto& lattice = model.getLattice().getSpins();
            return lattice; // Return the lattice as a Python list of lists
        }, "Get the lattice configuration as 2D list");

    // Bind the Lattice class (optional, for direct lattice access)
    py::class_<Lattice>(m, "Lattice")
        .def("get_spin", &Lattice::getSpin, "Get the spin at a specific position",
             py::arg("x"), py::arg("y"))
        .def("get_size", &Lattice::getSize, "Get the size of the lattice");
}
