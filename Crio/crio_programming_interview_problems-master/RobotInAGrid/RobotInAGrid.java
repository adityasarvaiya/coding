import java.util.*;

public class RobotInAGrid {

    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int visit[][];
    ArrayList<Integer>path;
    Vector<String> pathString;
    boolean isPath;
    boolean isValid(int x , int y , int n , int m , int grid[][]) {
        if(x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }
        if(grid[x][y] == 1 || visit[x][y] == 1) {
            return false;
        }
        return true;
    }
    void dfs(int x , int y , int grid[][] , int n , int m) {
        visit[x][y] = 1;
        path.add(x);
        path.add(y);
        if(x == n-1 && y == m-1) {
            for(int i = 0 ; i < path.size() ; i+=2) {
                pathString.add(Integer.toString(path.get(i)+1)+" "+Integer.toString(path.get(i+1)+1));
            }
            isPath = true;
            return;
        } 
        if(isValid(x+1, y, n, m, grid)) {
            dfs(x+1, y, grid , n , m);
        }
        if(isValid(x, y+1, n, m, grid)) {
            dfs(x, y+1, grid , n , m);
        }
        path.remove(path.size()-1);
        path.remove(path.size()-1);

    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    Vector<String> robotInAGrid(int grid[][] , int n , int m) {

        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        isPath = false;
        visit = new int[n][m];
        path = new ArrayList<>();
        pathString = new Vector<String>();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ;j < m ; j++) {
                visit[i][j] = 0;
            }
        }
        if(grid[0][0] == 1)
        {  
            Vector<String> st = new Vector<String>();
            st.add("Not Possible");
            return st;
        }
        dfs(0, 0, grid, n, m);
        if(isPath) {
            return pathString;
        } else {
            Vector<String> notposs = new Vector<String>();
            notposs.add("Not Possible");
            return notposs;
        }
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int grid[][] = new int[n][m];
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        RobotInAGrid answer = new RobotInAGrid();
        Vector<String> result = answer.robotInAGrid(grid , n , m);
        for(String elem : result)
        {
            System.out.println(elem);
        }
    }
}
