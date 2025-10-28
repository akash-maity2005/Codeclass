import java.util.Scanner;
class Complex
{
	double real;
	double img;
	Complex(double real,double img)
	{
		this.real=real;
		this.img=img;
	}
	void display()
	{
		System.out.println(real+"+"+img+"i");
	}
	Complex add(Complex C)
	{
		double r;
		double i;
		r=this.real+C.real;
		i=this.img+C.img;
		return new Complex(r,i);
	}
	Complex sub(Complex C)
	{
		double r;
		double i;
		r=this.real-C.real;
		i=this.img-C.img;
		return new Complex(r,i);
	}
	Complex mul(Complex C)
	{
		double r;
		double i;
		r = this.real * C.real - this.img * C.img;
		i = this.real * C.img + this.img * C.real;
		return new Complex(r,i);
	}
	static Complex input(Scanner sc)
	{
		System.out.println("Enter Real:");
		double real=sc.nextDouble();
		System.out.println("Enter Img:");
		double img=sc.nextDouble();
		return new Complex(real,img);
	}
}
class MainComplex
{
	public static void main(String args [])
	{
		double real,img;
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter the first complex number:");
		Complex C1=Complex.input(sc);
		
		System.out.println("Enter the second complex number:");
		Complex C2=Complex.input(sc);
		
		Complex sum=C1.add(C2);
		Complex difference=C1.sub(C2);
		Complex product=C1.mul(C2);
		
		System.out.println("Addition:");
		sum.display();
		
		System.out.println("Subtraction:");
		difference.display();
		
		System.out.println("Multiplication:");
		product.display();
	}
}

		
