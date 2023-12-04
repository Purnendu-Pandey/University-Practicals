/*
Q1)Write a program to accept a file name from command prompt, if the file exits then display 
number of words and lines in that file.
*/
import java.io.*;
import java.util.*;
class Slip13
{
public static void main(String args[])throws IOException 
{
	String filename=args[0];
	File file=new File(filename);
	int wc=0,lc=0;
	FileReader read=new FileReader(filename);
	BufferedReader bf=new BufferedReader(read);
	if(file.exists())
	{
		String line;
		while((line=bf.readLine())!=null)
		{
			lc++;
			for(int i=0; i<line.length(); i++)
			{
			if((line.charAt(i))==' ')
			{
				wc++;
			}
		        }
		        wc+=1;
		}
		System.out.println("No of lines in file:"+lc);
		System.out.println("No of words in file:"+wc);
	}
	else
	{
	 System.out.println("File Not found....");
	}
}
}

/* 
Q2)Write a program to display the system date and time in various formats shown below:
Current date is : 31/08/2021
Current date is : 08-31-2021
Current date is : Tuesday August 31 2021
Current date and time is : Fri August 31 15:25:59 IST 2021
Current date and time is : 31/08/21 15:25:59 PM +0530
*/

import java.text.SimpleDateFormat;
import java.util.Date;
class Slip13
{
	public static void main(String[] args)
	{
	    Date currentDate=new Date();
	    SimpleDateFormat s1=new SimpleDateFormat("dd/mm/yyyy");
	    System.out.println("Current date is "+s1.format(currentDate));
	    
	    SimpleDateFormat s2=new SimpleDateFormat("mm/dd/yyyy");
	    System.out.println("Current date is "+s2.format(currentDate));
	    
	    SimpleDateFormat s3=new SimpleDateFormat("EEEEEE MMMM dd yyyy");
	    System.out.println("Current date is "+s3.format(currentDate));
	    
	    SimpleDateFormat s4=new SimpleDateFormat("E MMMM dd HH:mm:ss z yyyy");
	    System.out.println("Current date and time is "+s4.format(currentDate));
	    
	    SimpleDateFormat s5=new SimpleDateFormat("dd/mm/yyyy HH:mm:ss a Z");
	    System.out.println("Current date and time is "+s5.format(currentDate));
    }
}