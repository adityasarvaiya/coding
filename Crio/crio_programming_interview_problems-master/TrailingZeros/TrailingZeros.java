import java.util.*;

class TrailingZeros {

    static long findTrailingZeros(long n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        long count = 0;

        for (long i = 5; n / i >= 1; i *= 5)
            count += n / i;

        return count;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(findTrailingZeros(n));
    }
}