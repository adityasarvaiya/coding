import java.io.*;
import java.util.Scanner;
public class SpecialURL {

	public static String change(String s) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int n = s.length();
		String ans = new String();
		for ( int i = 0; i < n; i++) {
			if (s.charAt(i) == ' ')
				ans += "%20";
			else
				ans += s.charAt(i);
		}
		return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String args[]) throws Exception {

		Scanner sc  = new Scanner(System.in);

		String s = new String();
		String ans = new String();
		s = sc.nextLine();
		ans = change(s);
		System.out.print(ans);

	}
}

