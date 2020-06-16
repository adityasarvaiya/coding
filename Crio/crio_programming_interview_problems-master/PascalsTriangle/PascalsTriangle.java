import java.io.*;
import java.util.*;

public class PascalsTriangle {
    public List<List<Integer>> pascalsTriangle(int numRows) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();

        if (numRows == 0) {
            return triangle;
        }

        triangle.add(new ArrayList<>());
        triangle.get(0).add(1);

        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            List<Integer> row = new ArrayList<>();
            List<Integer> prevRow = triangle.get(rowNum - 1);
            row.add(1);

            for (int j = 1; j < rowNum; j++)
                row.add(prevRow.get(j - 1) + prevRow.get(j));

            row.add(1);
            triangle.add(row);
        }

        return triangle;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int numRows = scanner.nextInt();
        scanner.close();

        List<List<Integer>> result = new PascalsTriangle().pascalsTriangle(numRows);
        for (List<Integer> row : result) {
            for (int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
