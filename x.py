import numpy as np
import matplotlib.pyplot as plt

data_points = np.array([-2, -1, 0, 1, 2])  # Sample data
probabilities = np.ones_like(data_points) / len(data_points)  # Equal probability

plt.stem(data_points, probabilities, basefmt="b-", use_line_collection=True)
plt.xlabel('x')
plt.ylabel('Probability')
plt.title('Empirical Distribution')
plt.grid()
plt.show()
