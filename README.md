## Setup Instructions

### Prerequisites
1. Install [CMake](https://cmake.org/) (version 3.14 or higher).
2. Install a C++ compiler:
   - GCC or Clang on Linux/macOS.
   - MSVC or MinGW-w64 on Windows.
3. Python 3.8+ installed with pip.

### Installing Dependencies with vcpkg
1. Clone and set up vcpkg:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh # Linux/macOS
   .\bootstrap-vcpkg.bat # Windows
   
2. Install pybind11
   ```bash
   ./vcpkg install pybind11
   ```

3. Set up vcpkg for your project
   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake ..
   ```
### Build instructions
Create build directory, run CMake, build project and test python bindings:
```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
python -c "import montecarlo; print(montecarlo.IsingModel(10,2.5).get_lattice())"
```
