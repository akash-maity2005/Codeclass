import java.util.Scanner;

class Person
{
	String firstName;
	String lastName;
	
	Person(String firstName,String lastName)
	{
		this.firstName=firstName;
		this.lastName=lastName;
	}
	String getFirstName()
	{
		return firstName;
	}
	String getLastName()
	{
		return lastName;
	}
}

class Employee extends Person
{
	String employeeId;
	String jobTitle;
	
	Employee(String firstName,String lastName,String employeeId,String jobTitle)
	{
		super(firstName,lastName);
		this.employeeId=employeeId;
		this.jobTitle=jobTitle;
	}
	
	String getEmployeeId()
	{
		return employeeId;
	}
	String getLastName()
	{
		return super.getLastName()+"("+jobTitle+")";
	}
}

class MainEmployee
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter the first name:");
		String pfn=sc.nextLine();
		System.out.println("Enter the last name:");
		String pln=sc.nextLine();
		
		Person per=new Person(pfn,pln);
		
		System.out.println("Person Details:");
		System.out.println("First Name:"+per.getFirstName());
		System.out.println("Last Name:"+per.getLastName());
		
		System.out.println("Enter Employee's first name:");
		String efn=sc.nextLine();
		System.out.println("Enter employee's last name:");
		String eln=sc.nextLine();
		
		System.out.println("Enter Employee ID:");
		String eID=sc.nextLine();
		System.out.println("Enter Job Title");
		String eJob=sc.nextLine();
		
		Employee emp=new Employee(efn,eln,eID,eJob);
		
		System.out.println("Employee Details:");
		System.out.println("First Name:"+emp.getFirstName());
		System.out.println("Last Name:"+emp.getLastName());
		System.out.println("Employee Id:"+emp.getEmployeeId());
	}
}
