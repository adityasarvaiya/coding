import java.util.*;

public class CircularRace {
    static int circularRace(int n, ArrayList<Integer>gas, ArrayList<Integer>burn){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        ArrayList<Integer>diff = new ArrayList<Integer>();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            diff.add(gas.get(i)-burn.get(i));
            sum+= diff.get(i);
        }
        if(sum<0){
            return -1;
        }
        int idx = 0;
        sum = 0;
        for(int i = 0 ; i<n; i++) {
            sum+=diff.get(i);
            if(sum<0){
                idx = i+1;
                sum = 0;
            }
        }
        return idx+1;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ;
        ArrayList<Integer>gas = new ArrayList<Integer>();
        ArrayList<Integer>burn = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            gas.add(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            burn.add(sc.nextInt());
        }
        int ans = circularRace(n,gas,burn);
        System.out.print(ans);
        sc.close();
    }
}
