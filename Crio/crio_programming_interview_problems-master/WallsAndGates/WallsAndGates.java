import java.util.*;
import java.io.*;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Entity {
	int first, second, third;
	Entity(int x, int y, int z) {
		first = x;
		second = y;
		third = z;
	}
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
class WallsAndGates {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

	public static int dx[] = {1, -1, 0, 0};
	public static int dy[] = {0, 0, -1, 1};

	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	public static int[][] WallsAndGates(int [][] grid , int n, int m) {

		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int [][] distance = new int [n + 1][m + 1];
		Queue<Entity> Q = new LinkedList<Entity>();
		for ( int i = 0; i < n; i++) {
			for ( int j = 0; j < m; j++) {
				if ( grid[i][j] == 0) {
					Entity p = new Entity(0, i, j);
					Q.add(p);
					distance[i][j] = 0;
				} else if (grid[i][j] == -1) {
					distance[i][j] = -1;
				} else {
					distance[i][j] = grid[i][j];
				}
			}
		}
		while (!Q.isEmpty()) {
			Entity P = Q.remove();
			int d = P.first, x = P.second, y = P.third;
			for ( int i = 0; i < 4; i++) {
				x = P.second + dx[i]; y = P.third + dy[i];
				if (x >= n || x < 0 || y >= m || y < 0) continue;

				if (grid[x][y] == -1) {
					distance[x][y] = -1;
					continue;
				}
				if (distance[x][y] > d + 1) {
					Entity p = new Entity(d + 1, x, y);
					Q.add(p);
					distance[x][y] = d + 1;
				}
			}
		}
		return distance;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String []args) {
		int n, m;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		int [][] grid = new int[n + 1][m + 1];
		for ( int i = 0; i < n; i++) {
			for ( int j = 0; j < m; j++) {
				grid[i][j] = sc.nextInt();
			}
		}
		int [][] distance = WallsAndGates(grid, n, m);
		for ( int i = 0; i < n; i++) {
			for ( int j = 0; j < m; j++) {
				System.out.print(distance[i][j] + " ");
			}
			System.out.println();
		}
	}
}
