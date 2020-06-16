import java.util.*;

public class ModuloUsingRecursion {
    int moduloUsingRecursion(int dividend , int divisor) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if(divisor == 0) {
            return -1;
        }
        if(dividend < divisor) {
            return dividend;
        }
        return moduloUsingRecursion(dividend - divisor, divisor);
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dividend = scanner.nextInt();
        int divisor = scanner.nextInt();
        int result = new ModuloUsingRecursion().moduloUsingRecursion(dividend , divisor);
        System.out.println(result);
    }
}
