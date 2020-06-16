import java.util.*;
public class MinimumJumps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<>();

        for(int i=0;i<n;i++){
            a.add(sc.nextInt());
        }
        int ans = minimumJumps(n,a);
        System.out.println(ans);
        sc.close();
    }
    static int minimumJumps(int n,ArrayList<Integer> a){
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int INT_MAX = 3000;
        ArrayList<Integer> jumps=new ArrayList<>();
        for(int i=0;i<n;i++){
            jumps.add(INT_MAX);
        }
        jumps.set(0,0);
        for(int i=1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(j+a.get(j)>=i){
                    jumps.set(i,Math.min(jumps.get(i),jumps.get(j)+1));
                }
            }
        }

        if(jumps.get(n-1)==INT_MAX){
            return -1;
        }
        return jumps.get(n-1);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    }
}
