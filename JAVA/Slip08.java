/*
Q1) 
Create a class Sphere, to calculate the volume and surface area of sphere.
(Hint : Surface area=4*3.14(r*r), Volume=(4/3)3.14(r*r*r))
*/
import java.util.Scanner;
class sphere
{
	int r;
	sphere(int r)
	{
		this.r=r;
	}
	public void area()
	{
		double a;
		a=4*3.14*(r*r);
		System.out.println("Surface Area: " +a );
	}
	public void volume()
	{
	
	    double v;
	    v=(4/3)*3.14*(r*r*r);
		System.out.println("Volume: " +v);
	}
}
class Slip07
{
	public static void main(String[] args)
	{
		int n,i;
		Scanner s=new Scanner(System.in);
		
		System.out.print("Enter the radius of the sphere: ");
        int r = s.nextInt();
		sphere e=new sphere(r);
		e.area();
		e.volume();
		
	}
	
}

/*
Q2) 
Design a screen to handle the Mouse Events such as MOUSE_MOVED and MOUSE_CLICKED and display 
the position of the Mouse_Click in a TextField.
*/
import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame
{
      TextField t,t1;
      Label l,l1;
      int x,y;
      Panel p;
      MyFrame(String title)
      {
            super(title);
            setLayout(new FlowLayout());
            p=new Panel();
            p.setLayout(new GridLayout(2,2,5,5));
            t=new TextField(20);
            l=new Label("Co-ordinates of clicking");
            l1=new Label("Co-ordinates of movement");
            t1=new TextField(20);
            p.add(l);
            p.add(t);
            p.add(l1);
            p.add(t1);
            add(p);
            addMouseListener(new MyClick());
            addMouseMotionListener(new MyMove());
            addWindowListener(new WindowAdapter()
            {
                public void windowClosing(WindowEvent we)
       	        {
       		   System.exit(0);
       	        }
       	    }
            );
            setSize(500,500);
            setVisible(true);
       }
       
       class MyClick extends MouseAdapter
       {
            public void mouseClicked(MouseEvent me)
            {
                  x=me.getX();
                  y=me.getY();
                  t.setText("X="+x+"Y="+y);
            }
       }
       
       class MyMove extends MouseMotionAdapter
       {
            public void mouseMoved(MouseEvent me)
            {
                  x=me.getX();
                  y=me.getY();
                  t1.setText("X="+x+"Y="+y);
            }
       }
}

class main
{
       public static void main(String args[])
       {
              MyFrame f=new MyFrame("Mouse Events");
       }
}