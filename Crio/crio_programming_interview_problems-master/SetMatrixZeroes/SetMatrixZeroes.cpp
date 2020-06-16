#include <bits/stdc++.h>
using namespace std;

class SetMatrixZeroes {
  public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    bool is_zero_in_first_row = false;
    bool is_zero_in_first_column = false;

    void update_is_zero_in_first_row(vector<vector<int>>& matrix, int columns) {
        for (int i = 0; i < columns; ++i) {
            if (matrix[0][i] == 0) {
                is_zero_in_first_row = true;
                break;
            }
        }
    }

    void update_is_zero_in_first_column(vector<vector<int>>& matrix, int rows) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                is_zero_in_first_column = true;
                break;
            }
        }
    }

    void make_first_zero(vector<vector<int>>& matrix, int rows, int columns) {
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
    }

    void row_zero(vector<vector<int>>& matrix, int rows, int columns) {
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < columns; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void column_zero(vector<vector<int>>& matrix, int rows, int columns) {
        for (int j = 1; j < columns; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    void setMatrixZeroes(vector<vector<int>>& matrix) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int rows, columns;
        rows = matrix.size();
        columns = matrix[0].size();
        update_is_zero_in_first_column(matrix, rows);
        update_is_zero_in_first_row(matrix, columns);
        if (int(matrix.size()) > 0 && int(matrix[0].size()) > 0) {
            make_first_zero(matrix, rows, columns);
            row_zero(matrix, rows, columns);
            column_zero(matrix, rows, columns);
        }
        if (is_zero_in_first_column) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (is_zero_in_first_row) {
            for (int i = 0; i < columns; ++i) {
                matrix[0][i] = 0;
            }
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
        cout<<"\n";
    }
    SetMatrixZeroes().setMatrixZeroes(grid);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
