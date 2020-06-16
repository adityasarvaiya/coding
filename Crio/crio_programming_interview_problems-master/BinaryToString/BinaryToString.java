import java.util.*;

public class BinaryToString {
    String convertToBinary(double number) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        String answer = new String("0.");
        while(number > 0) {
            double temp = number*2;
            int integerPart = (int)temp;
            answer += Integer.toString(integerPart);
            number = number*2 - integerPart;
            if(answer.length() == 35) {
                answer = "ERROR";
                return answer;
            }
        }
        return answer;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double number = scanner.nextDouble();
        String result = new BinaryToString().convertToBinary(number);
        System.out.println(result);
        scanner.close();
    }
}