import java.io.*;
import java.util.*;
public class  UniqueString {
  public static int check(String s) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    HashMap <Integer , Integer> M = new HashMap<Integer , Integer> ();
    int flag = 1;
    for ( int i = 0; i < s.length(); i++) {

      if (M.containsKey(s.charAt(i) - 'a' )) {
        flag = 0;
      } else   M.put(s.charAt(i) - 'a', i);
    }
    return flag;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }
  public static void  main (String args []) {
    Scanner sc =  new  Scanner (System.in);
    int t = 1;
    while (t-- > 0) {
      String s = new String();
      s = sc.next();
      int flag = check(s);
      if (flag == 1) {
        System.out.print("Yes");
      } else System.out.print("No");
    }
    return ;
  }

}
