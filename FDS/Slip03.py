"""
1. Write a Python program to create box plots to see how each feature i.e. Sepal Length, 
Sepal Width, Petal Length, Petal Width are distributed across the three species. (Use 
iris.csv dataset) [10]
2. Write a Python program to view basic statistical details of the data (Use Heights and 
Weights Dataset)[5]
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
from pandas import*
from numpy import*
df=read_csv("SOCR-HeightWeight.csv")
print("Statistical details of data frame")
print(df.describe())
"""