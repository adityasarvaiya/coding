import java.util.*;

public class NQueens {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    String answer;
    void place(int index , int[] column , int n) {
       if(index == n) {
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < n ; j++) {
                    if(column[j] == i) {
                        answer += '1';
                    } else {
                        answer += '0';
                    }
                }
                answer += '\n';
            }
            answer += '\n';
            return;
        }
        for(int i = 0 ; i < n ; i++) {
            boolean canPlace = true;
            for(int j = 0 ; j < index ; j++) {
                if(column[j] == i) {
                    canPlace = false;
                    break;
                }
                if(Math.abs(column[j] - i) == Math.abs(index-j)) {
                    canPlace = false;
                    break;
                }
            }
            if(canPlace) {
                column[index] = i;
                place(index+1, column , n);
            }
        }
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    String nQueens(int n) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        answer = new String();
        int column[] = new int[n];
        place(0 , column , n);
        boolean isAns = false;
        for(int i = 0 ; i < answer.length() ; i++) {
            if(answer.charAt(i) == '1') {
                isAns = true;
            }
        }
        if(isAns == false) {
            return "No Solution Exists";
        }
        return answer;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n =  scanner.nextInt();
        scanner.close();
        NQueens result = new NQueens();
        String board = result.nQueens(n);
        System.out.println(board);
    }
}