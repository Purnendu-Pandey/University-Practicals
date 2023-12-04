"""
A) Generate a random array of 50 integers and display them using a line chart, scatter plot, 
histogram and box plot. Apply appropriate color, labels and styling options. [10]
B) Add two outliers to the above data and display the box plot [5]
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
import numpy as np
import matplotlib.pyplot as plt
x=np.random.rand(50)
arr1=np.append(x,[2,3])
plt.boxplot(arr1)
plt.show()  
"""