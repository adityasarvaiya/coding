import java.util.*;
class MaxSubmatrix {
	public static long maxSubmatrix(int [][]arr, int n, int m) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		long ans = (long) - 1e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = Math.max(ans, arr[i][j]);
			}
		}
		if (ans < 0) return ans;
		for (int left = 0; left < m; left++) {
			long []maxCol = new long[n];
			for ( int right = left; right < m; right++) {
				for ( int k = 0; k < n; k++) {
					maxCol[k] = maxCol[k] + arr[k][right];
				}
				long temp = 0;
				for (int i = 0; i < n; i++) {
					temp += maxCol[i];
					if (temp < 0) temp = 0;
				}
				ans = Math.max(ans, temp);
			}
		}
		return ans;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int [][]arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		long ans = maxSubmatrix(arr, n, m);
		System.out.println(ans);
	}
}