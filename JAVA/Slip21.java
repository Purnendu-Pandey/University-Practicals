/*
Q1) Define a class MyDate(Day, Month, year) with methods to accept and display a MyDateobject. 
Accept date as dd,mm,yyyy. Throw user defined exception "InvalidDateException" if the date
is invalid.
*/
import java.io.*;
import java.util.*;
class InvalidDateException extends Exception
{
     InvalidDateException()
     {
         System.out.println("Invalid Date");
     }
}
class MyDate
{
     int day,mon,yr;
     void accept(int d,int m,int y)
     {
          day=d;
          mon=m;
          yr=y;
     }
     void display()
     {
          System.out.println("Date is valid : "+ day+ "/"+ mon+ "/"+ yr);
     }
}
class Date
{
public static void main(String args[]) throws Exception
{
     Scanner sc=new Scanner(System.in);
     System.out.println("Enter Date : dd mm yyyy");
     int day=sc.nextInt();
     int mon=sc.nextInt();
     int yr=sc.nextInt();
     int flag=0;
     try
          {
               if(mon<=0 || mon>12)
                    throw new InvalidDateException();
               else
               {
                    if(mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12)
                    {
                         if(day>=1 && day<=31)
                              flag =1;
                         else
                              throw new InvalidDateException();
                    }
                    else if(mon==2)
                    {
                         if(yr%4==0)
                         {
                                 if(day>=1 && day<=29)
                                     flag=1;
                                 else
                                     throw new InvalidDateException();
                         }
                         else
                         {
                                  if(day>=1 && day<=28)
                                       flag=1;
                                  else
                                     throw new InvalidDateException();
                         }
                    }   
                    else
                    {
                         if(mon==4 || mon==6 || mon==9 || mon==11)
                         {
                                        if(day>=1 && day<=30)
                                             flag=1;
                                        else
                                             throw new InvalidDateException();
                                  }
                            }
                      }
                      if(flag==1)
                      {
                            MyDate dt=new MyDate();
                            dt.accept(day,mon,yr);
                            dt.display();
                      }
                 }
                 catch(InvalidDateException mm)
                 {
                        System.out.println("Invalid Date");
                 }
         }
}

/*
Q2) Create an employee class(id,name,deptname,salary). Define a default and parameterized constructor.
Use ‘this’ keyword to initialize instance variables. Keep a count of objects created. Create objects
using parameterized constructor and display the object count after each object is created. 
(Use static member and method). Also display the contents of each object. 
*/
import java.util.Scanner;
class Employee 
{
    int ID;
    String name, deptname;
    float salary;
    static int count = 0;

    Employee() {}

    Employee(int id, String name, String deptname, float salary) {
        this.ID = id;
        this.name = name;
        this.deptname = deptname;
        this.salary = salary;
        count++;
    }
    static void displayCount() {
        System.out.print("Objects created: " + count + "\n");
    }
}
class S21Q2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of employees: ");
        int n = sc.nextInt();
        Employee emp[] = new Employee[n];

        for(int i=0; i<n; i++) {
            System.out.printf("\nEnter the ID of employee %d: ",i+1);
            int id = sc.nextInt();
            sc.nextLine();

            System.out.printf("Enter the NAME of employee %d: ",i+1);
            String name = sc.nextLine();

            System.out.printf("Enter the DEPARTMENT NAME of employee %d: ",i+1);
            String deptname = sc.nextLine();

            System.out.printf("Enter the SALARY of employee %d: ",i+1);
            float salary = sc.nextFloat();

            emp[i] = new Employee(id,name,deptname,salary);
            Employee.displayCount();
        }

        System.out.println("\n- Employee Details -");
        System.out.println("-----------------------------------------------------------");

        for(int i=0; i<n; i++)
        {
            System.out.printf("ID of employee %d: %d\n", (i+1), emp[i].ID);
            System.out.printf("Name of employee %d: %s\n", (i+1), emp[i].name);
            System.out.printf("Department Name of employee %d: %s\n", (i+1), emp[i].deptname);
            System.out.printf("Salary of employee %d: %.2f\n", (i+1), emp[i].salary);
            System.out.println("-----------------------------------------------------------");
        }
        sc.close();    
    }
}
