import java.util.*;

class ConnectRopes{

	private static long connectRopes(Vector<Long> arr)
	{
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		int n=arr.size();
		long cost =0 ;
		PriorityQueue<Long> pQueue = new PriorityQueue<Long>();
		for(int i =0 ;i<n;i++)
		{
			pQueue.add((long)arr.get(i));
		}
		while (pQueue.size() > 1)
    	{
        	long max1 = pQueue.poll();
        	long max2 = pQueue.poll();
       	 	pQueue.add(max1 + max2);
        	cost += max1 + max2;   
    	}
    	return cost;
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Vector<Long> arr = new Vector<Long>();
		for(int i=0;i<n;i++)
			arr.add(sc.nextLong());
		System.out.println(connectRopes(arr));
	}
}
