import java.io.*;
import java.util.*;

class SetMatrixZeroes {
    public void setMatrixZeroes(int[][] matrix) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int rowWithZero = -1;
        int n = matrix.length;
        if(n == 0) {
            return;
        }
        int m = matrix[0].length;
        
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                if(matrix[i][j] == 0) {
                    rowWithZero = i;
                }
            }
        }
        if(rowWithZero == -1) {
            return;
        }
        
        for(int j = 0 ; j < m ; ++j) {
            if(matrix[rowWithZero][j] == 0) {
                matrix[rowWithZero][j] = 1;
            } else {
                matrix[rowWithZero][j] = 0;
            }
        }
        
        
        
        for(int i = 0 ; i < n ; ++i) {
            if(i == rowWithZero) {
                continue;
            }
            Boolean containsZero = false;
            
            for(int j = 0 ; j < m ; ++j) {
                if(matrix[i][j] == 0) {
                    containsZero = true;
                    matrix[rowWithZero][j] = 1;
                }
            }
            
            for(int j = 0 ; j < m ; ++j) {
                if(containsZero) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0 ; i < n ; ++i) {
            if(i == rowWithZero) {
                continue;
            }
            for(int j = 0 ; j < m ; ++j) {
                if(matrix[rowWithZero][j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 0 ; j < m ; ++j) {
            matrix[rowWithZero][j] = 0;
        }
        return;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        int[][] matrix = new int[n][m];

        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                matrix[i][j] = in.nextInt();
            }
        }

        in.close();
        new SetMatrixZeroes().setMatrixZeroes(matrix);

        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                System.out.print(matrix[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
    }
}