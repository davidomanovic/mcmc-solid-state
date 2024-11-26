cmake_minimum_required(VERSION 3.14)
project(IsingModelBindings LANGUAGES CXX)

#Find python :)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE})
set(PYTHON_INCLUDE_DIR ${Python3_INCLUDE_DIRS})
set(PYTHON_LIBRARY ${Python3_LIBRARIES})

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Python interpreter and development components
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Debug output to verify Python paths
message(STATUS "Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message(STATUS "Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3_LIBRARIES: ${Python3_LIBRARIES}")

# Add pybind11 using pip-installed version
execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "pybind11 CMake directory: ${PYBIND11_CMAKE_DIR}")

find_package(pybind11 REQUIRED PATHS ${PYBIND11_CMAKE_DIR})

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
)
