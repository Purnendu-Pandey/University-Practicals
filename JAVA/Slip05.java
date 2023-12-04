/*
//Q1) 
//Write a program for multilevel inheritance such that Country is inherited from Continent. 
//State is inherited from Country. Display the place, State, Country and Continent.
*/
import java.util.Scanner;
class continent
{
	String cname;
	continent(String cname)
	{
	   this.cname=cname;
	}
}
class country extends continent
{
	String coname;
	country(String cname,String coname)
	{
	   super(cname);
	   this.coname=coname;
	}
}
class state extends country
{	
	 String sname;
	 state(String cname,String coname,String sname)
	 {
	      super(cname,coname);
	      this.sname=sname;
	 }
}
class Slip05
{
	public static void main(String[] args)
	{
	    Scanner s=new Scanner(System.in);
	    System.out.println("Enter the Continent name:");
	    String cname=s.nextLine();
	    
	    System.out.println("Enter the Country name:");
	    String coname=s.nextLine();
	    
	    System.out.println("Enter the state name:");
	    String sname=s.nextLine();
	    
	    System.out.println("Enter the palce name:");
	    String pname=s.nextLine();
	    
	    System.out.println("-----MultiHeritance-----:");
	    System.out.println("Continent:"+cname);
	    System.out.println("Contry:"+coname);	
	    System.out.println("State:"+sname);	
	    System.out.println("Place:"+pname);	
	 }
}

//Q2) 
//Write a menu driven program to perform the following operations on multidimensional array ie matrices :
//Addition,Multiplication,Exit.
import java.util.*; 
class Matrix 
{ 
 			Scanner sc = new Scanner(System.in); 
 			int a = sc.nextInt(); 
 			int b = sc.nextInt(); 
 			int M[][] = new int[a][b]; 
 			void accept() 
 			{
					int a = this.a; 
 					int b = this.b; 
 					System.out.println("enter the "+(a*b)+ " values to matrix:"); 
 					for(int i=0;i<a;i++) 
 					{ 
 							for(int j=0;j<b;j++) 
 							{ 
 									this.M[i][j] = sc.nextInt(); 
 							} 
					} 
 			} 
void display() 
{ 
 		for(int i =0;i<a;i++) 
 		{ 
 				for(int j =0;j<b;j++) 
 				{ 
 						System.out.print(" "+this.M[i][j]); 
 				} 
 				System.out.println(" "); 
 		} 
}  
public static void main(String a[]) 
{ 
			System.out.println("enter size 2*2 or 3*3 or ..."); 
 			Matrix m1 = new Matrix(); 
 			m1.accept(); 
 			System.out.println("values to matrix 1:"); 
 			m1.display(); 
 			System.out.println("enter the size:"); 
 			Matrix m2 = new Matrix(); 
 			m2.accept(); 
 			System.out.println("values to matrix 2:"); 
 			m2.display(); 
 
 			int choice; 
 			Scanner scanner = new Scanner(System.in); 
 			while(true)
			{ 
 					System.out.println("Press 1: Addition, 2: Multiplication, 3: Exit"); 
 					choice = scanner.nextInt(); 
 					switch (choice) 
					{ 
 						case 1: 
 									System.out.println("Addition is:" ); 
 									for(int i=0;i<m1.a;i++) 
 									{	 
 									for(int j=0;j<m1.b;j++) 
									{
										System.out.print(" "+ (m1.M[i][j]+m2.M[i][j]));
									} 
 									System.out.println(" "); 
 									} 
									break; 
						case 2: 
 									System.out.println("Multiplication is:"); 
 									for(int i=0;i<m2.a;i++) 
 									{ 
										for(int j=0;j<m2.b;j++) 
 										{ 
 												System.out.print(" "+(m1.M[i][j]*m2.M[i][j])); 
 										} 
 										System.out.println(" "); 
 									} 
 									break; 
						case 3: 
								 System.exit(0); 
 					} 
 			} 
} 
}