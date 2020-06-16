import java.util.*;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Pair {
    private Integer x;
    private Integer y;
    Pair(Integer x, Integer y) {
        this.x = x;
        this.y = y;
    }
    public Integer getX() {
        return x;
    }
    public Integer getY() {
        return y;
    }
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class StockSpan {

	static int [] stockSpan(int ar[], int n) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Stack< Pair > s = new Stack< Pair >();

		int answer[] = new int[n];
		for (int i = 0 ; i < n; i++) {
			while (!s.isEmpty() && ((s.peek()).getX() <= ar[i]))
				s.pop();
			if (s.empty())
				answer[i] = i + 1;
			else
				answer[i] = (i + 1) - (s.peek()).getY();
			Pair p = new Pair(ar[i], i + 1);
			s.push(p);
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
		int [] answer = stockSpan(ar, n);
		for (int i = 0; i < answer.length; i++)
			System.out.print(answer[i] + " ");
	}
}
