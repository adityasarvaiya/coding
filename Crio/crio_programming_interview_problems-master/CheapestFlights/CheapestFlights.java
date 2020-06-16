import java.util.*;

public class CheapestFlights {

    public static int cheapestFlights(int n, ArrayList<ArrayList<Integer>>flight, int source, int des, int k){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int M[][] = new int[n+1][n+1];
        for (ArrayList<Integer> edge : flight) {
            M[edge.get(0)][edge.get(1)] = edge.get(2);
        }
        PriorityQueue<int[]>q=new PriorityQueue<int[]>(new Comparator<int[]> () {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });
        int[] temp = new int[]{0,source,k+1};
        q.add(temp);
        while(!q.isEmpty()){
            temp = q.remove();
            int c = temp[0];
            int u = temp[1];
            int K = temp[2];
            if(u==des){
                return c;
            }
            if(K>0){
                for (int i = 1; i <= n; i++) {
                    if(M[u][i]>0){
                        int temp1[] = new int[3];
                        temp1[0] = (c+M[u][i]);
                        temp1[1] = (i);
                        temp1[2] = (K-1);
                        q.add(temp1);
                    }                    
                }
            }
        }
        return -1;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();
        ArrayList<ArrayList<Integer>>flight = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < e; i++) {
            flight.add(new ArrayList<Integer>());
            flight.get(i).add(sc.nextInt());
            flight.get(i).add(sc.nextInt());
            flight.get(i).add(sc.nextInt());
        }
        int source = sc.nextInt();
        int des = sc.nextInt();
        int k = sc.nextInt();
        int ans = cheapestFlights(n,flight,source,des,k);
        System.out.print(ans);
        sc.close();
    }
}