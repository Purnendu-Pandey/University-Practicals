"""
A) Write a Python program to create a graph to find relationship between the petal length 
and petal width.(Use iris.csv dataset) [10]
B) Write a Python program to find the maximum and minimum value of a given flattened array.[5]
"""

"""
#1
from numpy import *
from matplotlib.pyplot import *
from pandas import *
df=read_csv("Iris.csv")
data1=df['PetalLengthCm']
data2=df['PetalWidthCm']
scatter(data1,data2)
show()
"""

"""
#2
import numpy as np
data=np.array([[0,1],[2,3]])
print(data)
print("Expeceted Output :\n")
print("Original Flattened array :\n")
print("maximum value of the array:",np.max(data))
print("minimum value of the array:",np.min(data))  
"""