/*
//Q1) 
//Write a program to accept ‘n’ name of cities from the user and sort them in ascending order.
*/
import java.util.Scanner;
import java.util.Arrays;
class Slip03
{
	public static void main(String[] args)
	{
		  int n,i;
		  Scanner s=new Scanner(System.in);
		  System.out.println("Enter no of cities :");
		  n=s.nextInt();
		  s.nextLine();
		  String[] a=new String[n];
		  System.out.println("Enter cities :");
		  for(i=0;i<n;i++)
		  {
		    	System.out.println("Enter cities :"+(i+1));
	    		a[i]=s.nextLine();
		  }		
		  Arrays.sort(a);
	  	System.out.println("\nCities in ascending order:");
	  	for(i=0;i<n;i++)
			System.out.println(a[i]);
	}
}
/*
//Q2) 
//Define a class patient (patient_name, patient_age, patient_oxy_level,patient_HRCT_report).
//Create an object of patient. Handle appropriate exception while patient oxygen level less than
//95% and HRCT scan report greater than 10, then throw user defined Exception “Patient is Covid
//Positive(+) and Need to Hospitalized” otherwise display its information.
*/
import java.util.*;
class patient 
{
	String name;
	int id;
	int hrct;
	int oxylevel;
	patient(String name,int id,int hrct,int oxylevel)
	{
	    this.name=name;
      this.id=id;
      this.hrct=hrct;
		  this.oxylevel=oxylevel;
	}
}
class Slip03
{
	public static void main(String args[])
	{
	    	int n,i;
	  		Scanner sc=new Scanner(System.in);
   	    System.out.println("Enter The Number of Patient :");
       	n=sc.nextInt();
       	patient []a=new patient[n];
       	for(i=0;i<n;i++)
        {
     	    	System.out.println("Enter the Details of Patient :"+(i+1));
          	System.out.println("Enter the Name :");
       	  	String name=sc.next();
         		System.out.println("Enter the id :");
         		int id=sc.nextInt();
         		System.out.println("Enter the hrct report :");
						int hrct=sc.nextInt();
						System.out.println("Enter the oxygen level :");
            int oxylevel=sc.nextInt();
						a[i]=new patient(name,id,hrct,oxylevel);
	    	}
	    for(i=0;i<n;i++)
	    {
	    	if(a[i].oxylevel <95 && a[i].hrct >10)
	    	{
	    	    try
	    	    {
	    	        throw new NullPointerException();
	    	    }
	            catch(Exception e)
	            {
	            	System.out.println("Patient is covid positive and need to hosptalize");
	            }
	        }
	        else
	        {
	            System.out.println("Enter the Patient Name :"+a[i].name);
	            System.out.println("Enter the Patient Id :"+a[i].id);
	            System.out.println("Enter the Patient Hrct report :"+a[i].hrct);
	            System.out.println("Enter the Patient oxygen level :"+a[i].oxylevel);
	        }
	     }
	 }
}
