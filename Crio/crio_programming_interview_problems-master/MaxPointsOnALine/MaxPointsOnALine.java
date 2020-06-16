import java.io.*;
import java.util.*;

class MaxPointsOnALine {
    public int maxPoints(int[][] points) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int maxCount = 0;

        for(int i = 0 ; i < points.length ; ++i) {
            int x = points[i][0];
            int y = points[i][1];

            int currentMax = 0;
            int collisions = 0;
            HashMap<Fraction , Integer> slopeCount = new HashMap<Fraction , Integer>();
            for(int j = 0 ; j < points.length ; ++j) {
                Fraction slope = new Fraction(points[j][1] - y , points[j][0] - x);
                if(points[j][0] == x && points[j][1] == y) {
                    collisions++;
                    continue;
                }
                if(!slopeCount.containsKey(slope))
                    slopeCount.put(slope , 0);
                slopeCount.put(slope , slopeCount.get(slope) + 1);

                currentMax = Math.max(currentMax , slopeCount.get(slope));
            }

            maxCount = Math.max(currentMax + collisions , maxCount);
        }
        return maxCount;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] points = new int[n][2];

        for(int i = 0 ; i < n ; ++i) {
            points[i][0] = scanner.nextInt();
            points[i][1] = scanner.nextInt();
        }
        scanner.close();

        int result = new MaxPointsOnALine().maxPoints(points);
        System.out.println(result);
    }
}
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Fraction {

    public final int X;
    public final int Y;
    public static int gcd(int a , int b) {
        int temp = 0;
        while(b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public Fraction(final int X, final int Y) {
        int x = X;
        int y = Y;
        int g = gcd(X , Y);
        if(g != 0)
            x /= g;
        if(g != 0)
            y /= g;
        this.X = x;
        this.Y = y;
    }

    public boolean equals (final Object O) {
        if (!(O instanceof Fraction)) return false;
        if (((Fraction) O).X != X) return false;
        if (((Fraction) O).Y != Y) return false;
        return true;
    }

    public int hashCode() {
        return (X << 30) + Y;
    }
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
