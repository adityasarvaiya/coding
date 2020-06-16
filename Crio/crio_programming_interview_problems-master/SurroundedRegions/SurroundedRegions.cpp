#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class SurroundedRegions {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
private:
	int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
	int m, n;
	vector<vector<bool>> visited;
	vector<vector<bool>> isX;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

public:
	void surroundedRegions(vector<vector<char>>& board) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		if (int(board.size()) == 0)
			return;
		m = board.size();
		n = board[0].size();
		visited = vector<vector<bool>>(m, vector<bool>(n, false));
		isX = vector<vector<bool>>(m, vector<bool>(n, true));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
				        board[i][j] == 'O')
					DFS(board, visited, isX, i, j);
			}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (isX[i][j])
					board[i][j] = 'X';
				else
					board[i][j] = 'O';
			}
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}

	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited,
	         vector<vector<bool>>& isX, int x, int y) {
		if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] ||
		        board[x][y] == 'X')
			return;
		visited[x][y] = true;
		isX[x][y] = false;
		for (int i = 0; i < 4; i++) {
			int xx = x + d[i][0];
			int yy = y + d[i][1];
			DFS(board, visited, isX, xx, yy);
		}
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
};

int main() {
	FastIO();
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid;
	ReadMatrix<char>().TwoDMatrix(n, m, grid);
	SurroundedRegions().surroundedRegions(grid);
	PrintMatrix<char>().TwoDMatrix(grid);
	return 0;
}
