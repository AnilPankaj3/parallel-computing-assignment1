import matplotlib.pyplot as plt
import numpy as np

spA = [0.41,0.87,0.09,0.25,0.66,0.77,0.75,0.83,0.10,0.20,0.30]
spB = [0.44,0.79,0.65,0.22,0.16,0.75,0.67,0.44,0.10,0.20,0.20]

total_time = [0.024000,0.037000,0.022000,0.018000,0.030000,0.037000,0.044000,0.030000,0.014000,0.025000,0.040000]

# Create the plot spA vs total_time
plt.plot(total_time,spA,'ro',label = "spA")
plt.plot(total_time,spB,'go', label = "spB")

# show a legend on the plot
plt.legend()
#To give a title to the plot
plt.title('sparsity of matrix A & B vs total_time')
plt.xlabel('time')
plt.ylabel('spA & spB')
plt.savefig('sparsity_graph.png')

# Show the plot
plt.show()