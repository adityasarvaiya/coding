import java.io.*;
import java.util.Scanner;

public class  StringCompression {
  public static String compress(String s) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    String ans = new String();
    int n = s.length();
    for ( int i = 0; i < s.length() ; ) {
      int cnt = 0;

      int j = i;
      while (j < n && s.charAt(j) == s.charAt(i)) {
        j++; cnt++;
      }
      ans += s.charAt(i);
      ans += Integer.toString(cnt);
      i = j;
    }
    if (ans.length() < s.length())
      return ans;
    else 
      return s;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
  }
  public static void  main (String args []) {
    Scanner sc =  new  Scanner (System.in);
    String s = new String();
    s = sc.next();
    
    int n = s.length();
    String ans = compress(s);
    System.out.print(ans);    
  }
}