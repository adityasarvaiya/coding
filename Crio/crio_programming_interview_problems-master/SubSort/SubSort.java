import java.util.*;

class SubSort {
	public static Vector<Integer> subSort(int [] ar, int n) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int l = 0, r = 0, s = 0, e = n - 1;
		int mx = ar[0] , mn = ar[n - 1];
		int lflag = 0, rflag = 0;
		Vector<Integer> ans = new Vector<Integer>();
		for ( int i = 1; i < n; i++) {
			if (ar[i] < mx) {
				l = i - 1;
				lflag = 1;
				break;
			}
			mx = Math.max(ar[i], mx);
		}
		for ( int i = n - 2; i >= 0; i--) {
			if ( ar[i] > mn) {
				r = i + 1;
				rflag = 1;
				break;
			}
			mn = Math.min(ar[i] , mn);
		}

		if (lflag == 0 && rflag == 0) {
			ans.add(-1);
			ans.add(-1);
			return ans;
		}

		for ( int i = l ; i < r ; i++) {
			mn = Math.min(ar[i], mn);
			mx = Math.max(ar[i], mx);
		}

		for ( int i = 0; i < l; i++) {
			if (ar[i] > mn) {
				l = i;
				break;
			}
		}

		for ( int i = n - 1; i >= r; i--) {
			if ( ar[i] < mx) {
				r = i; break;
			}
		}
		ans.add(l);
		ans.add(r);
		return ans;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] ar = new int[n];
		for (int i = 0; i < n; i++) {
			ar[i] = sc.nextInt();
		}
		Vector<Integer> answer = subSort(ar, n);
		for (int i = 0; i < answer.size(); i++)
			System.out.print(answer.get(i) + " ");
	}
}