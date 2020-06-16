import java.util.*;

class Solution{ 
	public ArrayList<Integer> countOfSmallerNumberAfterSelf(int[] nums) 
	{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS 
		int len = nums.length; 
		Pair [] ar = new Pair[len]; 

		for (int i = 0; i < len; i++)
		{ 
			ar[i] = new Pair(nums[i], i); 
		} 
		int[] count = new int[len]; 
		mergeSort(ar, 0, len - 1, count); 
		ArrayList<Integer> res = new ArrayList<>(); 

		for (int i : count) { 
			res.add(i); 
		} 
		return res;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS 
	}
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS  
	private void mergeSort(Pair[] ar, int low, int high, int[] count) 
	{ 
		if (low >= high)
		{ 
			return; 
		} 
		int mid = low + (high - low) / 2; 
		mergeSort(ar, low, mid, count); 
		mergeSort(ar, mid + 1, high, count); 
		merge(ar, low, mid, mid + 1, high, count); 
	} 
	private void merge(Pair[] ar, int low, int lowEnd, int high, int highEnd, int[] count) 
	{ 
		int m = highEnd - low + 1; 
		Pair[] sorted = new Pair[m]; 
		int rightCounter = 0; 
		int lowPtr = low, highPtr = high; 
		int index = 0; 
		while (lowPtr <= lowEnd && highPtr <= highEnd)
		{ 
			if (ar[lowPtr].val > ar[highPtr].val)
			{ 
				rightCounter++; 
				sorted[index++] = ar[highPtr++]; 
			} 
			else 
			{ 
				count[ar[lowPtr].index] += rightCounter; 
				sorted[index++] = ar[lowPtr++]; 
			} 
		} 
		while (lowPtr <= lowEnd)
		{ 
			count[ar[lowPtr].index] += rightCounter; 
			sorted[index++] = ar[lowPtr++]; 
		} 
		while (highPtr <= highEnd)
		{ 
			sorted[index++] = ar[highPtr++]; 
		} 
		System.arraycopy(sorted, 0, ar, low, m); 
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

class Pair { 
	int val; 
	int index; 
	public Pair(int val, int index) 
	{ 
		this.val = val; 
		this.index = index; 
	} 
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

