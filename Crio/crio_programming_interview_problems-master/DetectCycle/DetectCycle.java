import java.util.*;
import java.io.*;

class DetectCycle {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t;
		t = sc.nextInt();
		while ((t--) > 0) {
			int nodes = sc.nextInt();
			int e = sc.nextInt();
			ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
			for (int i = 0; i < e; i++) {
				ArrayList<Integer> b = new ArrayList<Integer>();
				b.add(sc.nextInt());
				b.add(sc.nextInt());
				edges.add(b);
			}
			String ans = DetectCycle.detectCycle(nodes, edges);
			System.out.println(ans);
		}
	}

	public static String detectCycle(int nodes, ArrayList<ArrayList<Integer>> edges) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
		for (int i = 0; i < nodes + 1; i++) {
			adj.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < edges.size(); i++) {
			int x = edges.get(i).get(0);
			int y = edges.get(i).get(1);
			adj.get(x).add(y);
			adj.get(y).add(x);
		}
		ArrayList<Boolean> vis = new ArrayList<>();
		for (int i = 0; i < nodes + 1; i++)
			vis.add(false);
		for (int i = 1; i <= nodes; i++) {
			if (!vis.get(i) && DetectCycle.go(i, -1, adj, vis) == true) {
				return "Yes";
			}
		}
		return "No";
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	}

	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public static boolean go(int x, int p, ArrayList<ArrayList<Integer>> adj, ArrayList<Boolean> vis) {
		if (vis.get(x))
			return true;
		vis.set(x, true);
		for (int i : adj.get(x)) {
			if (i == p) {
				continue;
			}
			if (go(i, x, adj, vis) == true)
				return true;
		}
		return false;
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
