//Q1) Write a program to display the Employee(Empid,Empname,Empdesignation,Empsal)information using toString()
import java.util.Scanner;
class emp
{
		int eid;
		String ename,edept;
		double sal;
		emp(int eid,String ename,String edept,double sal)
		{
				this.eid=eid;
				this.ename=ename;
				this.edept=edept;
				this.sal=sal;
		}
	public String toString()
	{
		return 	"\nEmployee Id="+eid+
						"\nEmployee name:"+ename+
           	"\nEmployee Designation: "+edept+
			     	"\nEmployee salary:"+sal;
		
	}
}
class Slip06
{
	public static void main(String[] args)
	{
		int n,i;
		Scanner s=new Scanner(System.in);
		emp e=new emp(1,"Raaz","Bcs",100000);
		emp e1=new emp(2,"Rz","Bsc",50000);
		System.out.println(e.toString());
		System.out.println(e1.toString());		
	}
}

//Q2)Create an abstract class “order” having members id,description.Create two subclasses “PurchaseOrder” 
//& “Sales Order” having members customer name & Vendor name respectively. Definemethods accept & display 
//in all cases.Create 3 objects each of Purchase Order and Sales Order and accept and display details.
import java.util.Scanner;
abstract class order
{
	int id;
	String desp;
	order(int id,String desp)
	{
		this.id=id;
		this.desp=desp;
	}
	abstract void display();
}
class purchesorder extends order
{
    String cname;
    purchesorder(int id,String desp,String cname)
    {
        super(id,desp);
		this.cname=cname;
	}	
	
    void display()
    {
		System.out.println("-----DETAIL FOR PURCHESORDER-----");
    System.out.println("ID ="+id);
		System.out.println("DESCRIPTION ="+desp);
		System.out.println("COSTOMER NAME ="+cname);
		System.out.println();
	}		
	
}
class salesorder extends order
{
    String vname;
    salesorder(int id,String desp,String vname)
    {
        super(id,desp);
		this.vname=vname;
	}	
    void display()
    {
		System.out.println("-----DETAIL FOR SALESORDER-----");
    System.out.println("ID ="+id);
		System.out.println("DESCRIPTION ="+desp);
		System.out.println("VANDOR NAME ="+vname);
		System.out.println();
	}		
	
}
public class Slip06
{
	public static void main(String[] args)
	{
		int i;
		Scanner s=new Scanner(System.in);
		purchesorder []pur=new purchesorder[3];
		salesorder []sal=new salesorder[3];
		for(i=0;i<3;i++)
	    {
        System.out.println("Enter the Detail for purches order : "+(i+1));
				System.out.println("Enter id : ");
				int id=s.nextInt();
				System.out.println("Enter description : ");
				String desp=s.next();
				System.out.println("Enter name : ");
				String cname=s.next();
        pur[i]=new purchesorder(id,desp,cname);
			}	
      for(i=0;i<3;i++)
	    {
        System.out.println("Enter the Detail for Sales order : "+(i+1));
				System.out.println("Enter id : ");
				int id=s.nextInt();
				System.out.println("Enter description : ");
				String desp=s.next();
				System.out.println("Enter name : ");
				String vname=s.next();
        sal[i]=new salesorder(id,desp,vname);
			}	
      for(i=0;i<3;i++)	
			{
			  pur[i].display();
			  sal[i].display();		
		  }		
	}
}
