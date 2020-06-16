import java.io.*;
import java.util.*;

class SpiralMatrix  {
  // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
  // complete the below function implementation

  public List<Integer> spiralOrder(int[][] matrix) {
    List<Integer> lst = new ArrayList<Integer>();
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    int n = matrix.length;
    if (n == 0) {
      return lst;
    }
    int m = matrix[0].length;

    int rStart = 0;
    int cStart = 0;
    int rEnd = n - 1;
    int cEnd = m - 1;

    do {

      //hor - >forward
      for (int i = cStart; i <= cEnd; ++i) {
        lst.add(matrix[rStart][i]);
      }
      // ver -> down
      for (int j = rStart + 1; (j <= rEnd - 1); ++j) {
        lst.add(matrix[j][cEnd]);
      }

      // hor - back
      for (int i = cEnd; (i >= cStart); --i) {
        lst.add(matrix[rEnd][i]);
      }

      // ver - up
      for (int j = rEnd-1; (j >= rStart + 1); --j) {
        lst.add(matrix[j][cStart]);
      }

      rStart += 1;
      cStart += 1;
      rEnd -= 1;
      cEnd -= 1;

    }while (rStart <= rEnd && cStart <= cEnd);

    return lst.subList(0, n * m);
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
    // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
    // return lst;
    // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
  }

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[][] matrix = new int[n][m];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        matrix[i][j] = scanner.nextInt();
      }
    }
    scanner.close();
    List<Integer> result = new SpiralMatrix().spiralOrder(matrix);

    for (int i = 0; i < result.size(); ++i) {
      System.out.printf("%d ", result.get(i));
    }
  }
}

