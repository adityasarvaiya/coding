import java.util.*;
class NextLargerElement {

	static int [] nextLargerElement(int ar[], int n) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Stack<Integer> s = new Stack<Integer>();

		int answer[] = new int[n];
		for (int i = n - 1 ; i >= 0; i--) {
			while (!s.isEmpty() && (s.peek() <= ar[i]))
				s.pop();
			if (s.empty())
				answer[i] = -1;
			else
				answer[i] = s.peek();
			s.push(ar[i]);
		}
		return answer;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ar[] = new int[n];
		for (int i = 0; i < n; i++) {
			ar[i] = sc.nextInt();
		}
		int [] ans = nextLargerElement(ar, n);
		for (int i = 0; i < ans.length; i++)
			System.out.print(ans[i] + " ");
	}
}
