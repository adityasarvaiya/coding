import java.util.*;
public class MinCostOfRoad {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public static int findP(int u, int parent[]){
        if(parent[u]==u){
            return u;
        }
        parent[u] = findP(parent[u],parent);
        return parent[u];
    }
    public static void union(int u, int v, int parent[], int size[]){
        u = findP(u,parent);
        v = findP(v,parent);
        if(size[u]>size[v]){
            parent[v] = u;
            size[u]+=size[v];
        }
        else{
            parent[u] = v;
            size[v]+=size[u];
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static int minCostOfRoad(int n, ArrayList<ArrayList<Integer>> edges){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int e = edges.size();
        int parent[] = new int[n+1];
        int size[] = new int[n+1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        Collections.sort(edges, new Comparator<ArrayList<Integer>> () {
            @Override
            public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
                return a.get(2).compareTo(b.get(2));
            }
        });
        int idx = 0;
        int ans = 0;
        while(idx<e){
            int u = edges.get(idx).get(0);
            int v = edges.get(idx).get(1);
            int w = edges.get(idx).get(2);
            if(findP(u, parent)!=findP(v, parent)){
                union(u,v,parent,size);
                ans+=w;
            }
            idx++;
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,e;
        n = sc.nextInt();
        e = sc.nextInt();
        ArrayList<ArrayList<Integer>>edges = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < e; i++) {
            edges.add(new ArrayList<Integer>());
            edges.get(i).add(sc.nextInt());
            edges.get(i).add(sc.nextInt());
            edges.get(i).add(sc.nextInt());
        }
        int ans = minCostOfRoad(n,edges);
        System.out.print(ans);
        sc.close();
    }
}
