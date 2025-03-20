#!/usr/bin/env bash
#SBATCH --job-name=catalysis_sim      # Job name
#SBATCH --output=slurm-%j.out         # Output log file
#SBATCH --error=slurm-%j.err          # Error log file
#SBATCH --nodes=1                     # Number of nodes
#SBATCH --ntasks=36                   # Number of MPI tasks
#SBATCH --cpus-per-task=1             # CPUs per task
#SBATCH --time=01:00:00               # Max runtime (HH:MM:SS)
#SBATCH --mem=30000                   # Memory in MB (30GB)
#SBATCH --partition=standard          # Adjust based on `sinfo`

# Bugfix for oneapi issue (if needed)
export FI_PROVIDER=verbs

# Load required modules
module purge  # Clears any conflicting modules
module load gcc/11.3.0
module load openmpi/4.1.3
module load lammps/20220107-mpi-openmp-plumed

# Store the LAMMPS command and input/output file names
LAMMPS_CMD='srun lmp'
INPUT_FILE='in.catalysis_11_r3'
OUTPUT_FILE='catalysis_output.out'

# Run the calculation (printing command before execution)
echo "Running $LAMMPS_CMD -in $INPUT_FILE > $OUTPUT_FILE"
$LAMMPS_CMD -in $INPUT_FILE > $OUTPUT_FILE

