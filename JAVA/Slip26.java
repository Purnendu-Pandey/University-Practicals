//Q1) Define a Item class (item_number, item_name, item_price). Define a default and parameterized 
//constructor. Keep a count of objects created. Create objects using parameterized constructor 
//and display the object count after each object is created.(Use static member and method).Also 
//display the contents of each object.
class Item 
{
    int item_number;
    String item_name;
    double item_price;
    static int objectCount = 0;

    public Item(int item_number, String item_name, double item_price) {
        this.item_number = item_number;
        this.item_name = item_name;
        this.item_price = item_price;
        objectCount++;
    }

    public void displayItem() 
	  {
        System.out.println("Item Number: " + item_number);
        System.out.println("Item Name: " + item_name);
        System.out.println("Item Price: $" + item_price);
    }

    public static void displayObjectCount() {
        System.out.println("Number of objects created: " + objectCount);
    }
}

public class Slip26
 {
    public static void main(String[] args) {
        Item item1 = new Item(1, "Item A", 10.99);
        item1.displayItem();
        Item.displayObjectCount();

        Item item2 = new Item(2, "Item B", 15.49);
        item2.displayItem();
        Item.displayObjectCount();
    }
}
/*
Q2)Define a class ‘Donor’ to store the below mentioned details of a blood donor. name, age, 
address, contactnumber, bloodgroup, date of last donation. Create ‘n’ objects of this class for
all the regular donors at Pune. Write these objects to a file. Read these objects from the file and 
display only those donors’ details whose blood group is ‘A+ve’ and had not donated for the
recent six months.
*/
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Slip26 
{
    public static class Donor implements Serializable 
    {
        private String name;
        private int age;
        private String address;
        private String contactNumber;
        private String bloodGroup;
        private Date lastDonationDate;

        public Donor(String name, int age, String address, String contactNumber, String bloodGroup, String lastDonationDate) throws ParseException {
            this.name = name;
            this.age = age;
            this.address = address;
            this.contactNumber = contactNumber;
            this.bloodGroup = bloodGroup;
            this.lastDonationDate = new SimpleDateFormat("yyyy-MM-dd").parse(lastDonationDate);
        }

        public String getName() 
        {
            return name;
        }

        public int getAge() 
        {
            return age;
        }

        public String getAddress() 
        {
            return address;
        }

        public String getContactNumber() 
        {
            return contactNumber;
        }

        public String getBloodGroup() 
        {
            return bloodGroup;
        }

        public Date getLastDonationDate() 
        {
            return lastDonationDate;
        }

        @Override
        public String toString() 
        {
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
            return "Name: " + name + "\nAge: " + age + "\nAddress: " + address + "\nContact Number: " + contactNumber
                    + "\nBlood Group: " + bloodGroup + "\nLast Donation Date: " + sdf.format(lastDonationDate);
        }
    }

    public static void main(String[] args) 
    {
        List<Donor> donors = new ArrayList<>();

        // Create Donor objects and add them to the list
        try {
            Donor donor1 = new Donor("John", 30, "123 Main St", "123-456-7890", "A+ve", "2022-03-15");
            Donor donor2 = new Donor("Jane", 25, "456 Elm St", "987-654-3210", "B+ve", "2022-04-20");
            Donor donor3 = new Donor("Bob", 35, "789 Oak St", "555-123-4567", "A+ve", "2022-09-10");

            donors.add(donor1);
            donors.add(donor2);
            donors.add(donor3);
        } 
        catch (ParseException e) 
        {
            e.printStackTrace();
        }

        // Write Donor objects to a file
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("donors.dat"))) 
        {
            outputStream.writeObject(donors);
        } catch (IOException e) 
        {
            e.printStackTrace();
        }

        // Read Donor objects from the file
        List<Donor> loadedDonors = new ArrayList<>();
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream("donors.dat"))) 
        {
            List<?> loadedData = (List<?>) inputStream.readObject();
            loadedDonors = new ArrayList<>();
            for (Object item : loadedData) 
            {
                if (item instanceof Donor) 
                {
                    loadedDonors.add((Donor) item);
                } 
                else 
                {
                    // Handle the case where the loaded data is not of the expected type
                    System.err.println("Encountered an object that is not a Donor: " + item);
                }
            }
        } catch (IOException | ClassNotFoundException e) 
        {
            e.printStackTrace();
        }

        Date currentDate = new Date();

        for (Donor donor : loadedDonors) 
        {
            if (donor.getBloodGroup().equals("A+ve")) 
            {
                long daysSinceLastDonation = (currentDate.getTime() - donor.getLastDonationDate().getTime()) / (24 * 60 * 60 * 1000);
                if (daysSinceLastDonation >= 180) { // 6 months = 180 days
                    System.out.println("Donor Details:\n" + donor + "\n");
                }
            }
        }
    }
}
