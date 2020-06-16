import java.util.*;

class FizzBuzz{
	public static String [] fizzBuzz(int n)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		String [] result=new String[n];
		for(int i=1;i<=n;i++)
		{
			if(i%3==0 && i%5==0)
				result[i-1]="FizzBuzz";
			else if(i%3==0)
				result[i-1]="Fizz";
			else if(i%5==0)
				result[i-1]="Buzz";
			else
				result[i-1]=Integer.toString(i);
		}
		return result;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String [] args)
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String [] ans=fizzBuzz(n);
		for(int i=0;i<ans.length;i++)
		{
			System.out.println(ans[i]);
		}
	}
}
