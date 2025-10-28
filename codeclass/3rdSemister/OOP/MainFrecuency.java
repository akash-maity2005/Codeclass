import java.util.Scanner;

class Frequency
{
	 String str;
	 Frequency(String str)
	 {
	 	this.str=str;
	 }
	 void charFrequency()
	 {
	 	str=str.replaceAll("\\s"," ");
	 	StringBuffer sb=new StringBuffer(str);
	 	for(int i=0;i<sb.length();i++)
	 	{
	 		char ch=sb.charAt(i);
	 		if(ch=='\0')
	 		{
	 			continue;
	 		}
	 		int count=1;
	 		for(int j=i+1;j<sb.length();j++)
	 		{
	 			if(ch==sb.charAt(j))
	 			{
	 				count++;
	 				sb.setCharAt(j,'\0');
	 			}	
	 		}
	 		System.out.println(ch+"="+count);
	 	}
	 }
}

class MainFrequency
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter the String:");
		String input=sc.nextLine();
		Frequency freq=new Frequency(input);
		freq.charFrequency();
	}
}

