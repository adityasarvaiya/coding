import java.util.*;

public class BalancedBraces {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ArrayList<String>balanced;
    boolean isBalanced(char bracket[]) {
        int open = 0 , close = 0;
        for(int i = 0 ; i < bracket.length ; i++) {
            if(bracket[i] == '(') {
                open++;
            } else {
                close++;
            }
            if(close > open) {
                return false;
            }
        }
        if(open == close) {
            return true;
        }
        return false;
    }
    void findBalanced(int idx , char bracket[] , int n) {
        if(idx == n) {
            if(isBalanced(bracket)) {
                String res = new String();
                for(int i = 0 ; i < bracket.length ; i++) {
                    res += bracket[i];
                }
                balanced.add(res);
            }
            return ;
        }
        bracket[idx] = '(';
        findBalanced(idx+1, bracket, n);
        bracket[idx] = ')';
        findBalanced(idx+1, bracket, n);
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    ArrayList<String> balancedBraces(int n) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        char bracket[] = new char[2*n];
        balanced = new ArrayList<String>();
        findBalanced(0, bracket, 2*n);
        return balanced;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<String> answer = new BalancedBraces().balancedBraces(n);
        for(int i = 0 ; i < answer.size() ; i++) {
            System.out.println(answer.get(i));
        }
    }
}
