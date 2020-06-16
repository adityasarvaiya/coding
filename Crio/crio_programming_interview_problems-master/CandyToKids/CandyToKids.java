import java.util.*;

public class CandyToKids {
    static int candyToKids(int n, ArrayList<Integer>goodness){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int l[] = new int[n];
        Arrays.fill(l, 1);
        int r[] = l.clone();
        for (int i = 0; i < n-1; i++) {
            if(goodness.get(i+1)>goodness.get(i)){
                l[i+1]=l[i]+1;
            }
        }
        for(int i = n-1; i>0; i--){
            if(goodness.get(i-1)>goodness.get(i)){
                r[i-1]=r[i]+1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum+=Math.max(l[i], r[i]);
        }
        return sum;        
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer>goodness = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            goodness.add(sc.nextInt());
        }
        int ans = candyToKids(n,goodness);
        System.out.print(ans);
        sc.close();
    }
}