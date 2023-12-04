/*
Q1)Design a Super class Customer (name, phone-number).Derive a class Depositor(accno,balance) 
from Customer. Again, derive a class Borrower (loan-no, loan-amt) from Depositor. Write 
necessary member functions to read and display the details of ‘n’customers.
*/
import java.util.Scanner;
class Customer 
{
    String name;
    String phoneNumber;

    public Customer(String name, String phoneNumber) 
	{
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public void display() 
	{
        System.out.println("Name: " + name);
        System.out.println("Phone Number: " + phoneNumber);
    }
}
class Depositor extends Customer 
{
    int accNo;
    double balance;

    public Depositor(String name, String phoneNumber, int accNo, double balance) {
        super(name, phoneNumber);
        this.accNo = accNo;
        this.balance = balance;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Account Number: " + accNo);
        System.out.println("Balance: $" + balance);
    }
}
class Borrower extends Depositor {
    int loanNo;
    double loanAmount;

    public Borrower(String name, String phoneNumber, int accNo, double balance, int loanNo, double loanAmount) {
        super(name, phoneNumber, accNo, balance);
        this.loanNo = loanNo;
        this.loanAmount = loanAmount;
    }
    @Override
    public void display() 
	{
        super.display();
        System.out.println("Loan Number: " + loanNo);
        System.out.println("Loan Amount: $" + loanAmount);
    }
}
public class Slip17
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of customers: ");
        int n = scanner.nextInt();

        Customer[] customers = new Customer[n];
		    

        for (int i=0; i<n;i++) 
		{
            System.out.print("Enter customer name: ");
            String name = scanner.next();
            System.out.print("Enter phone number: ");
            String phoneNumber = scanner.next();
            System.out.print("Enter account number: ");
            int accNo = scanner.nextInt();
            System.out.print("Enter balance: ");
            double balance = scanner.nextDouble();
            customers[i] = new Depositor(name, phoneNumber, accNo, balance);
            System.out.print("Enter loan number: ");
            int loanNo = scanner.nextInt();
            System.out.print("Enter loan amount: ");
            double loanAmount = scanner.nextDouble();
			      customers[i] = new Depositor(name, phoneNumber, accNo, balance);
			      customers[i] = new Borrower(name, phoneNumber, -1, -1, loanNo, loanAmount);
        }
        System.out.println("Customer Details:");
        for (int i = 0; i < n; i++) 
		    {
            customers[i].display();
			
            System.out.println();
        }
    }
}

/*
Q2) Write Java program to design three text boxes and two buttons using swing. Enter different 
strings in first and second textbox. On clicking the First command button, concatenation of 
two strings should be displayed in third text box and on clicking second command button,
reverse of string should display in third text box
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Slip17 extends JFrame 
{
    private JTextField textField1;
    private JTextField textField2;
    private JTextField resultField;
    private JButton concatenateButton;
    private JButton reverseButton;

    public Slip17() 
    {
        setTitle("String Operations");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(4, 2));

        JLabel label1 = new JLabel("String 1:");
        JLabel label2 = new JLabel("String 2:");
        JLabel resultLabel = new JLabel("Result:");

        textField1 = new JTextField(20);
        textField2 = new JTextField(20);
        resultField = new JTextField(20);
        resultField.setEditable(false);

        concatenateButton = new JButton("Concatenate");
        reverseButton = new JButton("Reverse");

        add(label1);
        add(textField1);
        add(label2);
        add(textField2);
        add(resultLabel);
        add(resultField);
        add(concatenateButton);
        add(reverseButton);

        concatenateButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                concatenateStrings();
            }
        });

        reverseButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                reverseString();
            }
        });
    }

    private void concatenateStrings() 
    {
        String text1 = textField1.getText();
        String text2 = textField2.getText();
        String result = text1 + text2;
        resultField.setText(result);
    }

    private void reverseString() 
    {
        String text = textField1.getText();
        StringBuilder reversed = new StringBuilder(text).reverse();
        resultField.setText(reversed.toString());
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(() -> 
        {
            Slip17 gui = new S17Q2();
            gui.setVisible(true);
        });
    }
}
