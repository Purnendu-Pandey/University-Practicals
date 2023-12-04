/*
Q1)Create an abstract class 'Bank' with an abstract method 'getBalance'. Rs.100, Rs.150 and Rs.200 are 
deposited in banks A, B and C respectively. 'BankA', 'BankB' and 'BankC' are subclasses of class 'Bank',
each having a method named 'getBalance'.Call this method by creating an object of each of the three classes.
*/
abstract class Bank 
{
    public abstract int getBalance();
}
class BankA extends Bank 
{
    @Override
    public int getBalance()
    {
        return 100;
    }
}
class BankB extends Bank 
{
    @Override
    public int getBalance()
    {
        return 150;
    }
}

class BankC extends Bank 
{
    @Override
    public int getBalance()
    {
        return 200;
    }
}

public class Slip24
{
    public static void main(String[] args) 
	{
        BankA a = new BankA();
        BankB b = new BankB();
        BankC c = new BankC();

        System.out.println("Balance in Bank A: Rs." + a.getBalance());
        System.out.println("Balance in Bank B: Rs." + b.getBalance());
        System.out.println("Balance in Bank C: Rs." + c.getBalance());
    }
}


/*
Q2) Program that displays three concentric circles where ever the user clicks the mouse on a frame. 
The program must exit when user clicks ‘X’ on the frame.
*/
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Slip24 
{
    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("Concentric Circles");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        CirclesPanel circlesPanel = new CirclesPanel();
        frame.add(circlesPanel);
        frame.setSize(400, 400);
        frame.setVisible(true);
    }
}

class CirclesPanel extends JPanel 
{
    private int x = -1;
    private int y = -1;

    public CirclesPanel() 
    {
        addMouseListener(new MouseAdapter() 
        {
            public void mouseClicked(MouseEvent e) 
            {
                x = e.getX();
                y = e.getY();
                repaint();
            }
        });
    }

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        if (x != -1 && y != -1) 
        {
            g.setColor(Color.RED);
            g.fillOval(x - 60, y - 60, 120, 120);
            g.setColor(Color.GREEN);
            g.fillOval(x - 40, y - 40, 80, 80);
            g.setColor(Color.BLUE);
            g.fillOval(x - 20, y - 20, 40, 40);
        }
    }
}
