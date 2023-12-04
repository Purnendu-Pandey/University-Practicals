/*
Q1) Write a program to create an abstract class named Shape that contains two integers and an empty 
method named printArea(). Provide three classes named Rectangle, Triangle and Circle such that each 
one of the classes extends the class Shape. Each one of the classes contain only the method 
printArea() that prints the area of the given shape. (use method overriding).
*/
import java.util.Scanner;
abstract class Shape
{
    protected int side1;
    protected int side2;

    public Shape(int side1, int side2)
    {
        this.side1 = side1;
        this.side2 = side2;
    }

    public abstract void printArea();
}

class Rectangle extends Shape
{
    public Rectangle(int length, int width)
    {
        super(length, width);
    }

    @Override
    public void printArea()
    {
        int area = side1 * side2;
        System.out.println("Area of Rectangle: " + area);
    }
}

class Triangle extends Shape
{
    public Triangle(int base, int height)
    {
        super(base, height);
    }

    @Override
    public void printArea()
    {
        double area = 0.5 * side1 * side2;
        System.out.println("Area of Triangle: " + area);
    }
}

class Circle extends Shape
{
    public Circle(int radius)
    {
        super(radius, 0);
    }

    @Override
    public void printArea()
    {
        double area = Math.PI * side1 * side1;
        System.out.println("Area of Circle: " + area);
    }
}

public class Slip22
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a shape:");
        System.out.println("1. Rectangle");
        System.out.println("2. Triangle");
        System.out.println("3. Circle");
        System.out.print("Enter your choice (1/2/3): ");
        int choice = scanner.nextInt();

        Shape shape = null;
        int side1, side2;

        switch (choice)
         {
            case 1:
                System.out.print("Enter the length of the rectangle: ");
                side1 = scanner.nextInt();
                System.out.print("Enter the width of the rectangle: ");
                side2 = scanner.nextInt();
                shape = new Rectangle(side1, side2);
                break;
            case 2:
                System.out.print("Enter the base of the triangle: ");
                side1 = scanner.nextInt();
                System.out.print("Enter the height of the triangle: ");
                side2 = scanner.nextInt();
                shape = new Triangle(side1, side2);
                break;
            case 3:
                System.out.print("Enter the radius of the circle: ");
                side1 = scanner.nextInt();
                shape = new Circle(side1);
                break;
            default:
                System.out.println("Invalid choice.");
                break;
        }

        if (shape != null)
        {
            shape.printArea();
        }

    }
}


/*
Q2) Write a program that handles all mouse events and shows the event name at the center of the 
Window, red in color when a mouse event is fired. (Use adapter classes).
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Slip22 
{
    private JFrame frame;
    private JLabel label;

    public Slip22() 
    {
        frame = new JFrame("Mouse Event Demo");
        frame.setLayout(new BorderLayout());
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        label = new JLabel("Event Name", JLabel.CENTER);
        label.setFont(new Font("Arial", Font.PLAIN, 18));
        frame.add(label, BorderLayout.CENTER);

        frame.addMouseListener(new MouseAdapter() 
        {
            public void mouseClicked(MouseEvent e) 
            {
                showEventName("Mouse Clicked");
            }

            public void mousePressed(MouseEvent e) 
            {
                showEventName("Mouse Pressed");
            }

            public void mouseReleased(MouseEvent e) 
            {
                showEventName("Mouse Released");
            }

            public void mouseEntered(MouseEvent e) 
            {
                showEventName("Mouse Entered");
            }

            public void mouseExited(MouseEvent e) 
            {
                showEventName("Mouse Exited");
            }
        });

        frame.setVisible(true);
    }

    private void showEventName(String eventName) 
    {
        label.setText(eventName);
        label.setForeground(Color.RED);
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(() -> new S22Q2());
    }
}

