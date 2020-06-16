import java.io.*;
import java.util.*;

class FruitIntoBaskets {
    
    // Complete the function implementation below
    public int totalFruit(int[] trees) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Map<Integer, Integer> count = new HashMap<>();
        int i = 0, j;
        for (j = 0; j < trees.length; ++j) {
            count.put(trees[j], count.getOrDefault(trees[j], 0) + 1);
            if (count.size() > 2) {
                count.put(trees[i], count.get(trees[i]) - 1);
                count.remove(trees[i++], 0);
            }
        }
        return j - i;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int trees[] = new int[n];
        for(int i = 0 ; i < n; i++) {
            trees[i] = scanner.nextInt();
        }
        int result = new FruitIntoBaskets().totalFruit(trees);
        System.out.println(result);
	scanner.close();
    }
}
