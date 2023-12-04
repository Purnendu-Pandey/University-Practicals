"""
A) Write a python program to Display column-wise mean, and median for SOCRHeightWeight dataset. [10]
B) Write a python program to compute sum of Manhattan distance between all pairs of 
points.[5]
"""

"""
#1
import pandas as pd
import numpy as np
import scipy.stats as s
df=pd.read_csv("SOCR-HeightWeight.csv")
print("mean")
print("SpealLengthCm mean : ",s.tmean(df["SepalLengthCm"]).round(2))
print("SpealWidthCm mean : ",s.tmean(df["SepalWidthCm"]).round(2))
print("PetalLengthCm mean : ",s.tmean(df["PetalLengthCm"]).round(2))
print("PetalWidthCm mean : ",s.tmean(df["PetalWidthCm"]).round(2))

print("median")
print("SpealLengthCm median : ",np.median(df["SepalLengthCm"]).round(2))
print("SpealWidthCm median: ",np.median(df["SepalWidthCm"]).round(2))
print("PetalLengthCm median: ",np.median(df["PetalLengthCm"]).round(2))
print("PetalWidthCm median : ",np.median(df["PetalWidthCm"]).round(2))
"""

"""
#2
def dist(x,y,n):
    sum=0
    for i in range (n):
         for j in range(i+1,n):
             sum+=(abs(x[i]-x[j])+abs(y[i]-y[j]))
    return sum
x=[-1,1,3,2]
y=[5,6,5,3]
n=len(x)
print("Sum of marhattan distance :",dist(x,y,n))
"""