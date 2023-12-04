"""
1. Write a Python program for Handling Missing Value. Replace missing value of salary, age column 
with mean of that column.(Use Data.csv file).[5]
2. Write a Python program to generate a line plot of name Vs salary.[5]
3. Download the heights and weights dataset and load the dataset from a given csv file into a 
dataframe. Print the first, last 10 rows and random 20 rows also display shape of the dataset [5]
"""

"""
#1
import pandas as pd
df=pd.read_csv("data.csv");
print("Missing values:",df.fillna(0,inplace=True))
print(df)
print("..............................................")
df.fillna(0)
print(df)
print("..............................................")
mean_age=df['Age'].mean()
print("Mean Of Age:",mean_age)
print("..............................................")
mean_salary=df['Salary'].mean()
print("Mean Of Salary:",mean_salary)
print("..............................................")
df['Age'].fillna(mean_age,inplace=True)
df['Salary'].fillna(mean_salary,inplace=True)
print(df)
"""

"""
#2
import matplotlib.pyplot as plt
name=['ramesh','suresh','paresh','mahesh']
salary=[15000,20000,17000,22000]
plt.plot(name,salary,color="b")
plt.xlabel('name',color='g')
plt.ylabel('salary',color='r')
plt.show()
"""

"""
#3
import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv("SOCR-HeightWeight.csv");
df.head(10);
df.tail(10);
df.sample(20);
print(df);
print("Shape of dataframe:",df.shape);  
"""
