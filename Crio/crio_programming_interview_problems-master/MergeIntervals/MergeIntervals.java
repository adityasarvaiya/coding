
import java.util.*;

class MergeIntervals {

    public int[][] mergeIntervals(int[][] intervals) {

        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Comparator<int[]> byStart = new Comparator<int[]>() {
		    @Override
		    public int compare(int[] e1, int[] e2) {
                int i = 0;
                if (e1[i] == e2[i])
                    ++i;
                return e1[i] - e2[i];
		    }
	    };

        Arrays.sort(intervals, byStart);

        if (intervals.length == 0)
            return new int[0][2];

        int n = 0;
        for (int i = 0; i < intervals.length; ++i) {
            if (intervals[i][0] <= intervals[n][1]) {
                intervals[n][1] = Math.max(intervals[n][1], intervals[i][1]);
            } else  {
                ++n;
                intervals[n][0] = intervals[i][0];
                intervals[n][1] = intervals[i][1];
            }
            if (i + 1 == intervals.length)
                ++n;
        }

        int[][] result = new int[n][2];

        for (int  i = 0; i < n; ++i) {
            result[i][0] = intervals[i][0];
            result[i][1] = intervals[i][1];
        }

        return result;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[][] nums = new int[n][2];

        for(int i = 0 ; i < n ;i++) {
            nums[i][0] = scanner.nextInt();
            nums[i][1] = scanner.nextInt();
        }

        int[][] results = new MergeIntervals().mergeIntervals(nums);

        for (int i = 0; i < results.length; ++i) {
            System.out.printf("%d %d\n", results[i][0], results[i][1]);
        }
    }
}
