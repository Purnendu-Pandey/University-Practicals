//Q1) Write a program to find the Square of given number using function interface. 
import java.util.Scanner;
interface fun
{
   int cal(int k);
}
public class Slip16
{
      public static void main(String[] args)
      {
         Scanner s= new Scanner(System.in);
         System.out.print("Enter Number : ");
         int  x=s.nextInt();
         fun c=(int k)-> k*k;
         int ans=c.cal(x);
         System.out.println("SQUARE : "+ans);
      }
}
