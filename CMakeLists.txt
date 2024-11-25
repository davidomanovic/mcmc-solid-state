cmake_minimum_required(VERSION 3.14)
project(IsingModelBindings LANGUAGES CXX)
set(CMAKE_STRIP echo)

# Check for Python paths via environment variables
if(DEFINED ENV{PYTHON_EXECUTABLE})
    set(PYTHON_EXECUTABLE $ENV{PYTHON_EXECUTABLE})
endif()

if(DEFINED ENV{PYTHON_INCLUDE_DIR})
    set(PYTHON_INCLUDE_DIR $ENV{PYTHON_INCLUDE_DIR})
endif()

if(DEFINED ENV{PYTHON_LIBRARY})
    set(PYTHON_LIBRARY $ENV{PYTHON_LIBRARY})
endif()

# Forward Python paths to pybind11
add_subdirectory(src/dependencies/pybind11)

# Debug output to ensure paths are correct
message(STATUS "PYTHON_EXECUTABLE: ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIR: ${PYTHON_INCLUDE_DIR}")
message(STATUS "PYTHON_LIBRARY: ${PYTHON_LIBRARY}")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the local pybind11 directory
add_subdirectory(src/dependencies/pybind11)

# Add your bindings
pybind11_add_module(montecarlo
    src/cpp/bindings/montecarlo_bindings.cpp
    src/cpp/model/IsingModel.cpp
    src/cpp/model/Lattice.cpp
    src/cpp/model/MonteCarlo.cpp
)

# Include directories for the project
target_include_directories(montecarlo PRIVATE
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/cpp/model
    ${PROJECT_SOURCE_DIR}/src/dependencies/pybind11/include
)
