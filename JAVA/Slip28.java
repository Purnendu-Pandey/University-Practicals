/*
Q1) Write a program that reads on file name from the user, then displays information about 
whether the file exists, whether the file is readable, whether the file is writable, the type
of file and the length of the file in bytes.
*/
import java.io.*;
import java.util.*;
public class Slip28
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the file name:");
		String filename=sc.nextLine();
		File fn=new File(filename);
		if(fn.exists())
		{
			System.out.println("File "+filename+" exists!");
			System.out.println("is file readable:"+fn.canRead());
			System.out.println("is file Writable:"+fn.canWrite());
			if(fn.isDirectory())
			{
			    System.out.println("File Type:Directory");
			}
			else
			{
        System.out.println("File Type:File");
			}
			System.out.println("File length is:"+fn.length());
		}
		else
		{
			System.out.println("File with given name does not exists");
		}
	}
}

/*
Q2) Write a program called SwingTemperatureConverter to convert temperature values 
between Celsius and Fahrenheit.User can enter either the Celsius or the Fahrenheit value,
in floating-point number.Hints:To display a floating-point number in a specific format 
(e.g.,1 decimal place),use the static method String.format(),which has the same form 
as printf().For example,String.format("%.1f", 1.234) returns String "1.2".
*/
import javax.swing.*;
import java.util.*;
import java.text.*;
import java.awt.*;
import java.awt.event.*;

class s28 extends KeyAdapter
{
    JLabel l1, l2;
    JTextField t1, t2;

    s28() {
        JFrame ob = new JFrame("Temperature Converter");
        l1 = new JLabel("Celsius");
        l2 = new JLabel("Fahrenheit");
        t1 = new JTextField(10);
        t2 = new JTextField(10);

        ob.add(l1);
        ob.add(t1);
        ob.add(l2);
        ob.add(t2);

        ob.setVisible(true);
        t1.addKeyListener(this);

        ob.setLayout(new FlowLayout());
        ob.setSize(400, 400);
        ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void keyReleased(KeyEvent ke) {
        try {
            Double cels = Double.parseDouble(t1.getText());
            Double S = (cels * 1.8) + 32;
            Formatter fob = new Formatter();
            fob.format("%.2f", S);
            t2.setText("" + S);
        } catch (Exception e) {
            System.out.println("Enter Values in Box");
        }
    }

    public static void main(String[] args) {
        s28 ob = new s28();
    }
}