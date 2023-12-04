/*
Q1) Write a program to find the cube of given number using functional interface.
*/
import java.util.Scanner;
interface fun
{
	int cal(int k);
}
public class Slip10
{
	public static void main(String[] args)
	{
	    Scanner s=new Scanner(System.in);
	    System.out.println("Enter the Number:");
	    int x=s.nextInt();
	    fun c=(int k)->k*k*k;
	    int ans=c.cal(x);
	    System.out.println("Cube:"+ans);
	}
}

/*
Q2) 
Write a program to create a package name student. Define class StudentInfo with method to
display information about student such as rollno, class, and percentage. Create another class
StudentPer with method to find percentage of the student. Accept student details like
rollno, name, class and marks of 6 subject from user.
*/
//studentinfo
package student;
public class StudentInfo
{
    private int rollno;
    private String name;
    private String className;
    private float perc;

    public StudentInfo(int rollno, String name, String className, float perc) {
        this.rollno = rollno;
        this.name = name;
        this.className = className;
        this.perc = perc;
    }
    public void display()
		{
        System.out.println("Roll No.: " + rollno);
        System.out.println("Name: " + name);
        System.out.println("Class: " + className);
        System.out.println("Percentage: " + perc + "%");
    }
}

//StudentPer
package student;
public class StudentPer
{
    public static float percentage(int marks[]) 
		{
        int total = 0;
        for(int mark : marks)
            total += mark;
        return (float) total / 600 * 100;
    }
}


//program
import java.util.Scanner;
import student.StudentPer;
import student.StudentInfo;

public class Slip10 
{
    public static void main(String args[]) 
		{
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the number of students: ");
        int n = sc.nextInt();

        StudentInfo s[] = new StudentInfo[n];
        for(int i=0; i<n; i++) 
				{
            System.out.println("\nEnter the details of student " + (i+1));
            System.out.print("Enter the Roll No.: ");
            int rollno = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter the name: ");
            String name = sc.nextLine();

            System.out.print("Enter the class name: ");
            String className = sc.nextLine();

            int marks[] = new int[6];
            System.out.println("\nEnter the marks for 6 subjects (out of 100)");
            for(int j=0; j<6; j++) 
						{
              System.out.print("Marks of subject " + (j+1) + ": ");
              marks[j] = sc.nextInt();
            }
            float per = StudentPer.percentage(marks);
            s[i] = new StudentInfo(rollno,name,className,per);
        }
        System.out.println("\n- Student Details -");
        System.out.println("---------------------------------------");

        for(StudentInfo stu : s) 
				{
            stu.display();
            System.out.println("---------------------------------------");
        
        sc.close();
    }
}
}