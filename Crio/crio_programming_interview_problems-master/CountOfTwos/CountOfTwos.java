import java.util.*;
public class CountOfTwos {
    int countOfTwos(int n) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int ans = 0;
        for (int i = 2 ; i <= n ; i++) {
            String temp = Integer.toString(i);
            int count = 0;
            for (int j = 0 ; j < temp.length() ; j++) {
                if (temp.charAt(j) == '2') {
                    count++;
                }
            }
            ans += count;
        }
        return ans;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int result = new CountOfTwos().countOfTwos(n);
        System.out.println(result);
        scanner.close();
    }
}