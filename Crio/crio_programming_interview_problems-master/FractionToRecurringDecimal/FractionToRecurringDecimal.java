import java.util.*;

class FractionToRecurringDecimal {
    public String fractionToRecurringDecimal(int numerator, int denominator) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Boolean isNegative = false;
        if(numerator > 0 && denominator < 0) {
            isNegative = true;
        } else if(numerator < 0 && denominator > 0) {
            isNegative = true;
        }
        long num = numerator;
        num = Math.abs(num);
        
        long den = denominator;
        den = Math.abs(den);
        
        long beforeDecimal = num / den;
        String res = String.valueOf(beforeDecimal);
        long rem = num % den;
        HashMap<Long , Integer> remainders = new HashMap<Long,Integer>();
        ArrayList<Long> afterDecimal = new ArrayList<Long>();
        
        while(rem > 0 && !remainders.containsKey(rem)) {
            remainders.put(rem , afterDecimal.size());
            
            rem = rem * 10;
            afterDecimal.add(rem / den);
            rem %= den;
        }        
        if(afterDecimal.size() > 0) {
            res += ".";
            if(rem == 0) {
                for(int i = 0 ; i < afterDecimal.size() ; ++i) {
                    res += String.valueOf(afterDecimal.get(i));
                }
            } else {
                for(int i = 0 ; i < remainders.get(rem) ; ++i) {
                    res += String.valueOf(afterDecimal.get(i));
                }
                res += "(";
                
                for(int i = remainders.get(rem); i <  afterDecimal.size(); ++i) {
                    res += String.valueOf(afterDecimal.get(i));
                }
                res += ")";
            }
        }
        if(isNegative) {
            res = "-" + res;
        }
        return res; 
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numerator = in.nextInt();
        int denominator = in.nextInt();

        String result = new FractionToRecurringDecimal().fractionToRecurringDecimal(numerator , denominator);
        System.out.println(result);
    }
}