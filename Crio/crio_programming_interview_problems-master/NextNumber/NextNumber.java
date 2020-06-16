import java.util.*;

public class NextNumber {
    String nextGreater(long number) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        for(int i = 0 ; i < 62 ; i++) {
            if(((number >> i) & 1) == 1) {
                if(((number >> (i+1)) & 1) == 0) {
                    number ^= (1L << i);
                    number ^= (1L << (i+1));
                    if(number%2 == 0) {
                        for(int j = 0 ; j < i ; j++) {
                            if(((number >> (j+1)) & 1) == 0) {
                                number &= ~(1L << j);
                            } else {
                                number |= (1L << j);
                            }
                        }
                    }
                    return Long.toString(number);
                }
            }
        }
        return "No Number";
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    String nextSmaller(long number) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int cnt = 0;
         for(int i = 0 ; i < 62 ; i++) {
            if(((number >> i) & 1) == 1) {
                cnt++;
            }
            if(((number >> i) & 1) == 0) {
                if(((number >> (i+1)) & 1) == 1) {
                    number ^= (1L << i);
                    number ^= (1L << (i+1));
                    for(int j = i-1 ; j >= 0 ; j--) {
                        if(cnt > 0) {
                            number |= (1L << j);
                            cnt--;
                        } else {
                            number &= ~(1L << j);
                        }
                    }
                    return Long.toString(number);
                }
            }
        }
        return "No Number";
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long number = scanner.nextLong();
        String greater = new NextNumber().nextGreater(number);
        String smaller = new NextNumber().nextSmaller(number);
        System.out.println(greater);
        System.out.println(smaller);
        scanner.close();
    }
}