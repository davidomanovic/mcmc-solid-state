from setuptools import setup, find_packages
import platform
import os

# Identify the compiled file based on the platform
compiled_file = "lib/montecarlo"
if platform.system() == "Windows":
    compiled_file += ".cp312-win_amd64.pyd"  # Update for other Python versions if needed
elif platform.system() == "Linux":
    compiled_file += ".so"
elif platform.system() == "Darwin":
    compiled_file += ".so"

# Ensure the compiled file exists
if not os.path.exists(compiled_file):
    raise FileNotFoundError(f"Compiled file {compiled_file} not found. Please build it first.")

setup(
    name="montecarlo",
    version="0.1",
    description="Monte Carlo simulations for the Ising Model",
    packages=find_packages(where="src/python"),  # Finds Python packages in src/python
    package_dir={"": "src/python"},  # Python root is in src/python
    py_modules=["montecarlo"],  # Include the compiled file as a module
    data_files=[("lib", [compiled_file])],  # Ensure the compiled file is included
    include_package_data=True,
    install_requires=["numpy", "matplotlib"],  # Add dependencies here
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires=">=3.7",  # Minimum Python version required
)
