"""
1. Write a Python program to draw scatter plots to compare two features of the iris dataset [10]
2. Write a Python program to create a data frame containing columns name, age , salary, 
department.Add 10 rows to the data frame. View the data frame.[5]
"""

"""
#1
from numpy import *
from matplotlib.pyplot import *
from pandas import *
df=read_csv("Iris.csv")
data1=df['SepalLengthCm']
data2=df['SepalWidthCm']
scatter(data1,data2)
show()
"""

"""
#2
import pandas as pd
import matplotlib.pyplot as plt
df=pd.DataFrame(columns=["Name","Age","Salary","Department"])
df.loc[0]=["Sankalp",33,42000,"Sales"]
df.loc[1]=["Manas",35,22000,"Marketing"]
df.loc[2]=["Om",30,48000,"Sales"]
df.loc[3]=["Raj",24,32000,"Store"]
df.loc[4]=["Rahul",32,38000,"Quality"]
df.loc[5]=["Aman",31,35000,"Sales"]
df.loc[6]=["Shwan",28,32000,"Finance"]
df.loc[7]=["Gauraj",29,62000,"Quality"]
df.loc[8]=["Sarthak",25,52000,"Store"]
df.loc[9]=["Satyam",29,25000,"Quality"]
print(df)
"""