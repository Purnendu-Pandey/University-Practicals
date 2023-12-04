"""
1. Write a Python program to create a Pie plot to get the frequency of the three species of 
the Iris data (Use iris.csv) [10]
2. Write a Python program to view basic statistical details of the data.(Use wineequality-red.csv)[5]
"""

"""
#1
from pandas import *
from numpy import *
from matplotlib.pyplot import *
df=read_csv("Iris.csv")
data1=df['Species']
data2=df['Id']
pie(data2,labels=data1)
show()
"""
"""
#2
from pandas import*
from numpy import*
df=read_csv("winequality-red.csv")
print("Statistical details of data frame")
print(df.describe())
"""