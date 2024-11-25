## Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/mcmc-solid-state.git
   cd mcmc-solid-state
   ```

2. Set Python paths or rely on autodetection by ```find_package```

For Windows
```cmd
set PYTHON_EXECUTABLE=C:\Path\To\Python\python.exe
set PYTHON_INCLUDE_DIR=C:\Path\To\Python\include
set PYTHON_LIBRARY=C:\Path\To\Python\libs\python312.lib
```

For Linux/Mac

```bash
export PYTHON_EXECUTABLE=/path/to/python
export PYTHON_INCLUDE_DIR=/path/to/python/include
export PYTHON_LIBRARY=/path/to/python/libs/python3.x.a
```

3. Build the project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

### **Debugging in CI**

```yaml
- name: Setup Python
  uses: actions/setup-python@v4
  with:
    python-version: "3.9"

- name: Configure Python Paths
  run: |
    echo "PYTHON_EXECUTABLE=$(which python3)" >> $GITHUB_ENV
    echo "PYTHON_INCLUDE_DIR=$(python3 -c 'import sysconfig; print(sysconfig.get_path(\"include\"))')" >> $GITHUB_ENV
    echo "PYTHON_LIBRARY=$(python3 -c 'import sysconfig; print(sysconfig.get_config_var(\"LIBDIR\"))')" >> $GITHUB_ENV

- name: Build Project
  run: |
    mkdir build && cd build
    cmake .. -DPYTHON_EXECUTABLE=${{ env.PYTHON_EXECUTABLE }} \
             -DPYTHON_INCLUDE_DIR=${{ env.PYTHON_INCLUDE_DIR }} \
             -DPYTHON_LIBRARY=${{ env.PYTHON_LIBRARY }}
    cmake --build .

```