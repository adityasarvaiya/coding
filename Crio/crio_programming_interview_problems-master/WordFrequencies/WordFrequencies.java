import java.util.*;

class Pair {
    private String x;
    private Integer y;
    Pair(String x, Integer y) {
        this.x = x;
        this.y = y;
    }
    public String getX() {
        return x;
    }
    public Integer getY() {
        return y;
    }
}

class WordFrequencies {
	public static Vector<Pair> wordFrequencies(String [] words) {

		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int n = words.length;
		TreeMap<String, Integer> map = new TreeMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			if (map.get(words[i]) != null) {
				Integer temp = map.get(words[i]);
				map.replace(words[i], temp + (Integer)1);
			} else
				map.put(words[i], (Integer)1);
		}
		Vector<Pair> ans = new Vector<Pair>();
		int i = 0;
		for (Map.Entry<String, Integer> m : map.entrySet()) {
			String s = m.getKey();
			Integer y = m.getValue();
			Pair temp = new Pair(s, y);
			ans.add(temp);
			i++;
		}
		return ans;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String [] inp = new String [n];
		for (int i = 0; i < n; i++) {
			inp[i] = sc.next();
		}
		Vector<Pair> ans = wordFrequencies(inp);
		for (int i = 0; i < ans.size(); i++) {
			System.out.println(ans.get(i).getX() + " " + ans.get(i).getY());
		}
	}
}
