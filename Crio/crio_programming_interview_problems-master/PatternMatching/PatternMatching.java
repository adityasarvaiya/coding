import java.util.*;

public class PatternMatching {

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    String text , pattern;
    boolean answer;
    Map<Character, String> map;
    void isMatch(int i , int j) {

        if (i == this.text.length()) {
            if (j == this.pattern.length()) {
                this.answer = true;
            }
            return;
        }
        if (j == this.pattern.length()) {
            return;
        }
        char patternPart = this.pattern.charAt(j);
        if (this.map.containsKey(patternPart)) {
            String textPart = this.map.get(patternPart);
            int length = textPart.length();
            if (length > text.length() - i) {
                return;
            } else {
                String subsString = text.substring(i, i + length);
                if (subsString.equals(textPart)) {
                    isMatch(i + length , j + 1);
                } else {
                    return;
                }
            }
        } else {
            String value = "";
            for (int k = 1 ; i + k - 1 < this.text.length() ; k++) {
                value += this.text.charAt(i + k - 1);
                this.map.put(pattern.charAt(j), value);
                this.isMatch(i + k, j + 1);
                this.map.remove(pattern.charAt(j));
            }
        }

    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    boolean patternMatching(String text, String pattern) {

        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        this.answer = false;
        this.map = new HashMap<Character, String>();
        this.text = text;
        this.pattern = pattern;
        isMatch(0, 0);
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int p = 0 ; p < t ; p++) {
            PatternMatching result = new PatternMatching();
            String text = scanner.next();
            String pattern = scanner.next();
            if (result.patternMatching(text, pattern)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        scanner.close();
    }
}