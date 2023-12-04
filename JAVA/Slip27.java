/*
Q1) Define an Employee class with suitable attributes having getSalary() method, which returns
salary withdrawn by a particular employee. Write a class Manager which extends a class
Employee, override the getSalary() method, which will return salary of manager by adding
traveling allowance, house rent allowance etc. 
*/
import java.util.Scanner;
class Employee 
{
    double basicSalary;
    public Employee(double basicSalary) 
	{
        this.basicSalary = basicSalary;
    }

    public double getSalary() 
	{
        return basicSalary;
    }
}

class Manager extends Employee 
{
     double travelAllowance;
     double houseRentAllowance;

    public Manager(double basicSalary, double travelAllowance, double houseRentAllowance) 
	{
        super(basicSalary);
        this.travelAllowance = travelAllowance;
        this.houseRentAllowance = houseRentAllowance;
    }

    @Override
    public double getSalary() 
	{
        return basicSalary + travelAllowance + houseRentAllowance;
    }
}
public class Slip27
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Employee's Basic Salary: $");
        double employeeBasicSalary = scanner.nextDouble();

        System.out.print("Enter Manager's Basic Salary: $");
        double managerBasicSalary = scanner.nextDouble();

        System.out.print("Enter Manager's Travel Allowance: $");
        double managerTravelAllowance = scanner.nextDouble();

        System.out.print("Enter Manager's House Rent Allowance: $");
        double managerHouseRentAllowance = scanner.nextDouble();

        Employee employee = new Employee(employeeBasicSalary);
        Manager manager = new Manager(managerBasicSalary, managerTravelAllowance, managerHouseRentAllowance);

        System.out.println("Employee's Salary: $" + employee.getSalary());
        System.out.println("Manager's Salary: $" + manager.getSalary());        
    }
}


/*
Q2) Write a program to accept a string as command line argument and check whether it is a file or 
directory. Also perform operations as follows:
i)If it is a directory,delete all text files in that directory. Confirm delete operation from
user before deleting text files. Also, display a count showing the number of files deleted, if any, 
from the directory. ii)If it is a file display various details of that file
*/
import java.util.*;
import java.io.*;

class s27 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String fname = args[0];
        File f = new File(fname);

        if (f.isFile()) {
            System.out.println("File Name: " + f.getName());
            System.out.println("File Length: " + f.length());
            System.out.println("File Absolute Path: " + f.getAbsolutePath());
            System.out.println("File Path: " + f.getPath());
        } else if (f.isDirectory()) {
            System.out.println("Sure you want Delete All Files (Press 1)");
            int n = sc.nextInt();

            if (n == 1) {
                String[] s1 = f.list();
                String a = ".txt";

                for (String str : s1) {
                    System.out.println(str);
                    if (str.endsWith(a)) {
                        File f1 = new File(fname, str);
                        System.out.println(str + "-->Deleted");
                        f1.delete();
                    }
                }
            } else {
                System.out.println("OKKKK");
            }
        }
    }
}