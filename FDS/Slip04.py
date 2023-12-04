"""
1. Generate a random array of 50 integers and display them using a line chart, scatter 
plot, histogram and box plot. Apply appropriate color, labels and styling options. [10]
2. Write a Python program to print the shape, number of rows-columns, data types, 
feature names and the description of the data(Use User_Data.csv).[5]
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
import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv("data.csv")
print("Shape of data:",df.shape);
print("No of Rows and Columns:",df.size);
print("Data Types:",df.dtypes);
print("Feature Names:",df.info());
print("Description Of Data\n",df.describe());
"""