import java.util.*;

class MinStack {
	static Stack<Integer> stack = new Stack<Integer>();
	static Stack<Integer> min = new Stack<Integer>();

	static void push(Integer e) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		stack.push(e);
		if (!min.empty()) {
			if (min.peek() >= e)
				min.push(e);
		} else
			min.push(e);
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	static void pop() {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

		if (!stack.empty()) {
			Integer element = (Integer) stack.pop();
			if (!min.empty()) {
				Integer x = (Integer) min.peek();
				if (x.equals(element)) {
					min.pop();

				}
			}
		}
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	static Integer findMin() {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

		if (!min.empty()) {
			Integer element = (Integer) min.peek();
			return element;
		} else
			return -1;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		Integer n = sc.nextInt();
		for (int i = 1; i <= n; i++) {
			Integer a = sc.nextInt();
			if (a == 1) {
				Integer e = sc.nextInt();
				push(e);
			}
			if (a == 2) {
				pop();
			}
			if (a == 3) {
				System.out.println(findMin());
			}
		}
	}
}
