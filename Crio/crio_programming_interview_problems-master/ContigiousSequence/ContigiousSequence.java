import java.io.*;
import java.util.Scanner;
public class  ContigiousSequence {
	public static  long contigiousSequence(int arr[] , int n) {

		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		long mx = -1000000000, cur_max = 0;

		for ( int i = 0; i < n; i++) {
			cur_max += arr[i];

			if (mx < cur_max) mx = cur_max;

			if ( cur_max < 0) cur_max = 0;
		}
		return mx;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

	}
	public static void  main (String args []) {

		Scanner sc =  new  Scanner (System.in);

		int n = sc.nextInt();
		int arr [] = new int[n + 5];
		for ( int i = 0 ; i < n; i++)
			arr[i] = sc.nextInt();

		long max = contigiousSequence(arr, n);
		System.out.println(max);

	}
}

