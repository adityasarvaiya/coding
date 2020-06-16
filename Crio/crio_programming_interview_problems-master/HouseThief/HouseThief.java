import java.util.*;
class HouseThief {
	public static long houseThief(int n, int []arr) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		long []dp = new long[n + 1];
		dp[0] = arr[0];
		if (n == 1)
			return dp[0];
		dp[1] = Math.max(dp[0], arr[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = Math.max(dp[i - 1], (long)arr[i] + dp[i - 2]);
		}
		return dp[n - 1];
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	}
	public static void main(String []args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int []arr = new int [n];
		for ( int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		long ans = houseThief(n, arr);
		System.out.println(ans);

	}
}
