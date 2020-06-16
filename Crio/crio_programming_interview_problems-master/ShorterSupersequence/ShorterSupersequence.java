import java.util.*;
import java.io.*;

public class ShorterSupersequence {

    int shortestSupersequence(int smaller_size , ArrayList<Integer> smaller_array , int larger_size , ArrayList<Integer> larger_array ) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        int l = 0, r = 0;
        HashMap<Integer, Integer> M = new HashMap<Integer, Integer> ();
        for ( int i = 0; i < smaller_size; i++) {
            int key = smaller_array.get(i);
            M.put(key , M.getOrDefault(key, 0) + 1);
        }

        int count = 0;
        int required = M.size();
        int ans = (int)1e9;

        HashMap<Integer, Integer> M1 = new HashMap<Integer, Integer> ();

        while ( r < larger_size) {
            int key = larger_array.get(r);
            M1.put(key , M1.getOrDefault(key, 0) + 1);
            if ( M.getOrDefault(key, 0) > 0 && M1.get(key) == M.get(key)) {
                count++;
            }

            while (count == required && l <= r) {
                key = larger_array.get(l);
                ans = Math.min(ans, r - l + 1);
                M1.put(key, M1.get(key) - 1);
                if (M.getOrDefault(key, 0) > 0 && M.getOrDefault(key, 0) > M1.getOrDefault(key, 0)) {
                    count--;
                }
                l++;
            }
            r++;
        }

        if (ans == 1e9) ans = -1;
        return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer> ar = new ArrayList<Integer>();
        ArrayList<Integer> br = new ArrayList<Integer>();
        for (int p = 0 ; p < n ; p++) {
            ar.add(scanner.nextInt());
        }
        for (int p = 0 ; p < m ; p++) {
            br.add(scanner.nextInt());
        }
        int result = 0;
        if (n < m) {
            result = new ShorterSupersequence().shortestSupersequence(n, ar, m, br);
        } else {
            result = new ShorterSupersequence().shortestSupersequence(m, br, n, ar);
        }
        System.out.print(result);
        scanner.close();
    }
}
