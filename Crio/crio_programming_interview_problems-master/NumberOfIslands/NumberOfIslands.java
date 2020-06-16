import java.io.*;
import java.util.*;

class NumberOfIslands {

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public void dfs(int i , int j , char[][] grid , int[][] visited , int component) {
        int rows = grid.length;
        int columns = grid[0].length;
        if(i >= rows || i < 0 || j >= columns || j < 0) {
            return;
        }
        if(grid[i][j] == '0') {
            return;
        }
        if(visited[i][j] > 0) {
            return;
        }
        visited[i][j] = component;
        dfs(i-1,j,grid,visited,component);
        dfs(i+1,j,grid,visited,component);
        dfs(i,j-1,grid,visited,component);
        dfs(i,j+1,grid,visited,component);
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public int numIslands(char[][] grid) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int rows = grid.length;
        if(rows == 0) {
            return 0;
        }
        int columns = grid[0].length;
        
        int[][] visited = new int[rows][columns];
        
        for(int i = 0 ; i < rows ; ++i) {
            for(int j = 0 ; j < columns ; ++j) {
                visited[i][j] = 0;
            }
        }
        
        int res = 0;
        for(int i = 0 ; i < rows ; ++i) {
            for(int j = 0 ; j < columns ; ++j) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                    res++;
                    dfs(i , j , grid , visited , res);
                }
            }
        }
        return res;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int rows = in.nextInt();
        int columns = in.nextInt();
        char[][] grid = new char[rows][columns];

        for(int i = 0 ; i < rows ; ++i) {
            String s = in.next();
            for(int j = 0 ; j < columns ; ++j) {
                grid[i][j] = s.charAt(j);
            }
        }
        in.close();
        int result = new NumberOfIslands().numIslands(grid);
        System.out.println(result);
    }
}