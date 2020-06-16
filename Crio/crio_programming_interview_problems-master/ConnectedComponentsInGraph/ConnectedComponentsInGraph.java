import java.util.*;

public class ConnectedComponentsInGraph {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	
    ArrayList<ArrayList<Integer> > graph = new ArrayList<ArrayList<Integer> >();
    int visited[];
    void init(int n) {
        this.visited = new int[n + 1];
        for (int i = 0 ; i <= n ; i++) {
            this.visited[i] = 0;
        }
    }
    void dfs(int src) {
        this.visited[src] = 1;
        for (int i = 0 ; i < this.graph.get(src).size() ; i++) {
            int child = graph.get(src).get(i);
            if (visited[child] == 0) {
                visited[child] = 1;
                dfs(child);
            }
        }
        return ;
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    int connectedComponentsInGraph(int n,  ArrayList<ArrayList<Integer>> edges) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        for(int i=0;i<n+1;i++){
            graph.add(new ArrayList<Integer>());
        }
        int m = edges.size();
        for(int i=0;i<m;i++){
            int x,y;
            x=edges.get(i).get(0);
            y=edges.get(i).get(1);
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        int ans=0;
        for(int  i=1; i<= n;i++)
        {
            if (this.visited[i]==0)
            {
                ans++;
                dfs(i);
            }
        }
        return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
    
        for(int i=0;i<m;i++){
            edges.add(new ArrayList<Integer>());
            edges.get(i).add(scanner.nextInt());
            edges.get(i).add(scanner.nextInt());
        }
        ConnectedComponentsInGraph answer = new ConnectedComponentsInGraph();
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        answer.init(n);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        int result = answer.connectedComponentsInGraph(n, edges);
        System.out.println(result);
        scanner.close();
    }
}
