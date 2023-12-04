/*
Q1) Accept the names of two files and copy the contents of the first to the second. First file having
Book name and Author name in file. 
*/
import java.io.*;
import java.util.*;
import java.io.File;
class Slip15
{
      public static void main(String args[]) throws Exception
      {
             Scanner s=new Scanner(System.in);
             System.out.println("Source File name: \n");
             String file1=s.next();
             System.out.println("Destination File name: \n");
             String file2=s.next();
             FileReader fin=new FileReader(file1);
             FileWriter fout=new FileWriter(file2,true);
             int c;
             while((c=fin.read()) != -1)
             {
                  fout.write(c);
             }
             System.out.println("Copy Finish..");
             fin.close();
             fout.close();
      }
      
}
/*
Q2) Write a program to define a class Account having members custname, accno. Define default 
and parameterized constructor. Create a subclass called SavingAccount with member savingbal, 
minbal. Create a derived class AccountDetail that extends the class SavingAccount with 
members, depositamt and withdrawalamt. Write a appropriate method to display customer details.
*/
import java.util.Scanner;

class Account
{
    int accno;
    String custname;

    Account() 
    {
        accno = 0;
        custname = "";
    }

    Account(int accno, String custname) 
    {
        this.accno = accno;
        this.custname = custname;
    }

    void displayCustomer() 
    {
        System.out.println("Account Number: " + accno);
        System.out.println("Customer Name: " + custname);
    }
}

class SavingAccount extends Account 
{
    float savingBal;
    float minBal;

    SavingAccount() 
    {
        super();
        savingBal = 0.0f;
        minBal = 0.0f;
    }

    SavingAccount(int accno, String custname, float savingBal, float minBal) 
    {
        super(accno,custname);
        this.savingBal = savingBal;
        this.minBal = minBal;
    }

    void displayCustomer() 
    {
        super.displayCustomer();
        System.out.println("Savings Balance: " + savingBal);
        System.out.println("Minimum Balance: " + minBal);
    }
}

class AccountDetails extends SavingAccount 
{
    float depositAmt;
    float withdrawalAmt;

    AccountDetails() 
    {
        super();
        depositAmt = 0.0f;
        withdrawalAmt = 0.0f;
    }

    AccountDetails(int accno, String custname, float savingBal, float minBal, float depositAmt, float withdrawlAmt)
    {
        super(accno,custname,savingBal,minBal);
        this.depositAmt = depositAmt;
        this.withdrawalAmt = withdrawlAmt;
    }

    void displayCustomer() 
    {
        super.displayCustomer();
        System.out.println("Deposit Amount: " + depositAmt);
        System.out.println("Withdrawal Amount: " + withdrawalAmt);
    }
}

public class Slip15 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Customer Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Account Number: ");
        int accountNumber = sc.nextInt();

        System.out.print("Enter Savings Balance: ");
        float savingBalance = sc.nextFloat();

        System.out.print("Enter Minimum Balance: ");
        float minBalance = sc.nextFloat();

        System.out.print("Enter Last Deposit Amount: ");
        float depositAmount = sc.nextFloat();

        System.out.print("Enter Last Withdrawal Amount: ");
        float withdrawalAmount = sc.nextFloat();

        AccountDetails account = new AccountDetails(accountNumber, name, savingBalance, minBalance, depositAmount, withdrawalAmount);

        System.out.println("\nCustomer Details:");
        account.displayCustomer();

        sc.close();
    }
}
