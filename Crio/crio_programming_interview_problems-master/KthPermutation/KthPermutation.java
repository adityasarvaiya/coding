import java.util.*;

public class KthPermutation {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long fact[];
    int freq[];
    String res;
    void rec(int idx , int k , int n) {
        if(idx >= n || k <= 0) {
            return ;
        }
        long sum = 0;
        for (int i = 0; i < n; i++) { 
            if (freq[i] == 0) 
                continue; 
            freq[i]--; 

            // System.out.println(v.length-idx);
            long numerator = fact[n-idx-1]; 
            for (int j = 0; j < 10; j++) {
                numerator /= fact[freq[j]];
            } 
            sum += numerator; 
            // System.out.println(idx + " " + i + " " + numerator + " " + sum + " " + k);
            if (sum >= k) { 
                res += (char)(i + 'A'); 
                rec(idx + 1 ,(int)(k - (sum - numerator) ) , n);
                break;
            } 
            if(sum < k) { 
                freq[i]++;
            }	 
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    String kthPermutation(int n , int k) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        char v[] = new char[n];
        for(int i = 0 ; i < n ; i++) {
            v[i] = (char)(i + 'A');
        }
        fact = new long[20];
        fact[0] = 1; 
        freq = new int[20];
        for(int i = 0 ; i < 20 ; i++) {
            freq[i] = 0;
        }
        for (int i = 1; i < fact.length; i++) {
            fact[i] = fact[i - 1] * i; 
        }
        for(int i = 0 ; i < v.length ; i++) {
            freq[v[i] - 'A']++;
        }
        res = new String("");
        rec(0 , k , n);
        return res;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n , k;
        n = scanner.nextInt();
        k = scanner.nextInt();
        String ans = new KthPermutation().kthPermutation(n , k);
        for(int i = 0 ; i < ans.length() ; i++) {
            System.out.print(ans.charAt(i));
        }
    }
    
}
