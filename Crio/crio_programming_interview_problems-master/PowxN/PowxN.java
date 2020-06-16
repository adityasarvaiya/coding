import java.io.*;
import java.util.*;

class PowxN {
    public long myPow(long x, long n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        long result = new PowxN().answer(x, n, 1000000007);
        return result;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public long answer(long x, long n, long mod) {
        if (n == 0)
            return 1;
        long ans = 1;
        x = x % mod;
        if (n % 2 == 0) {
            ans = answer(x, n / 2, mod);
            ans = (ans * ans) % mod;
        }
        if (n % 2 == 1) {
            ans = answer(x, n / 2, mod);
            ans = (ans * ans) % mod;
            ans = (ans * x) % mod;
        }
        return ans;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        long x = scanner.nextLong();
        long n = scanner.nextLong();
        scanner.close();

        long result = new PowxN().myPow(x, n);
        System.out.print(result);
    }
}