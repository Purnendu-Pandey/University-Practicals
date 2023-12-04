"""
Q.2) Write a program in python to perform following task : [15]
Standardizing Data (transform them into a standard Gaussian distribution with a mean 
of 0 and a standard deviation of 1) (Use winequality-red.csv)
"""

"""
from pandas import*
from numpy import*
from sklearn import preprocessing
import scipy.stats as s
df=read_csv("winequality-red.csv");
print(df)
print("\nStandardizing data")
arr=array(df)
print(arr)
print("\n initial mean=",s.tmean(arr).round(2))
print("\n initial standard devetion=",round(arr.std(),2))
x_scaled=preprocessing.scale(arr)
x_scaled.mean(axis=0)
x_scaled.std(axis=0)
print("\n standardizing data =\n",x_scaled.round(2))
print("\n scaling mean=",s.tmean(x_scaled).round(2))
print("\n scaling standard deviation :=",round(x_scaled.std(),2))
"""