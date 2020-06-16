import java.io.*;
import java.util.Scanner;
import java.lang.Math;
public class  OneAway {

  public static int isOneAway(String s , String t) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n = s.length();
    int m = t.length();
    int cnt = 0;
    if (Math.abs(n - m) > 1 ) return 0;
    int i = 0, j = 0;
    while (i < n && j < m) {

      if ( s.charAt(i) != t.charAt(j)) {
        cnt++;
        if ( cnt > 1) {
          return 0;
        }
        if ( n == m) {
          i++ ;
          j++;
        }
        if (n < m)
          j++;

        if ( n > m)
          i++;

      } else {
        i++;
        j++;
      }
    }
    if ( cnt > 1) return 0;
    else return 1;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

  }
  public static void  main (String args []) {

    Scanner sc =  new  Scanner (System.in);
    int t = 1;
    t = sc.nextInt();
    sc.nextLine();
    while (t-- > 0) {
      String s = new String();
      String s1 = new String();
      s = sc.next();
      s1 = sc.next();
      int flag = isOneAway(s, s1);

      if (flag == 1) {
        System.out.println("True");
      } else {
        System.out.println("False");
      }
    }
  }

}