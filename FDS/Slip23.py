"""
Dataset Name: winequality-red.csv [15]
Write a program in python to perform following task 
a. Rescaling: Normalised the dataset using MinMaxScaler class 
b. Standardizing Data (transform them into a standard Gaussian distribution with a mean of 0 and
a standard deviation of 1)
c. Binarizing Data using we use the Binarizer class (Using a binary threshold, it is possible 
to transform our data by marking the values above it 1 and those equal to or below it, 0)
"""
"""
from pandas import*
from numpy import*
from sklearn import preprocessing
import scipy.stats as s
df=read_csv("winequality-red.csv");
print(df)
print("Rescaling Data")
print("Data scaled between 0 to 1")
data_scaler=preprocessing.MinMaxScaler(feature_range=(0,1))
data_scaled=data_scaler.fit_transform(df)
print("Min Max Scaled data")
print("------------------------------")
print(data_scaled.round(2))
print("Standardizing data")
arr=array(df)
print(arr)
print("initial mean=",s.tmean(arr).round(2))
print("initial standard devetion=",round(arr.std(),2))
x_scaled=preprocessing.scale(arr)
x_scaled.mean(axis=0)
x_scaled.std(axis=0)
print("standardizing data =\n",x_scaled.round(2))
print("scaling mean=",s.tmean(x_scaled).round(2))
print("sscaling standard deviation :=",round(x_scaled.std(),2))
data_binarized=preprocessing.Binarizer(threshold=5).transform(df)
print("Binarized Data")
print("------------------------------")
print(data_binarized)
"""