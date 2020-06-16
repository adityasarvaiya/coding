import java.util.*;

class FlipBitToWin {
    public static int flipBitToWin(long n)
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		long [] ar=new long[100];
		long temp=n,flag=0,prev=0,maxx=-1;
		int j=1;
		while(temp!=0)
		{
			ar[j]=temp%(long)2;
			temp/=2;
			j++;
		}
		for(int i=1;i<j;i++)
		{
			flag=0;
			prev=0;
			if(ar[i]==0)
			{
				ar[i]=1;
				flag=1;
			}
			for(int k=1;k<j;k++)
			{
				if(ar[k]==1)
				{
					prev++;
				}
				else
				{
					prev=0;
				}
				maxx=Math.max(maxx,prev);
			}
			if(flag==1)
				ar[i]=0;
		}
		if(n==0)
			return 1;
		else
			return (int)maxx;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        scanner.close();
        int ans=flipBitToWin(n);
        System.out.println(ans);
    }
}
