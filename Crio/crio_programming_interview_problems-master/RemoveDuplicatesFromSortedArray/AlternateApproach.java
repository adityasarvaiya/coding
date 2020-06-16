import java.io.*;
import java.util.*;

public class AlternateApproach {
    // Implement your solution by completing the below function
    public int removeDuplicates(int[] nums) {
        Set<Integer> unique_elements = new TreeSet<Integer>();
        for (int a : nums) {
            unique_elements.add(a);
        }
        return unique_elements.size();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] numbers = new int[scanner.nextInt()];
        for (int i = 0; i < numbers.length; i++)
            numbers[i] = scanner.nextInt();
        scanner.close();

        int result = new AlternateApproach().removeDuplicates(numbers);
        System.out.print(Integer.toString(result));
    }
}
