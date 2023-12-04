/*
Q1) Write a program to accept a number from the user, if number is zero then throw user defined 
exception “Number is 0” otherwise check whether no is prime or not (Use static keyword).
*/
import java.io.*;
import java.util.*;

public class Slip14
{
	public static void main(String[] args)
	{
	   	Scanner sc = new Scanner(System.in);
		  int num;
		  int flag = 0, i;
		  int m;
		  
			System.out.print("Enter the number  : ");
		  num = sc.nextInt();
		  m = num / 2;
		  try
			{
			if (num!=0)
			{
				if (num <= 2)
					System.out.println(num + " is not prime number");
				else
				{
					for (i=2;i<=m;i++)
					{
						if (num % i==0)
						{
							System.out.println(num + " is not prime number");
							flag = 1;
							break;
						}
					}
					if (flag == 0)  
					{
						System.out.println(num + " is prime number");
					}
				}
			} else
				throw new  NullPointerException();
		}

		catch (Exception e) 
		{
			System.out.print("\n Number  is 0 : ");
		}

	}
}

/*
Q2)Write a Java program to create a Package “SY” which has a class SYMarks (members–ComputerTotal,
MathsTotal,and ElectronicsTotal) Create another package TY which has a class TYMarks
(members – Theory, Practicals).Create ‘n’ objects of Student class(having rollNumber,name,SYMarks & TYMarks)
Add the marks of SY and TY computer subjects and calculate the Grade 
(‘A’ for >= 70, ‘B’ for >= 60 ‘C’ for >= 50, Pass Class for > =40 else‘FAIL’) and display the result 
of the student in proper format.
*/

//SYMarks
package SY;
import java.util.Scanner;
public class SYMarks 
{
    public int com, math, elect;

    public void get(Scanner sc) 
		{
        System.out.println("\nEnter TY marks");
        System.out.print("Computer marks out of 100: ");
        com = sc.nextInt();

        System.out.print("Maths marks out of 100: ");
        math = sc.nextInt();

        System.out.print("Electronics marks out of 100: ");
        elect = sc.nextInt();
    }
}
//TYMarks
package TY;
import java.util.Scanner;

public class TYMarks 
{
    public int theory, pract;

    public void get(Scanner sc) 
		{
        System.out.println("\nEnter SY marks");
        System.out.print("Theory marks out of 100: ");
        theory = sc.nextInt();

        System.out.print("Practical marks out of 100: ");
        pract = sc.nextInt();
    }
}
import SY.SYMarks;
import TY.TYMarks;
import java.util.Scanner;

public class Slip14
{
    public int rollno;
    public String name, grade;
    public float total, perc, sytotal, tytotal;

    public void get(Scanner sc) {
        System.out.print("\nEnter the roll no.: ");
        rollno = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter the name: ");
        name = sc.nextLine();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the number of students: ");
        int n = sc.nextInt();

        S14Q2 s[] = new S14Q2[n];
        SYMarks sy[] = new SYMarks[n];
        TYMarks ty[] = new TYMarks[n];

        for(int i=0; i<n; i++) {
            s[i] = new S14Q2();
            sy[i] = new SYMarks();
            ty[i] = new TYMarks();

            s[i].get(sc);
            sy[i].get(sc);
            ty[i].get(sc);

            s[i].sytotal = sy[i].com + sy[i].math + sy[i].elect;
            s[i].tytotal = ty[i].theory + ty[i].pract;
            s[i].total = s[i].sytotal + s[i].tytotal;
            s[i].perc = (s[i].total / 500) * 100;
            s[i].perc = Float.parseFloat(String.format("%.2f",s[i].perc));

            if(s[i].perc >= 70)
                s[i].grade = "A";
            else if(s[i].perc >= 60)
                s[i].grade = "B";
            else if(s[i].perc >= 50)
                s[i].grade = "C";
            else if(s[i].perc >= 40)
                s[i].grade = "PASS";
            else
                s[i].grade = "FAIL";
        }

        System.out.println("\n- Student Records -");
        System.out.println("\nRoll No | Name | SY Total | TY Total | Grand Total | Percentage | Grade\n");

        for(S14Q2 stu : s)
            System.out.println("\n" + stu.rollno + "\t" + stu.name + "\t" + stu.sytotal + "\t" + stu.tytotal + "\t" + stu.total + "\t" + stu.perc + "%\t" + stu.grade);

        sc.close();
    }
}

