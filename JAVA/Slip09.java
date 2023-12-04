/*
Q1) 
Define a “Clock” class that does the following ; 
a.Accept Hours, Minutes and Seconds
b.Check the validity of numbers
c.Set the time to AM/PM mode
Use the necessary constructors and methods to do the above task 
*/
import java.util.Scanner;
class Clock 
{
    int hours;
    int minutes;
    int seconds;
    String amPm;

    public Clock(int hours, int minutes, int seconds) 
	{
        if (isValidTime(hours, minutes, seconds)) 
		{
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
            this.amPm = (hours < 12) ? "AM" : "PM";
            this.hours = (hours > 12) ? hours - 12 : hours;
        } 
		else 
		{
            System.out.println("Invalid time values. Setting to default time (12:00:00 AM).");
            this.hours = 12;
            this.minutes = 0;
            this.seconds = 0;
            this.amPm = "AM";
        }
    }
    private boolean isValidTime(int hours, int minutes, int seconds) 
	{
      return (hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59) && (seconds >= 0 && seconds <= 59);
    }
    public void displayTime() 
	{
        System.out.printf("Time: %02d:%02d:%02d %s%n", hours, minutes, seconds, amPm);
    }
}
public class Slip09
{
    public static void main(String[] args) 
	{
        Scanner s = new Scanner (System.in);
        System.out.print("Enter hours (0-23): ");
        int hours = s.nextInt();
        System.out.print("Enter minutes (0-59): ");
        int minutes = s.nextInt();
        System.out.print("Enter seconds (0-59): ");
        int seconds = s.nextInt();

        Clock clock = new Clock(hours, minutes, seconds);
        clock.displayTime();
    }
}


/* 
Q2) 
Write a program to using marker interface create a class Product (product_id, product_name,
product_cost, product_quantity) default and parameterized constructor. Create objectsof class 
product and display the contents of each object and Also display the object count.
*/
interface Countable{
}
class Product implements Countable
{
    private int productId;
    private String productName;
    private double productCost;
    private int productQuantity;
    private static int objectCount = 0; 
    public Product() 
    {
       objectCount++; 
    }
    public Product(int productId, String productName, double productCost, int productQuantity) {
    this.productId = productId;
    this.productName = productName;
    this.productCost = productCost;
    this.productQuantity = productQuantity;
    objectCount++; 
    }
    public void displayProduct()
    {
        System.out.println("Product ID: " + productId);
        System.out.println("Product Name: " + productName);
        System.out.println("Product Cost: " + productCost);
        System.out.println("Product Quantity: " + productQuantity);
        System.out.println();
    }
    public static void displayObjectCount() 
    {
      System.out.println("Total number of products created: " + objectCount);
    }
}
public class Slip09 
{
    public static void main(String[] args)
    {
        Product product1 = new Product(1, "Smartwatch", 999.99, 5);
        Product product2 = new Product(2, "Smartphone", 599.99, 10);
        Product product3 = new Product(3, "Headphones", 49.99, 20);

        product1.displayProduct();
        product2.displayProduct();
        product3.displayProduct();
        Product.displayObjectCount();
    }
}
