## Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/davidomanovic/mcmc-solid-state.git
   cd mcmc-solid-state
   ```

2. Build the C++ library, or just use my compiled one
  ```bash
  mkdir build
  cd build
  cmake .. -DPYTHON_EXECUTABLE=$(which python3)
  cmake --build .
  ```


4. Install my compiled Python package 

  ```bash
  pip install -e .
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
