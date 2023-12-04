"""
1. Write a Python program to create box plots to see how each feature i.e. Sepal Length, 
Sepal Width, Petal Length, Petal Width are distributed across the three species. (Use iris.csv 
dataset) [10]
2. Use the heights and weights dataset and load the dataset from a given csv file into a 
dataframe. Print the first, last 5 rows and random 10 row [5]
"""

"""
#1
from numpy import*
from pandas import*
from matplotlib.pyplot import*
from seaborn as sns
df=read_csv("Iris.csv")
sns.boxplot(x=df["Species"],y=df["SepalLengthCm"],palette="Blues")
show()
"""

"""
#2
import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv("SOCR-HeightWeight.csv");
df.head(10);
df.tail(5);
df.sample(10);
print(df);
"""