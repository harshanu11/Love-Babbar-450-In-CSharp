using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _04_searching_and_sorting
{
    public class _03_search_in_rotated_array
    {
		/*
			link: https://leetcode.com/problems/search-in-rotated-sorted-array/
		*/

		[Fact]
		public void reverse_arrayTest()
		{
			var ans = BinarySearch1(new int[] { 4, 5, 6, 7, 0, 1, 2 },0);
			ans = BinarySearch2(new int[] { 4, 5, 6, 7, 0, 1, 2 },7, 0);
		}
		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			simple binary search
			TC: O(logn)
		*/
		public int BinarySearch1(int[] nums, int target)
        {
            var low = 0;
            var high = nums.Length - 1;

            while (low <= high)
            {
                var mid = (low + high) / 2;

                if (nums[mid] == target)
                    return mid;

                if (nums[mid] < nums[high])
                {
                    if (target > nums[mid] && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                else
                {
                    if (target >= nums[low] && target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }

            return -1;
        }

		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			using rotation variable in binary search
			TC: O(logn)
		*/
		private int BinarySearch2(int[] A, int n, int target)
		{
			int lo = 0;
			int hi = n - 1;
			// find the index of the smallest value using binary search.
			// Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
			// Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
			while (lo < hi)
			{
				int mid = (lo + hi) / 2;
				if (A[mid] > A[hi])
				{
					lo = mid + 1;
				}
				else
				{
					hi = mid;
				}
			}
			// lo==hi is the index of the smallest value and also the number of places rotated.
			int rot = lo;
			lo = 0;
			hi = n - 1;
			// The usual binary search and accounting for rotation.
			while (lo <= hi)
			{
				int mid = (lo + hi) / 2;
				int realmid = (mid + rot) % n;
				if (A[realmid] == target)
				{
					return realmid;
				}
				if (A[realmid] < target)
				{
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}
			return -1;
		}

	}
}
