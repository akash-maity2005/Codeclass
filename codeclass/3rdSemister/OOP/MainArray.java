import java.util.Scanner;
 
class Arr
{
	int arr[];
	int size;
	Scanner sc=new Scanner(System.in);
	
	void getArr()
	{
		System.out.print("Enter the size of the array:");
		size=sc.nextInt();
		arr=new int[size];
		System.out.println("Enter the elements:");
		for(int i=0;i<size;i++)
		{
			arr[i]=sc.nextInt();
		}
	}
	
	void display()
	{
		System.out.println("Array is:");
		for(int i=0;i<size;i++)
		{
			System.out.println(arr[i]+" ");
		}
		System.out.println();
	}
	
	void search()
	{
		System.out.println("Enter the element you want to search:");
		int target=sc.nextInt();
		int flag=-1;
		for(int i=0;i<size;i++)
		{
			if(arr[i]==target)
			{
				System.out.println("Element "+arr[i]+"is found at index "+i);
				flag=1;
				break;
			}
		}
		if(flag==-1)
		{
			System.out.println("Sorry, the element is not found.");
		}
	}
	
	void sort()
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=0;j<size-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}
	
	void deleteByIndex()
	{
		System.out.println("Enter the index of the element to delete:");
		int index=sc.nextInt();
		if(index<0||index>=size)
		{
			System.out.println("Invalid index.");
		}
		
		int[] newArr=new int[size-1];
		for(int i=0,j=0;i<size;i++)
		{
			if(i!=index)
			{
				newArr[j++]=arr[i];
			}
		}
		arr=newArr;
		size--;
	}
}

class MainArray
{
	public static void main(String args[])
	{
		Arr obj=new Arr();
		obj.getArr();
		obj.display();
		obj.search();
		obj.sort();
		System.out.println("Sorted array is:");
		obj.display();
		obj.deleteByIndex();
		obj.display();
	}
}

	

