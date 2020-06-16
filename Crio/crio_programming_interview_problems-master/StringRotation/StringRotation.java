import java.io.*;
import java.util.Scanner;
public class  StringRotation {
  public static int compare(StringBuilder s , StringBuilder t) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int flag = 0;
    for ( int i = 0; i < s.length() + 1; i++) {
      if (s.compareTo(t) == 0) {
        flag = 1 ; return 1;
      }

      s.append(s.charAt(0));
      s.deleteCharAt(0);
    }
    return flag;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }
  public static void  main (String args []) {

    Scanner sc =  new  Scanner (System.in);
    int t = 1;
    while (t-- > 0) {
      String s = new String() ;
      s = sc.next();
      String s1 = new String();
      s1 = sc.next();
      StringBuilder r = new StringBuilder(s);
      StringBuilder r1 = new StringBuilder(s1);

      if (s.length() != r.length()) {
        System.out.print("No");
      } else {
        int flag = compare(r, r1);

        if ( flag == 1) {
          System.out.print("Yes");
        } else {
          System.out.print("No");
        }
      }
    }

    return ;
  }

}
