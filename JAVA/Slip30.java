/*
Q1) Write program to define class Person with data member as Personname,Aadharno, Panno.
Accept information for 5 objects and display appropriate information (use this keyword).
import java.util.Scanner;
*/
class Person 
{
    private String Personname;
    private long Aadharno;
    private String Panno;

    public Person(String Personname, long Aadharno, String Panno) 
    {
        this.Personname = Personname;
        this.Aadharno = Aadharno;
        this.Panno = Panno;
    }

    public void displayInfo() 
    {
        System.out.println("Person Name: " + this.Personname);
        System.out.println("Aadhar Number: " + this.Aadharno);
        System.out.println("PAN Number: " + this.Panno);
        System.out.println();
    }
}

public class Slip30 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        Person[] persons = new Person[5];

        for (int i = 0; i < 5; i++) 
        {
            System.out.println("Enter information for Person " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();

            System.out.print("Aadhar Number: ");
            long aadharNo = scanner.nextLong();
            scanner.nextLine();

            System.out.print("PAN Number: ");
            String panNo = scanner.nextLine();

            persons[i] = new Person(name, aadharNo, panNo);
        }
        System.out.println("\nPerson Information:");
        for (int i = 0; i < 5; i++) {
            System.out.println("Details for Person " + (i + 1) + ":");
            persons[i].displayInfo();
        }
        scanner.close();
    }
}

/*
Q2) Write a program that creates a user interface to perform integer divisions. The user enters two 
numbers in the text fields, Number1 and Number2. The division of Number1 and Number2 is 
displayed in the Result field when the Divide button is clicked. If Number1 or Number2 were 
not an integer, the program would throw a NumberFormatException. If Number2 were Zero, 
the program would throw an Arithmetic Exception Display the exception in a message 
dialog box.
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class s30 extends JFrame implements ActionListener
{
    JButton btn1;
    JTextField t1, t2;
    JLabel l1, l2, Result;

    s30() {
        t1 = new JTextField(10);
        t2 = new JTextField(10);
        Result = new JLabel();
        l1 = new JLabel("Enter First number");
        l2 = new JLabel("Enter Second number");
        btn1 = new JButton("Divide");

        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(btn1);
        add(Result);

        setLayout(new FlowLayout());
        btn1.addActionListener(this);

        setVisible(true);
        setSize(300, 400);
    }

    public void actionPerformed(ActionEvent ae) 
    {
        try {
            int v1 = Integer.parseInt(t1.getText());
            int v2 = Integer.parseInt(t2.getText());
            int ans = v1 / v2;

            Result.setText(ans + " ");
        } 
        catch (NumberFormatException e) 
        {
            System.out.println("Enter a valid number!");
        } 
        catch (ArithmeticException o) 
        {
            System.out.println("Divided by zero");
        }
    }
    public static void main(String args[])
    {
        Slip30 ob1 = new Slip30();
    }
}
