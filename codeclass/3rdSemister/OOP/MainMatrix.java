import java.util.Scanner;

class Matrix
{
	int rows,cols;
	int[][] mat;
	
	Matrix(int r,int c)
	{
		rows=r;
		cols=c;
		mat=new int[rows][cols];
	}
	
	void inputMatrix(Scanner sc)
	{
		System.out.println("Enter the elements of the matrix ("+rows+"x"+cols+"):");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				mat[i][j]=sc.nextInt();
			}
		}
	}
	
	void displayMatrix()
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				System.out.print(mat[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	static Matrix subtraction(Matrix a,Matrix b)
	{
		if(a.rows!=b.rows||a.cols!=b.cols)
		{
			System.out.println("Subtraction is not possible as the dimensions of the two matrices does not match.");
			return null;
		}
		Matrix result=new Matrix(a.rows,a.cols);
		for(int i=0;i<a.rows;i++)
		{
			for(int j=0;j<a.cols;j++)
			{
				result.mat[i][j]=a.mat[i][j]-b.mat[i][j];
			}
		}
		return result;
	}
	
	static Matrix multiplication(Matrix a,Matrix b)
	{
		if(a.cols!=b.rows)
		{
			System.out.println("Multiplication not possible as columns of the first row must equal rows of the second.");
			return null;
		}
		Matrix result=new Matrix(a.rows,b.cols);
		for(int i=0;i<a.rows;i++)
		{
			for(int j=0;j<b.cols;j++)
			{
				result.mat[i][j]=0;
				for(int k=0;k<a.cols;k++)
				{
					result.mat[i][j]+=a.mat[i][j]*b.mat[k][j];
				}
			}
		}
		return result;
	}
}

class MainMatrix
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter rows and columns of the first matrix:");
		int r1=sc.nextInt();
		int c1=sc.nextInt();
		Matrix m1=new Matrix(r1,c1);
		m1.inputMatrix(sc);
		
		System.out.println("Enter rows and columns of the second matrix:");
		int r2=sc.nextInt();
		int c2=sc.nextInt();
		Matrix m2=new Matrix(r2,c2);
		m2.inputMatrix(sc);
		
		System.out.println("\nMatrix Subtraction:");
		Matrix sub=Matrix.subtraction(m1,m2);
		if(sub!=null)
		{
			sub.displayMatrix();
		}
		
		System.out.println("\nMatrix Multiplication:");
		Matrix mul=Matrix.multiplication(m1,m2);
		if(mul!=null)
		{
			mul.displayMatrix();
		}
	}
}
		
		
