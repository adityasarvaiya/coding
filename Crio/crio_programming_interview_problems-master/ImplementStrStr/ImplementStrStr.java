import java.io.*;
import java.util.*;

public class ImplementStrStr {
	// Implement your solution by completing the below function
	public int strStr(String haystack, String needle) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		if (needle.length() == 0)
			return 0;

		if (haystack.length() < needle.length())
			return -1;

		if (haystack.length() == needle.length())
			return haystack.equals(needle) ? 0 : -1;

		for (int i = 0; i < haystack.length(); i++) {
			int hIndex = i;
			int nIndex = 0;
			while (hIndex < haystack.length() && nIndex < needle.length()
					&& haystack.charAt(hIndex) == needle.charAt(nIndex)) {
				hIndex++;
				nIndex++;
			}
			if (nIndex == needle.length()) {
				return i;
			}
		}
		return -1;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

		// CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
		//return -1;
		// CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String haystack = in.readLine();
		String needle = in.readLine();
		int result = new ImplementStrStr().strStr(haystack, needle);
		System.out.print(result);
	}
}