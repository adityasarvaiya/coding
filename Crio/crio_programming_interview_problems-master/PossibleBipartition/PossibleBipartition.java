import java.util.*;
class PossibleBipartition {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	private static Vector<Vector<Integer> > createAdjList(int n, Vector<Vector<Integer> > edges) {
		Vector<Vector<Integer> > adjList = new Vector<Vector<Integer> >();
		for (int i = 0; i <= n; i++) {
			Vector<Integer> temp = new Vector<Integer>();
			adjList.add(temp);
		}
		for (int i = 0; i < edges.size(); i++) {
			adjList.get(edges.get(i).get(0)).add(edges.get(i).get(1));
			adjList.get(edges.get(i).get(1)).add(edges.get(i).get(0));
		}
		return adjList;
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	private static String possibleBipartition(int n, Vector<Vector<Integer> > edges) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		Vector<Vector<Integer> > vec = createAdjList(n, edges);
		Queue<Integer> q = new LinkedList<Integer>();
		int [] level = new int[n + 1];
		q.add(1);
		level[1] = 1;
		int flag = 0;
		while (q.size() != 0) {
			int front = q.poll();
			for (int i = 0; i < vec.get(front).size(); i++) {
				if (level[vec.get(front).get(i)] == 0) {
					level[vec.get(front).get(i)] = level[front] + 1;
					q.add(vec.get(front).get(i));
				} else if ((level[vec.get(front).get(i)] % 2 == 0 && (level[front] + 1) % 2 == 1) || (level[vec.get(front).get(i)] % 2 == 1 && (level[front] + 1) % 2 == 0))
					flag = 1;
			}
		}
		if (flag == 0)
			return "Possible";
		else
			return "Not Possible";

// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int tests = 0; tests < t; tests++) {
			int n = sc.nextInt();
			int m = sc.nextInt();

			Vector<Vector<Integer> > edges = new Vector<Vector<Integer> >();
			for (int i = 0; i < m; i++) {
				int u = sc.nextInt();
				int v = sc.nextInt();
				Vector<Integer> edge = new Vector<Integer>();
				edge.add(u);
				edge.add(v);
				edges.add(edge);
			}
			System.out.println(possibleBipartition(n, edges));
		}

	}
}
