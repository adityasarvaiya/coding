import java.util.*;
public class CobbledStreets {
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
    public static int cobbledStreets(int n, ArrayList<ArrayList<Integer>> street, int p){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int e = street.size();
        int parent[] = new int[n+1];
        int size[] = new int[n+1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        Collections.sort(street, new Comparator<ArrayList<Integer>> () {
            @Override
            public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
                return a.get(2).compareTo(b.get(2));
            }
        });
        int idx = 0;
        int ans = 0;
        while(idx<e){
            int u = street.get(idx).get(0);
            int v = street.get(idx).get(1);
            int w = street.get(idx).get(2);
            if(findP(u, parent)!=findP(v, parent)){
                union(u,v,parent,size);
                ans+=w;
            }
            idx++;
        }
        return ans*p;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,e,t,p;
        t = sc.nextInt();
        while(t>0){
            t--;
            p = sc.nextInt();
            n = sc.nextInt();
            e = sc.nextInt();
            ArrayList<ArrayList<Integer>>street = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < e; i++) {
                street.add(new ArrayList<Integer>());
                street.get(i).add(sc.nextInt());
                street.get(i).add(sc.nextInt());
                street.get(i).add(sc.nextInt());
            }
            int ans = cobbledStreets(n,street,p);
            System.out.println(ans);
        }
        sc.close();
    }
}
