/*
Q1) Write a Program to illustrate multilevel Inheritance such that country is inherited from 
continent. State is inherited from country. Display the place, state, country and continent.
*/
import java.util.Scanner;
class continent
{
	String cname;
	continent(String cname)
	{
	   this.cname=cname;
	}
}
class country extends continent
{
	String coname;
	country(String cname,String coname)
	{
	   super(cname);
	   this.coname=coname;
	}
}
class state extends country
{	
	 String sname;
	 state(String cname,String coname,String sname)
	 {
	      super(cname,coname);
	      this.sname=sname;
	 }
}
class Slip20
{
	public static void main(String[] args)
	{
	    Scanner s=new Scanner(System.in);
	    System.out.println("Enter the Continent name:");
	    String cname=s.nextLine();
	    
	    System.out.println("Enter the Country name:");
	    String coname=s.nextLine();
	    
	    System.out.println("Enter the state name:");
	    String sname=s.nextLine();
	    
	    System.out.println("Enter the palce name:");
	    String pname=s.nextLine();
	    
	    System.out.println("-----MultiHeritance-----:");
	    System.out.println("Continent:"+cname);
	    System.out.println("Contry:"+coname);	
	    System.out.println("State:"+sname);	
	    System.out.println("Place:"+pname);	
	 }
}

/*
Q2) Write a package for Operation, which has two classes, Addition and Maximum. Addition has 
two methods add () and subtract (), which are used to add two integers and subtract two,
float values respectively. Maximum has a method max () to display the maximum of two integers
*/

import Operation.Addition;
import Operation.Maximum;
import java.util.Scanner;

public class S20Q2 {
    public static void main(String[] args) 
		{
        Scanner scanner = new Scanner(System.in);
        Addition addition = new Addition();
        Maximum maximum = new Maximum();

        System.out.print("Enter the first integer: ");
        int num1 = scanner.nextInt();

        System.out.print("Enter the second integer: ");
        int num2 = scanner.nextInt();


        System.out.print("Enter the first float: ");
        float num3 = scanner.nextFloat();

        System.out.print("Enter the second float: ");
        float num4 = scanner.nextFloat();

        System.out.println("\nAddition result: " + addition.add(num1, num2));
        System.out.println("Subtraction result: " + addition.subtract(num3, num4));
        System.out.println("Maximum result: " + maximum.max(num1, num2));

        scanner.close();
    }
}
