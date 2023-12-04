"""
A) Generate a random array of 50 integers and display them using a line chart, scatter plot. 
Apply appropriate color, labels and styling options. [5]
B) Create two lists, one representing subject names and the other representing marks 
obtained in those subjects. Display the data in a pie chart. [5]
C) Write a program in python to perform following task (Use winequality-red.csv ) [5]
Import Dataset and do the followings: 
a) Describing the dataset 
b) Shape of the dataset 
c) Display first 3 rows from dataset
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
plt.pie(marks,labels=sub,autopct="%1.1f%%",explode=[0.5,0.0,0.0,0.0])
plt.show()
"""

"""
#3
import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv("winequality-red.csv")
print("Description Of Data\n",df.describe());
print("Shape of data:",df.shape);
print("No of Rows and Columns:",df.size);
"""
