"""
Write python program to [15]
1. Generate a random array of 50 integers and display them using a line chart, scatter plot, 
histogram and box plot. Apply appropriate color, labels and styling options. 
2. Create two lists, one representing subject names and the other representing marks obtained in 
those subjects. Display the data in bar chart.
"""

"""
#1
import numpy as np
import matplotlib.pyplot as plt
x=np.random.rand(50)
y=np.random.rand(50)
#plt.plot(x,y)
#plt.grid(True)
#plt.hist(x,color="m",linewidth=2,edgecolor="b",bins=30,alpha=0.6)
#plt.boxplot(x)
plt.scatter(x,y,color="m",marker="+")
plt.show()
"""

"""
#2
import matplotlib.pyplot as plt
sub=['FDS','WT','TCS','CN']
marks=[77,89,80,92]
plt.bar(sub,marks,color="g",width=0.5,align="center",bottom=10,edgecolor="b",linewidth=2,tick_label=sub)
plt.show()
"""
