import java.util.*;

class NetworkDelayTime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            ArrayList<Integer> b = new ArrayList<>();

            b.add(sc.nextInt());
            b.add(sc.nextInt());
            b.add(sc.nextInt());
            edges.add(b);
        }

        int k = sc.nextInt();

        int ans = NetworkDelayTime.networkDelayTime(n, edges, k);

        System.out.println(ans);
    }

    public static int networkDelayTime(int n, ArrayList<ArrayList<Integer>> edges, int k) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        ArrayList<Integer> dist = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            dist.add(Integer.MAX_VALUE);
        }

        dist.set(k - 1, 0);
        for (int i = 0; i < n + 1; i++) {

            ArrayList<Integer> tmp = (ArrayList) dist.clone();
            for (ArrayList<Integer> edge : edges) {

                if (dist.get(edge.get(0) - 1) != Integer.MAX_VALUE) {

                    tmp.set(edge.get(1) - 1,
                            Math.min(tmp.get(edge.get(1) - 1), tmp.get(edge.get(0) - 1) + edge.get(2)));
                }
                dist = tmp;
            }
        }

        int ans = Collections.max(dist);
        if (ans == Integer.MAX_VALUE) {
            return -1;
        }

        return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
