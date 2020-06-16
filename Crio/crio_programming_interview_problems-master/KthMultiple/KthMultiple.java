import java.util.*;

class KthMultiple {
	public static Long findKthMultiple(int k) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		PriorityQueue<Long> pq = new PriorityQueue<Long>();
		HashMap<Long, Long> map = new HashMap<>();
		map.put((long)1, (long)1);
		pq.add((long)1);
		Long i = (long)1, top;
		while (i < k) {
			top = pq.poll();
			if (map.get(top * ((long)3)) == null) {
				map.put(top * ((long)3), (long)1);
				pq.add(top * ((long)3));
			}
			if (map.get(top * ((long)5)) == null) {
				map.put(top * ((long)5), (long)1);
				pq.add(top * ((long)5));
			}
			if (map.get(top * ((long)7)) == null) {
				map.put(top * ((long)7), (long)1);
				pq.add(top * ((long)7));
			}
			i++;
		}
		return pq.peek();
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		System.out.println(findKthMultiple(k));
	}
}
