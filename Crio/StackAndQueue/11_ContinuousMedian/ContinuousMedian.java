import java.util.*;
import java.io.*;

class ContinuousMedian {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	// class Cmp implements Comparator<Integer> {
	// 	public int compare(Integer a , Interger b) {
	// 		return a - b;
	// 	}
	// }
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	
	public static ArrayList<Integer> continuousMedian(ArrayList<Integer> nums) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int n = nums.size();
		PriorityQueue <Integer> maxHeap = new PriorityQueue<Integer> ();
		PriorityQueue<Integer> minHeap = new PriorityQueue<Integer> (Collections.reverseOrder());
		minHeap.add(nums.get(0));
		double median = nums.get(0);

		ArrayList<Integer> answer = new ArrayList<Integer>();
		answer.add((int)median);


		for ( int i = 1; i < n; i++) {
			int cur = nums.get(i);
			if ( minHeap.size() > maxHeap.size()) {
				if (cur < median) {
					maxHeap.add(minHeap.remove());
					minHeap.add(cur);
				} else {
					maxHeap.add(cur);
				}
				median = (double)(minHeap.peek() + maxHeap.peek()) / 2;
			} else if ( minHeap.size() == maxHeap.size()) {
				if ( cur < median ) {
					minHeap.add(cur);
					median = minHeap.peek();
				} else {
					maxHeap.add(cur);
					median = maxHeap.peek();
				}
			} else {
				if ( cur > median) {
					minHeap.add(maxHeap.remove());
					maxHeap.add(cur);
				} else {
					minHeap.add(cur);
				}
				median = (double)(minHeap.peek() + maxHeap.peek()) / 2;
			}

			answer.add((int)median);
		}
		return answer;
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> A = new ArrayList<Integer>();
		for ( int i = 0; i < n; i++) {
			int x = sc.nextInt();
			A.add(x);
		}

		ArrayList<Integer> answer = continuousMedian(A);
		for ( int i = 0; i < answer.size(); i++) {
			System.out.println(answer.get(i) + " ");
		}

	}
}
