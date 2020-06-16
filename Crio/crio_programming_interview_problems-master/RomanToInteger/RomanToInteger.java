import java.io.*;
import java.util.*;

public class RomanToInteger {
    // Implement your solution by completing the below function
    public int romanToInt(String s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Map<String, Integer> map = new HashMap<String, Integer>();
        map.put("I", 1);
        map.put("V", 5);
        map.put("X", 10);
        map.put("L", 50);
        map.put("C", 100);
        map.put("D", 500);
        map.put("M", 1000);

        int result = 0, previousCharValue = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            String currentChar = String.valueOf(s.charAt(i));
            int currentCharValue = map.get(currentChar);

            if (currentCharValue < previousCharValue)
                result -= currentCharValue;
            else {
                previousCharValue = currentCharValue;
                result += currentCharValue;
            }
        }
        return result;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return -1;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();

        int result = new RomanToInteger().romanToInt(line);
        System.out.print(String.valueOf(result));
    }
}
