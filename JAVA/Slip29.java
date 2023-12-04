/*
Q1) Write a program to create a class Customer(custno,custname,contactnumber,custaddr).Write a method 
to search the customer name with given contact number and display the details. 
*/
import java.util.ArrayList;
import java.util.Scanner;
class Customer 
{
    private int custno;
    private String custname;
    private String contactnumber;
    private String custaddr;

    public Customer(int custno, String custname, String contactnumber, String custaddr) 
    {
        this.custno = custno;
        this.custname = custname;
        this.contactnumber = contactnumber;
        this.custaddr = custaddr;
    }

    public int getCustno() 
    {
        return custno;
    }

    public String getCustname() 
    {
        return custname;
    }

    public String getContactnumber() 
    {
        return contactnumber;
    }

    public String getCustaddr() 
    {
        return custaddr;
    }

    // Search for a customer by contact number
    public static Customer searchCustomerByContactNumber(String contactNumber, ArrayList<Customer> customers) 
    {
        for (Customer customer : customers) 
        {
            if (customer.getContactnumber().equals(contactNumber)) 
            {
                return customer;
            }
        }
        return null; 
    }
}

public class Slip29
{
    public static void main(String[] args) 
    {
        ArrayList<Customer> customers = new ArrayList<>();
        customers.add(new Customer(1, "John", "1234567890", "123 Main St"));
        customers.add(new Customer(2, "Alice", "9876543210", "456 Elm St"));
        customers.add(new Customer(3, "Bob", "5551234567", "789 Oak St"));

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the contact number to search for a customer: ");
        String contactNumberToSearch = scanner.nextLine();

        Customer foundCustomer = Customer.searchCustomerByContactNumber(contactNumberToSearch, customers);

        if (foundCustomer != null) 
        {
            System.out.println("Customer found:");
            System.out.println("Customer Number: " + foundCustomer.getCustno());
            System.out.println("Customer Name: " + foundCustomer.getCustname());
            System.out.println("Contact Number: " + foundCustomer.getContactnumber());
            System.out.println("Customer Address: " + foundCustomer.getCustaddr());
        } 
        else 
        {
            System.out.println("Customer not found for contact number: " + contactNumberToSearch);
        }

        scanner.close();
    }
}

/*
Q2) Write a program to create a super class Vehicle having members Company and price.Derive two 
different classes LightMotorVehicle(mileage) and HeavyMotorVehicle (capacity_in_tons) Accept the 
information for "n" vehicles and display the information in appropriate form. While taking data, ask
user about the type of vehicle first.
*/
import java.util.Scanner;
class Vehicle 
{
    String company;
    double price;

    public Vehicle(String company, double price)
    {
        this.company = company;
        this.price = price;
    }
}

class LightMotorVehicle extends Vehicle
{
    double mileage;

    public LightMotorVehicle(String company, double price, double mileage) 
    {
        super(company, price);
        this.mileage = mileage;
    }
    public void display() 
    {
        System.out.println("Company: " + company);
        System.out.println("Price: $" + price);
        System.out.println("Mileage: " + mileage + " km/l");
    }
}
class HeavyMotorVehicle extends Vehicle 
{
    double capacityInTons;

    public HeavyMotorVehicle(String company, double price, double capacityInTons)
    {
        super(company, price);
        this.capacityInTons = capacityInTons;
    }

    public void display() 
    {
        System.out.println("Company: " + company);
        System.out.println("Price: $" + price);
        System.out.println("Capacity in Tons: " + capacityInTons + " tons");
    }
}

public class Slip29
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vehicles: ");
        int n = scanner.nextInt();
        scanner.nextLine(); 
        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter the type of vehicle (Light / Heavy):");
            String vehicleType = scanner.nextLine();

            System.out.print("Enter company name: ");
            String company = scanner.nextLine();

            System.out.print("Enter price: ");
            double price = scanner.nextDouble();
            scanner.nextLine(); // Consume the newline character

            if (vehicleType.equalsIgnoreCase("Light")) 
            {
                System.out.print("Enter mileage: ");
                double mileage = scanner.nextDouble();
                scanner.nextLine(); // Consume the newline character

                LightMotorVehicle lightVehicle = new LightMotorVehicle(company, price, mileage);
                lightVehicle.display();
            } 
            else if (vehicleType.equalsIgnoreCase("Heavy")) 
            {
                System.out.print("Enter capacity in tons: ");
                double capacityInTons = scanner.nextDouble();
                scanner.nextLine(); // Consume the newline character

                HeavyMotorVehicle heavyVehicle = new HeavyMotorVehicle(company, price, capacityInTons);
                heavyVehicle.display();
            } 
            else 
            {
                System.out.println("Invalid vehicle type entered.");
            }
        }
        scanner.close();
    }
}
