"""
Import dataset “iris.csv”. 
1. Write a Python program to create a Bar plot to get the frequency of the three species of the
Iris data.[10]
2. Write a Python program to create a histogram of the three species of the Iris data. [5]
"""
"""
#1
from pandas import *
from numpy import *
from matplotlib.pyplot import * 
df=read_csv("Iris.csv")
data1=df['Species']
data2=df['Id']
bar(data1,data2)
show()
"""
"""
#2
from pandas import *
from numpy import *
from matplotlib.pyplot import *
df=read_csv("Iris.csv")
data=df['Species']
hist(data,edgecolor="k",linewidth=2,bins=3,alpha=0.8)
show()  
"""