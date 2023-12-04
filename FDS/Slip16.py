"""
1. Write a python program to create two lists, one representing subject names and the other 
representing marks obtained in those subjects. Display the data in a pie chart and bar chart. [10]
2. Write a python program to create a data frame for students information such as name, 
graduation percentage and age. Display average age of students, average of graduation 
percentage [5]
"""

"""
#1
import matplotlib.pyplot as plt
sub=['FDS','WT','TCS','CN']
marks=[77,89,80,92]
plt.bar(sub,marks,color="g",width=0.5,align="center",bottom=10,edgecolor="b",linewidth=2,tick_label=sub)
#plt.pie(marks,labels=sub,autopct="%1.1f%%",explode=[0.5,0.0,0.0,0.0])
plt.show()
"""

"""
#2
import pandas as pd
df=pd.DataFrame({'Name':['Ajay','Atul','Ram','Sham'],'per':[92,86,95,88],'age':[21,20,23,20]})
print("Average of Graduation :",df['per'].mean())
print("Average age of Students :",df['age'].mean())
"""