import java.io.*;
import java.util.*;

class SurroundedRegions {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	public static int getRowMajorIndex(int i , int j , int rows , int columns) {
		if (i <= 0 || i > rows) {
			return 0;
		}
		if (j <= 0 || j > columns) {
			return 0;
		}
		return (i - 1) * columns + j;
	}
	public static char getCellChar(char[][] board , int i , int j) {
		int rows = board.length;
		int columns = board[0].length;

		if (i < 0 || i >= rows) {
			return 'O';
		}
		if (j < 0 || j >= columns) {
			return 'O';
		}
		return board[i][j];
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	public void surroundedRegions(char[][] board) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int rows = board.length;
		if (rows == 0) {
			return;
		}
		int columns = board[0].length;

		DisjointSetUnion connected = new DisjointSetUnion(rows * columns + 1);

		for (int i = 0 ; i < rows ; ++i) {
			for (int j = 0 ; j < columns ; ++j) {
				if (board[i][j] == 'O') {
					if (getCellChar(board , i - 1 , j) == 'O') {
						connected.join(getRowMajorIndex(i + 1 , j + 1 , rows , columns) , getRowMajorIndex(i , j + 1, rows , columns));
					}
					if (getCellChar(board , i + 1 , j) == 'O') {
						connected.join(getRowMajorIndex(i + 1 , j + 1 , rows , columns) , getRowMajorIndex(i + 2, j + 1 , rows , columns));
					}
					if (getCellChar(board , i , j - 1) == 'O') {
						connected.join(getRowMajorIndex(i + 1 , j + 1 , rows , columns) , getRowMajorIndex(i + 1, j , rows , columns));
					}
					if (getCellChar(board , i , j + 1) == 'O') {
						connected.join(getRowMajorIndex(i + 1 , j + 1 , rows , columns) , getRowMajorIndex(i + 1, j + 2 , rows , columns));
					}
				}
			}
		}

		for (int i = 0 ; i < rows ; ++i) {
			for (int j = 0 ; j < columns ; ++j) {
				if (connected.root(getRowMajorIndex(i + 1 , j + 1 , rows , columns)) != connected.root(0)) {
					board[i][j] = 'X';
				}
			}
		}
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rows = scanner.nextInt();
		int columns = scanner.nextInt();
		char[][] board = new char[rows][columns];
		for (int i = 0 ; i < rows ; ++i) {
			for (int j = 0 ; j < columns ; ++j) {
				board[i][j] = scanner.next().charAt(0);
			}
		}
		scanner.close();

		new SurroundedRegions().surroundedRegions(board);

		for (int i = 0 ; i < rows ; ++i) {
			for (int j = 0 ; j < columns ; ++j) {
				System.out.printf("%c " , board[i][j]);
			}
			System.out.println();
		}
	}
}

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class DisjointSetUnion {
	private int n;
	private int[] parent;
	private int[] size;
	DisjointSetUnion(int n) {
		this.n = n;
		this.parent = new int[n];
		this.size = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			this.parent[i] = i;
			this.size[i] = 1;
		}
	}
	public int root(int x) {
		if (this.parent[x] == x) {
			return x;
		}
		return this.parent[x] = root(this.parent[x]);
	}
	public void join(int a , int b) {
		a = this.root(a);
		b = this.root(b);
		if (a == b) {
			return;
		}
		if (this.size[a] > this.size[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		this.parent[a] = b;
		this.size[b] += this.size[a];
	}
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
