# visualize_lattice.py
import matplotlib.pyplot as plt
import numpy as np

class LatticeVisualizer:
    def __init__(self, lattice):
        """
        Initialize the visualizer with a lattice array.
        Args:
            lattice (np.ndarray): 2D NumPy array representing the lattice configuration.
                                  Values should be +1 for spin up and -1 for spin down.
        """
        self.lattice = lattice
        self.rows, self.cols = lattice.shape
        self.x, self.y = np.meshgrid(np.arange(self.cols), np.arange(self.rows))

    def plot(self, title="Lattice Configuration", circle_color="gray", arrow_scale=2, arrow_alpha=1.0):
        """
        Plot the lattice with arrows and optional circles.
        Args:
            title (str): Title of the plot.
            circle_color (str): Color of the circles drawn at each lattice point.
            arrow_scale (float): Scale factor for the arrow lengths.
            arrow_alpha (float): Transparency of the arrows.
        """
        # Define arrow directions: up for +1, down for -1
        u = np.zeros_like(self.lattice)  # No horizontal movement
        v = self.lattice  # Vertical direction is based on spin value (+1 or -1)

        # Map spins to RGB colors
        colors = np.zeros((self.rows, self.cols, 3))  # Initialize an array for RGB values
        colors[self.lattice > 0] = [0, 0, 1]  # Blue for spin up (+1)
        colors[self.lattice < 0] = [1, 0, 0]  # Red for spin down (-1)

        # Create the plot
        plt.figure(figsize=(8, 8))
        plt.quiver(
            self.x,
            self.y,
            u,
            v,
            angles="xy",
            scale_units="xy",
            scale=arrow_scale,
            pivot="middle",
            color=colors.reshape(-1, 3),
            alpha=arrow_alpha
        )

        # Draw circles at the centers of the arrows
        plt.scatter(
            self.x,
            self.y,
            s=int(500 * 100/np.size(v)),
            facecolors=circle_color,
            edgecolors="black",
            linewidths=1,
            zorder=3,
            alpha=0.3,
        )

        # Invert the y-axis to match matrix indexing
        plt.gca().invert_yaxis()

        # Add gridlines and labels
        plt.xticks(np.arange(self.cols))
        plt.yticks(np.arange(self.rows))
        plt.title(title)
        plt.grid(visible=True, linestyle="--", color="gray", alpha=0.5)
        plt.show()
