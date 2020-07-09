import java.util.*;

class ConnectRopes{

	private static long connectRopes(Vector<Long> arr)
	{
		long result = 0;
		PriorityQueue<Long> heap = new PriorityQueue<Long>();
		for (int i =0;i<arr.size();i++)
		{
			heap.add(arr.get(i));
		} 
		while(heap.size()>=2)
		{
			long first = heap.poll();
			long second = heap.poll();
			long sum = first+second;
			heap.add(sum);
			result = result+sum;
		}
		
		return result;
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
