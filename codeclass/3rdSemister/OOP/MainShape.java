import java.util.Scanner;

class Shape
{
	double getArea();
	double getPerimeter();
}

class Circle extends Shape
{
	double radius;
	Circle(double radius)
	{
		this.radius=radius;
	}
	double getArea()
	{
		return Math.PI*radius*radius;
	}
	double getPerimeter()
	{
		return 2*Math.PI*radius;
	}
}

class Rectangle extends Shape
{
	double length,width;
	Rectangle(double length,double width)
	{
		this.length=length;
		this.width=width;
	}
	double getArea()
	{
		return length*width;
	}
	double getPerimeter()
	{
		return 2*(length+width);
	}
}

class Triangle extends Shape
{
	double a,b,c;
	Triangle(double a,double b,double c)
	{
		this.a=a;
		this.b=b;
		this.c=c;
	}
	double getArea()
	{
		double s=(a+b+c)/2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}
	double getPerimeter()
	{
		return a+b+c;
	}
}

class MainShape
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		System.out.print("Enter radius of circle:");
		double radius=sc.nextDouble();
		Shape circle=new Circle(radius);
		System.out.println("Circle Area: "+circle.getArea());
		System.out.println("Circle Perimeter: "+circle.getPerimeter());
		
		System.out.print("\n Enter the length and width of the rectangle:");
		double length=sc.nextDouble();
		double width=sc.nextDouble();
		Shape rectangle=new Rectangle(length,width);
		System.out.println("Rectangle Area: "+rectangle.getArea());
		System.out.println("Rectangle Perimeter: "+rectangle.getPerimeter());
		
		System.out.print("\nEnter the three sides of the triangle:");
		double a=sc.nextDouble();
		double b=sc.nextDouble();
		double c=sc.nextDouble();
		Shape triangle=new Triangle(a,b,c);
		System.out.println("Triangle Area: "+triangle.getArea());
		System.out.println("Triangle Perimeter: "+triangle.getPerimeter());
	}
}
		
