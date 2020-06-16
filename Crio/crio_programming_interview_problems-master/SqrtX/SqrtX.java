import java.io.*;
import java.util.*;

public class SqrtX {
    // Implement your solution by completing the below function
    public int mySqrt(int x) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (x < 2)
            return x;

        int left = (int) Math.pow(Math.E, 0.5 * Math.log(x));
        int right = left + 1;
        return (long) right * right > x ? left : right;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return -1;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        scanner.close();

        int sqrt = new SqrtX().mySqrt(num);
        System.out.println(Integer.toString(sqrt));
    }
}