#include "FastIO.hpp"
#include "PrintMatrix.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class SpiralMatrix {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        int szy = matrix.size();
        if (szy == 0)
            return res;
        int szx = matrix[0].size();
        if (szx == 0)
            return res;
        vector<bool> bool_vec(szx, false);
        vector<vector<bool>> visit(szy, bool_vec);
        int vx = 1;
        int vy = 0;
        int tmp;
        int cur_x = 0;
        int cur_y = 0;
        while (true) {
            res.push_back(matrix[cur_y][cur_x]);
            visit[cur_y][cur_x] = true;
            if (cur_x + vx == -1 || cur_x + vx == szx || cur_y + vy == -1 ||
                cur_y + vy == szy || visit[cur_y + vy][cur_x + vx]) {
                tmp = vx;
                vx = -vy;
                vy = tmp;
            }
            cur_x += vx;
            cur_y += vy;
            if (cur_y == -1 || cur_y == szy || cur_x == -1 || cur_x == szx ||
                visit[cur_y][cur_x])
                break;
        }
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        return res;
    }
};

int main() {
    FastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    ReadMatrix<int>().TwoDMatrix(n, m, matrix);
    vector<int> result = SpiralMatrix().spiralOrder(matrix);
    PrintMatrix<int>().OneDMatrix(result, " ");
    return 0;
}
