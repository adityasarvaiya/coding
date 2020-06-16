import java.util.*;


class TheMesseuse{
	public static long theMesseuse(int [] time,int len)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		long [] dp= new long [len];
		dp[0]= time[0];
		dp[1] = time[1];
		for (int i = 2; i < len; i++) {
			dp[i] = Math.max(dp[i - 1], dp[i - 2] + time[i]);
		}
		return dp[len-1];
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ar = new int[n];
		for (int i = 0; i < n; i++)
			ar[i] = sc.nextInt();
		System.out.println(theMesseuse(ar, n));
	}
}
