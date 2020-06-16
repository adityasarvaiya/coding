import java.util.*;

class LettersAndNumbers {
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	static int [] acount = new int[100000];
	static int startidx = -1, endidx = -1;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	public static Vector<Integer> lettersAndNumbers(String s, int n) {
		//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int l;
		acount[0] = 0;
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		map.put(0, -1);
		for (int i = 0; i < n; i++) {
			if ((s.charAt(i) >= 65 && s.charAt(i) <= 90) || (s.charAt(i) >= 97 && s.charAt(i) <= 122) ) {
				if (i == 0)
					acount[i] = 1;
				else {
					acount[i] = acount[i - 1] + 1;
				}
			} else {
				if (i == 0)
					acount[i] = -1;
				else {
					acount[i] = acount[i - 1] - 1;
				}
			}
			if (map.containsKey(acount[i])) {
				l = map.get(acount[i]);
				if ((i - (l + 1)) > (endidx - startidx)) {
					startidx = l + 1;
					endidx = i;
				}
			} else {
				map.put(acount[i], i);
			}
		}
		Vector<Integer> ans = new Vector<Integer>();
		if (startidx == -1)
			ans.add(startidx);
		else {
			ans.add(startidx);
			ans.add(endidx);
		}
		return ans;
		//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		Vector<Integer> answer = lettersAndNumbers(s, n);
		for (int i = 0; i < answer.size(); i++) {
			System.out.print(answer.get(i) + " ");
		}
	}
}
