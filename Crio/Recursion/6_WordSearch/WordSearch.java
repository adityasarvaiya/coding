import java.io.*;
import java.util.*;

public class WordSearch {
    public boolean exist(char[][] board, String word) {
         // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int row = board.length;
        int col = board[0].length;
        if(word.length() > row*col) {
            return false;
        }
        visit = new boolean[row][col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if((word.charAt(0) == board[i][j])) {
                    boolean answer = dfs(board, word, i, j, 0);
                    if(answer) {
                        return answer;
                    }
                }
            }
        }
        return false;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
     // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    boolean[][] visit;
    private boolean dfs(char[][]board, String word, int i, int j, int index){
        if(index == word.length()){
            return true;
        }        
        if(i >= board.length || i < 0 || j >= board[i].length || j < 0){
            return false;
        }
        if(board[i][j] != word.charAt(index) || visit[i][j]) {
            return false;
        }        
        visit[i][j] = true;
        if(dfs(board, word, i-1, j, index+1) || 
           dfs(board, word, i+1, j, index+1) ||
           dfs(board, word, i, j-1, index+1) || 
           dfs(board, word, i, j+1, index+1)){
            return true;
        }
        visit[i][j] = false;
        return false;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int row = scanner.nextInt();
        int col = scanner.nextInt();
        char board[][] = new char [row][col];
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col;  j++) {
                board[i][j] = scanner.next().charAt(0);
            }
        }
        String word = scanner.next();
        scanner.close();
        boolean result = new WordSearch().exist(board , word);
        System.out.println(result);
    }
}
