#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class RotateImage {
  public:
    void rotateImage(vector<vector<int>>& arr) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int m = arr.size();
        if (m == 0 || m == 1)
            return;
        int ind = 0;
        while (ind <= (m / 2)) {
            for (int j = 0; j < (m - 1 - (2 * ind)); j++) {
                int temp = arr[ind][ind + j];
                arr[ind][ind + j] = arr[m - 1 - ind - j][ind];
                arr[m - 1 - ind - j][ind] = arr[m - 1 - ind][m - 1 - ind - j];
                arr[m - 1 - ind][m - 1 - ind - j] = arr[ind + j][m - 1 - ind];
                arr[ind + j][m - 1 - ind] = temp;
            }
            ind++;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    ReadMatrix<int>().SquareMatrix(n, matrix);
    RotateImage().rotateImage(matrix);
    PrintMatrix<int>().SquareMatrix(matrix);
    return 0;
}