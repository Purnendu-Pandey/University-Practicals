/*
Q1) 
Design a class for Bank. Bank Class should support following operations; 
a.Deposit a certain amount into an account
b.Withdraw a certain amount from an account
c.Return a Balance value specifying the amount with details
*/
import java.util.Scanner;
public class S7Q1
{
    private double balance;

    public S7Q1(double bal) {
        if (bal < 0) {
            throw new IllegalArgumentException("\nInitial balance cannot be negative");
        }
        this.balance = bal;
    }

    public void deposit(double amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("\nDeposit amount cannot be negative");
        }
        balance += amount;
        System.out.println("\nDeposited: " + amount + "\nNew Balance: " + balance);
    }

    public void withdraw(double amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("\nWithdrawal amount cannot be negative");
        }
        if (amount > balance) {
            System.out.println("\nInsufficient balance. Cannot withdraw " + amount);
            return;
        }
        balance -= amount;
        System.out.println("\nWithdrew: " + amount + "\nRemaining Balance: " + balance);
    }

    public double getBalance() {
        return balance;
    }

    public String toString() {
        return "\nBank Account Details:- \nBalance: " + balance;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("\nEnter initial bank balance: ");
        double bal = sc.nextDouble();

        S7Q1 bank = new S7Q1(bal);

        while(true) {
            System.out.print("\n- Choose an operation - \n1. Deposit \n2. Withdraw \n3. Check Balance \n4. Exit \nEnter your choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1: // Deposit
                    System.out.print("\nEnter amount to deposit: ");
                    double depositAmount = sc.nextDouble();
                    bank.deposit(depositAmount);
                    break;

                case 2: // Withdraw
                    System.out.print("\nEnter amount to withdraw: ");
                    double withdrawAmount = sc.nextDouble();
                    bank.withdraw(withdrawAmount);
                    break;

                case 3: // Check Balance
                    System.out.println(bank);
                    break;

                case 4: // Exit
                    System.out.println("\nThank you for using our bank!");
                    sc.close();
                    return;

                default:
                    System.out.println("\nInvalid choice! Please select a valid option.");
            }
        }
    }
}

/*
//Q2) 
//Write a program to accept a text file from user and display the contents of a file in 
//reverse order and change its case.
*/
import java.io.*;
import java.util.*;
class Slip07
{
      public static void main(String args[]) throws IOException
      {
             FileReader f=new FileReader("sample.txt");
             Scanner sc=new Scanner(f);
             String c,c2;
             while (sc.hasNext())
             {
                    StringBuilder c1=new StringBuilder();
                    c=sc.nextLine();
                    System.out.println("Original String : "+c);
                    c2=c.toUpperCase();
                    c1.append(c2);
                    c1.reverse();
                    System.out.println("Reverse String :"+c1);
             }
             f.close();
      }
}
