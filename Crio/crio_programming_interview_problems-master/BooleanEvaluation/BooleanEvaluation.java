import java.util.*;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Pair {
    long waysTrue;
    long waysFalse;
    Pair(long waysTrue , long waysFalse) {
        this.waysTrue = waysTrue;
        this.waysFalse = waysFalse;
    }
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (obj instanceof Pair) {
            Pair pair = (Pair) obj;
            if (pair.waysTrue == waysTrue && pair.waysFalse == waysFalse)
                return true;
        }
        return false;
    }
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
public class BooleanEvaluation {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    Pair noOfWays[][];
    int mod = 1000000007;
    Pair findNoOfWays(int i , int j , String expression) {
        if(i == j) {
            if(expression.charAt(i) == '1') {
                return new Pair(1,0);
            } else {
                return new Pair(0,1);
            }
        }
        if(!(noOfWays[i][j].equals(new Pair(-1,-1)))) {
            return noOfWays[i][j];
        }
        Pair ret = new Pair(0,0);
        for(int k = i+1 ; k <= j ; k+=2) {
            Pair left = findNoOfWays(i , k-1 , expression);
            Pair right = findNoOfWays(k+1 , j , expression);
            if(expression.charAt(k) == '^') {
                ret.waysTrue = (ret.waysTrue%mod + ((left.waysFalse%mod) * (right.waysTrue%mod))%mod)%mod;
                ret.waysTrue %= mod;
                ret.waysTrue = (ret.waysTrue%mod + ((left.waysTrue%mod) * (right.waysFalse%mod))%mod)%mod;
                ret.waysTrue %= mod;
                ret.waysFalse = (ret.waysFalse%mod + ((right.waysTrue%mod) * (left.waysTrue%mod))%mod)%mod;
                ret.waysFalse %= mod;
                ret.waysFalse = (ret.waysFalse%mod + ((right.waysFalse%mod) * (left.waysFalse%mod))%mod)%mod;
                ret.waysFalse %= mod;
            }
            if(expression.charAt(k) == '|') {
                ret.waysTrue = (ret.waysTrue%mod + ((left.waysFalse%mod) * (right.waysTrue%mod))%mod)%mod;
                ret.waysTrue %= mod;
                ret.waysTrue = (ret.waysTrue%mod +  ((left.waysTrue%mod) * (right.waysFalse%mod))%mod)%mod;
                ret.waysTrue %= mod;
                ret.waysTrue = (ret.waysTrue%mod +  ((right.waysTrue%mod) * (left.waysTrue%mod))%mod)%mod;
                ret.waysTrue %= mod;
                ret.waysFalse =(ret.waysFalse%mod +  ((right.waysFalse%mod) * (left.waysFalse%mod))%mod)%mod;
                ret.waysFalse %= mod;
            }
            if(expression.charAt(k) == '&') {
                ret.waysFalse = (ret.waysFalse%mod + ((left.waysFalse%mod) * (right.waysTrue%mod))%mod)%mod;
                ret.waysFalse %= mod;
                ret.waysFalse = (ret.waysFalse%mod + ((left.waysTrue%mod) * (right.waysFalse%mod))%mod)%mod;
                ret.waysFalse %= mod;
                ret.waysTrue = (ret.waysTrue%mod + ((right.waysTrue%mod) * (left.waysTrue%mod))%mod)%mod;
                ret.waysTrue %= mod;
                ret.waysFalse = (ret.waysFalse%mod + ((right.waysFalse%mod) * (left.waysFalse%mod))%mod)%mod;
                ret.waysFalse %= mod;
            }
        }
        return noOfWays[i][j] = ret;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    int booleanEvaluation(String expression , int desired) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        long ways = 0;
        noOfWays = new Pair[310][310];
        for(int i = 0 ; i < 310 ; i++) {
            for(int j = 0 ;j < 310 ; j++) {
                noOfWays[i][j] = new Pair(-1, -1);
            }
        }
        if(desired == 0) {
            ways = findNoOfWays(0, expression.length()-1, expression).waysFalse;
        } else {
            ways = findNoOfWays(0, expression.length()-1, expression).waysTrue; 
        }
        return (int)(ways%mod);
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.next();
        int desired = scanner.nextInt();
        scanner.close();
        int result = new BooleanEvaluation().booleanEvaluation(expression, desired);
        System.out.println(result);
    }
}