#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class ValidSudoku {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        // check for each row
        for (int r = 0; r < int(board.size()); r++) {
            vector<int> mpRow(10, 0);
            for (int elem = 0; elem < int(board[0].size()); elem++) {
                if ('1' <= board[r][elem] && board[r][elem] <= '9')
                    mpRow[board[r][elem] - '0']++;
            }

            for (int i = 1; i < 10; i++) {
                if (mpRow[i] > 1)
                    return false;
            }
        }

        // check for each col
        for (int c = 0; c < int(board[0].size()); c++) {
            vector<int> mpCol(10, 0);
            for (int elem = 0; elem < int(board.size()); elem++) {
                if ('1' <= board[elem][c] && board[elem][c] <= '9')
                    mpCol[board[elem][c] - '0']++;
            }

            for (int i = 1; i < 10; i++) {
                if (mpCol[i] > 1)
                    return false;
            }
        }

        // check for 3*3 cells
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<int> mpBox(10, 0);
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if ('1' <= board[k][l] && board[k][l] <= '9')
                            mpBox[board[k][l] - '0']++;
                    }
                }

                for (int i = 1; i < 10; i++) {
                    if (mpBox[i] > 1)
                        return false;
                }
            }
        }
        return true;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
    }
};

int main() {
    FastIO();
    vector<vector<char>> grid;
    ReadMatrix<char>().SquareMatrix(9, grid);
    bool result = ValidSudoku().isValidSudoku(grid);
    cout << boolalpha << result;
    return 0;
}
