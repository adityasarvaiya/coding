import java.util.*;
import java.io.*;
class EvaluateExpression {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public static Long eval( Long a , Long b , char ch) {
		if (ch == '+')
			return (a + b);
		else if (ch == '-')
			return (a - b);
		else if ( ch == '/')
			return a / b;
		else
			return a * b;
	}
	public static boolean isOperator(String ch) {
		char c = ch.charAt(0);
		return ch.length() == 1 && (c == '/' || c == '*' || c == '+'  || c == '-');
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	public static Long evaluateExpression(Long n , ArrayList<String> expresion) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Stack<Long> S = new Stack<Long>();

		for ( int i = 0; i < n; i++) {
			String ch = expresion.get(i);
			if (!isOperator(ch)) {
				S.push( Long.parseLong(ch));
			} else {
				Long b = S.pop();
				Long a = S.pop();
				Long c =  eval(a, b, ch.charAt(0));
				S.push(c);
			}
		}
		Long answer = S.pop();
		return answer;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		Long n = sc.nextLong();
		ArrayList<String> A = new ArrayList<String> ();
		for ( int i = 0; i < n; i++) {
			String s = sc.next();
			A.add(s);
		}
		Long answer = evaluateExpression(n, A);
		System.out.print( answer + " ");
	}
}
