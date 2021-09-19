using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _18_all_pair_whose_sum_is_k
    {
		/*
    link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

    https://www.geeksforgeeks.org/count-pairs-with-given-sum/

		Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
		Example 1:
		
		Input:
		N = 4, K = 6
		arr[] = {1, 5, 7, 1}
		Output: 2
		Explanation: 
		arr[0] + arr[1] = 1 + 5 = 6 
		and arr[1] + arr[3] = 5 + 1 = 6.
*/


		// ----------------------------------------------------------------------------------------------------------------------- //
		// using hashing (aka unordered_map)
		private int getPairsCount(int[] arr, int n, int sum)
		{
			Dictionary<int, int> m = new Dictionary<int, int>();

			// Store counts of all elements in map m
			for (int i = 0; i < n; i++)
			{
				m[arr[i]]++;
			}

			int twice_count = 0;

			// iterate through each element and increment the
			// count (Notice that every pair is counted twice)
			for (int i = 0; i < n; i++)
			{
				twice_count += m[sum - arr[i]];

				// if (arr[i], arr[i]) pair satisfies the condition,
				// then we need to ensure that the count is
				// decreased by one such that the (arr[i], arr[i])
				// pair is not considered
				if (sum - arr[i] == arr[i])
				{
					twice_count--;
				}
			}

			// return the half of twice_count
			return twice_count / 2;
		}



		// ----------------------------------------------------------------------------------------------------------------------- //
		// naive solution (TLE)
		// TC: O(n^2)
		private int getPairsCount1(int[] arr, int n, int sum)
		{
			int count = 0; // Initialize result

			// Consider all possible pairs and check their sums
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (arr[i] + arr[j] == sum)
					{
						count++;
					}
				}
			}

			return count;
		}

		[Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

    https://www.geeksforgeeks.org/count-pairs-with-given-sum/
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//// using hashing (aka unordered_map)
//int getPairsCount(int arr[], int n, int sum)
//{
//	unordered_map<int, int> m;

//	// Store counts of all elements in map m
//	for (int i = 0; i < n; i++)
//		m[arr[i]]++;

//	int twice_count = 0;

//	// iterate through each element and increment the
//	// count (Notice that every pair is counted twice)
//	for (int i = 0; i < n; i++)
//	{
//		twice_count += m[sum - arr[i]];

//		// if (arr[i], arr[i]) pair satisfies the condition,
//		// then we need to ensure that the count is
//		// decreased by one such that the (arr[i], arr[i])
//		// pair is not considered
//		if (sum - arr[i] == arr[i])
//			twice_count--;
//	}

//	// return the half of twice_count
//	return twice_count / 2;
//}



//// ----------------------------------------------------------------------------------------------------------------------- //
//// naive solution (TLE)
//// TC: O(n^2)
//int getPairsCount(int arr[], int n, int sum)
//{
//	int count = 0; // Initialize result

//	// Consider all possible pairs and check their sums
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; j++)
//			if (arr[i] + arr[j] == sum)
//				count++;

//	return count;
//}