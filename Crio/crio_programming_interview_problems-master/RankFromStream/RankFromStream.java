import java.util.*;

public class RankFromStream {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int q = scanner.nextInt();
    Solution solution = new  Solution();

    for(int i = 0 ; i < q ; i++) {
        char ch = scanner.next().charAt(0);
        int x = scanner.nextInt();
        if(ch == '+') {
            solution.track(x);
        } else {
            System.out.println(solution.getRankOfNumber(x));
        }
    }
    }
}