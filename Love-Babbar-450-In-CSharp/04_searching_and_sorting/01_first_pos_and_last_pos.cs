using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace Love_Babbar_450_In_CSharp._04_searching_and_sorting
{
	/*
    link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
*/

	public class _01_first_pos_and_last_pos
    {
		[Fact]
		public void reverse_arrayTest()
		{
			int[] arr = { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
			var ans = findBf(arr, arr.Length - 1, 5);//2,5
			ans = findBST(arr, arr.Length - 1, 5);//2,5
			ans = findBST1(arr, arr.Length - 1, 5);//2,5
		}

		/*
			simple iteration
			TC: O(N)
		*/
		private List<int> findBf(int[] arr, int n, int x)
		{
			// code here
			int i = n;
			int j = 0;
			bool flag = true;
			for (int k = 0; k < n; k++)
			{
				if (arr[k] == x)
				{
					i = Math.Min(i, k);
					j = Math.Max(j, k);
					flag = false;
				}
			}

			// if ele is not present
			if (flag)
			{
				return new List<int>() { -1, -1 };
			}

			// if ele is present
			return new List<int>() { i, j };
		}

		/*
using binary search
TC: O(logn)
SC: O(1)
*/
		private List<int> findBST(int[] arr, int n, int x)
		{
			int low = 0;
			int high = n - 1;
			int first_occ = -1;
			int last_occ = -1;
			while (low <= high)
			{
				// Normal Binary Search Logic
				int mid = (low + high) / 2;
				if (arr[mid] > x)
				{
					high = mid - 1;
				}
				else if (arr[mid] < x)
				{
					low = mid + 1;
				}

				// If arr[mid] is same as x, we
				// update res and move to the left
				// half.
				else
				{
					first_occ = mid;
					high = mid - 1;
				}
			}

			low = 0; high = n - 1;
			while (low <= high)
			{
				// Normal Binary Search Logic
				int mid = (low + high) / 2;
				if (arr[mid] > x)
				{
					high = mid - 1;
				}
				else if (arr[mid] < x)
				{
					low = mid + 1;
				}

				// If arr[mid] is same as x, we
				// update res and move to the right
				// half.
				else
				{
					last_occ = mid;
					low = mid + 1;
				}
			}

			return new List<int>() { first_occ, last_occ };
		}
		/*
    using binary search
    TC: O(logn)
    SC: O(1)
*/
		private List<int> findBST1(int[] arr, int n, int x)
		{
			// by default i and j have value -1 and -1.
			int i = -1;
			int j = -1;

			// searching for first occurence
			int low = 0;
			int high = n - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;

				// main logic to check first occurence
				if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x)
				{
					i = mid;
					break;
				}
				else if (arr[mid] < x)
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}

			// searching for last occurence 
			low = 0; high = n - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;

				// main logic for last occurence  
				if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x)
				{
					j = mid;
					break;
				}
				else if (x < arr[mid])
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}


			return new List<int>() { i, j };
		}

	}
}
