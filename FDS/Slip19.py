"""
Write a Python program [15]
1. To create a dataframe containing columns name, age and percentage. Add 10 rows to the 
dataframe. View the dataframe. 
2. To print the shape, number of rows-columns, data types, feature names and the description of 
the data 
3. To Add 5 rows with duplicate values and missing values. Add a column ‘remarks’ with empty 
values. Display the data
"""

"""
import pandas as pd
import matplotlib.pyplot as plt
df=pd.DataFrame(columns=["Name","Age","Percentage"])
df.loc[0]=["Sankalp",21,94]
df.loc[1]=["Manas",20,94]
df.loc[2]=["Om",19,94]
df.loc[3]=["Raj",22,94]
df.loc[4]=["Rahul",19,74]
df.loc[5]=["Aman",20,84]
df.loc[6]=["Shwan",20,82]
df.loc[7]=["Gauraj",23,90]
df.loc[8]=["Sarthak",21,72]
df.loc[9]=["Satyam",21,88]
print(df)

print("Shape of data:",df.shape);
print("No of Rows and Columns:",df.size);
print("Data Types:",df.dtypes);
print("Feature Names:",df.info());
print("Description of data ",df.describe())

df.loc[10]=["Purnendu",20,None]
df.loc[11]=["Shagun",20,82]
df.loc[12]=["Darshika",None,90]
df.loc[13]=["Shreyash",21,72]
df.loc[14]=["Shobhit",21,None]
df["remark"]=None
print(df)
"""