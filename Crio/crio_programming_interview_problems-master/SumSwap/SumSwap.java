import java.util.*;

class SumSwap {
	public static String sumSwap(int [] ar, int [] br, int n, int m) {
		//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		long sum1 = 0, sum2 = 0;
		HashMap<Long, Long> map = new HashMap<Long, Long>();
		for (int i = 0; i < n; i++) {
			sum1 += ar[i];
		}
		for (int i = 0; i < m; i++) {
			sum2 += br[i];
			if (map.containsKey((long)br[i]) == false)
				map.put((long)br[i], (long)1);
		}
		Vector<Long> ans = new Vector<Long>();
		long mid = (sum1 + sum2) / 2;
		if (sum1 == sum2) {
			ans.add((long)0);
		} else if (mid != (sum1 + sum2 + 1) / 2) {
			ans.add((long) - 1);
		} else {
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (sum1 < sum2) {
					if (map.containsKey(mid - sum1 + ar[i])) {
						ans.add((long)ar[i]);
						ans.add(mid - sum1 + ar[i]);
						flag = 1;
						break;
					}
				}
				if (sum1 > sum2) {
					if (sum1 - ar[i] - mid >= (long)0) {
						if (map.containsKey(sum1 - mid - ar[i])) {
							ans.add((long)ar[i]);
							ans.add(sum1 - mid - ar[i]);
							flag = 1;
							break;
						}
					} else {
						if (map.containsKey(mid - (sum1 - ar[i]))) {
							ans.add((long)ar[i]);
							ans.add(mid - (sum1 - ar[i]));
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 0)
				ans.add((long) - 1);
		}
		if (ans.get(0) == 0)
			return "ALREADY EQUAL";
		else if (ans.get(0) == -1)
			return "NOT POSSIBLE";
		else
			return "POSSIBLE";
		//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int [] ar = new int[n];
		int [] br = new int[m];
		for (int i = 0; i < n; i++)
			ar[i] = sc.nextInt();
		for (int i = 0; i < m; i++)
			br[i] = sc.nextInt();
		System.out.println(sumSwap(ar, br, n, m));
	}
}
