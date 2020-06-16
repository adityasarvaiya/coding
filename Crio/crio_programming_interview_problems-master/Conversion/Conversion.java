import java.util.*;

class Conversion{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public static int [] binary(long n)
	{
		int [] ar=new int[100];
		int i=0;
		while(n!=0)
		{
			ar[i]=(int)(n%2);
			n=n/(long)2;
			i++;
		}
		return ar;
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	public static int conversion(long A,long B)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int [] binaryOfA=binary(A);
		int [] binaryOfB=binary(B);
		int result=0;
		for(int i=0;i<100;i++)
		{
			if(binaryOfA[i]!=binaryOfB[i])
				result++;
		}
		return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String [] args)
	{
		Scanner sc=new Scanner(System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		System.out.println(conversion(a,b));
	}	
}
