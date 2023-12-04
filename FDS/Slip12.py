"""
1. Generate a random array of 50 integers and display them using a line chart, scatter plot, 
histogram and box plot. Apply appropriate color, labels and styling options. [10]
2. Write a Python program to create data frame containing column name, salary, department 
add 10 rows with some missing and duplicate values to the data frame. Also drop all null and 
empty values. Print the modified data frame.[5]
"""

"""
#1
import numpy as np
import matplotlib.pyplot as plt
x=np.random.rand(50)
y=np.random.rand(50)
#plt.plot(x,y)
#plt.grid(True)
#plt.hist(x,color="m",linewidth=2,edgecolor="b",bins=30,alpha=0.6)
#plt.boxplot(x)
plt.scatter(x,y,color="m",marker="+")
plt.show()
"""

"""

import pandas as pd
import matplotlib.pyplot as plt
df=pd.DataFrame(columns=["Name","Age","Salary","Department"])
df.loc[0]=["Sankalp",33,42000,"IT"]
df.loc[1]=["Manas",35,None,"IT"]
df.loc[2]=["Om",30,48000,"IT"]
df.loc[3]=["Raj",24,None,"IT"]
df.loc[4]=["Rahul",32,38000,"IT"]
df.loc[5]=["Aman",None,35000,"IT"]
df.loc[6]=["Shwan",28,25000,"IT"]
df.loc[7]=["Gauraj",None,62000,"IT"]
df.loc[8]=["Sarthak",25,None,"IT"]
df.loc[9]=["Satyam",29,25000,"IT"]
print(df.dropna())
"""