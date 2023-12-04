/*
Q1)Write a program to accept the two dimensional array from user and display sum of its diagonal elements.
*/
import java.io.*;
import java.util.*;
public class Slip19
{
	public static void main(String[] args) 
  {
		Scanner sc =new Scanner(System.in);
		int n,m,i,j;
		
		System.out.print("Enter the no of rows : ");
    m=sc.nextInt();
    System.out.print("Enter the no of columns : ");
    n=sc.nextInt();
             
    int a[][]=new int[m][n];
    System.out.println("Enter the array elements  : ");
    for (i=0;i<m;i++)
    { 
      System.out.println("Enter for row : "+(i+1));
      for (j=0;j<n;j++)
          a[i][j]=sc.nextInt();
    }
                      
    System.out.println(" the array elements  : ");
    int sum=0;
    for (i=0;i<m;i++)
        { 
          for (j=0;j<n;j++)
          {
            System.out.print(" "+a[i][j]);
            if (i==j)
            {
              sum=sum+a[i][j];
              }
          }
          System.out.println();
        }
        System.out.println("Sum of diagonal elements :"+sum);		
	}
}

/*
Q2) Write a program which shows the combo box which includes list of T.Y.B.Sc.(Comp. Sci) 
subjects. Display the selected subject in a text field
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Slip19 extends JFrame 
{
    private JComboBox<String> subjectComboBox;
    private JTextField selectedSubjectTextField;

    public Slip19() 
    {
        setTitle("Subject ComboBox Demo");
        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        String[] subjects = {
            "OOP using Java",
            "Foundation of Data Science",
            "Computer Networks",
            "Web Technologies",
            "Operating Systems"
        };

        subjectComboBox = new JComboBox<>(subjects);
        selectedSubjectTextField = new JTextField(20);
        selectedSubjectTextField.setEditable(false);

        subjectComboBox.addActionListener(new ActionListener() 
        {
            @Override
            public void actionPerformed(ActionEvent e) 
            {
                String selectedSubject = subjectComboBox.getSelectedItem().toString();
                selectedSubjectTextField.setText(selectedSubject);
            }
        });

        add(new JLabel("Select Subject:"));
        add(subjectComboBox);
        add(new JLabel("Selected Subject:"));
        add(selectedSubjectTextField);

        setVisible(true);
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(new Runnable() 
        {
            public void run() 
            {
                new Slip19();
            }
        });
    }
}
