import java.util.*;

class Solution{

	Scanner sc=new Scanner(System.in);
	int n;
	int ar[]=new int[100000+5];
	public void readInput()
	{
		n=sc.nextInt();
		for(int i=1;i<=n;i++)
		{
			ar[i]=sc.nextInt();
		}
	}
	public int [] solve()
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Arrays.sort(ar,1,n);
		int answer[]=new int[n+1];
		int j=1,k=n/2;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1)
			{
				answer[i]=ar[k];
				k++;
			}
			else
			{
				answer[i]=ar[j];
				j++;
			}
		}
		return answer;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
}
