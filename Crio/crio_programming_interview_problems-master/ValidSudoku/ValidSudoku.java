import java.io.*;
import java.util.*;

class ValidSudoku {
     // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    public boolean check(int i , int j , char[][] board) {
        int temp[] = new int[10];
        for(int p = 0; p < 10 ; p++) {
                temp[p] = 0;
        }
        for(int row = 0 ; row < 3 ; row++) {
            for(int col = 0 ; col < 3 ; col++) {
                if(board[i + row][j + col] != '.') {
                    int x = board[i + row][j + col] - '0';
                    if(temp[x] != 1) {
                        temp[x] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    return true;
    }
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS    
     // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    // complete the below function implementation
    public boolean isValidSudoku(char[][] board) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        for(int i = 0 ; i < 9 ; i++) {
            int temp[] = new int[10];
            for(int j = 0; j < 10 ; j++) {
                temp[j] = 0;
            }
            for(int j = 0 ; j < 9 ; j++) {
                if(board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    if(temp[x] == 0) {
                        temp[x] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
            for(int j = 0; j < 10 ; j++) {
                temp[j] = 0;
            }
            for(int j = 0 ; j < 9 ; j++) {
                if(board[j][i] != '.') {
                    int x = board[j][i] - '0';
                    if(temp[x] != 1) {
                        temp[x] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        boolean answer = true;
        for(int i = 0 ; i < 9 ; i+=3) {
            for(int j = 0 ; j < 9 ; j+=3) {
                answer = answer & check(i,j,board);
            }
        }
        return answer;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        // return true;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS  
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char board[][] = new char[9][9];
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
                board[i][j] = scanner.next().charAt(0);
            }
        }
        scanner.close();
        boolean result = new ValidSudoku().isValidSudoku(board);
        System.out.println(result);
    }
}