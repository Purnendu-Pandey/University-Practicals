"""
A) Write a Python Numpy program to compute the weighted average along the specified 
axis of a given flattened array. [10]
B) Write a Python program to view basic statistical details of the data (Use advertising.csv)[5]
"""
"""
#2
from pandas import*
from numpy import*
df=read_csv("advertising.csv")
print("Statistical details of data frame")
print(df.describe())
"""