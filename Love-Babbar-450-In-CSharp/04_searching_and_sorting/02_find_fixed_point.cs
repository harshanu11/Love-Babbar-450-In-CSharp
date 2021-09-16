using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _04_searching_and_sorting
{
    public class _02_find_fixed_point
    {
        [Fact]
        public void first_pos_and_last_pos_SearchSortTest()
        {
            var arr = new int[] { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
            var ansLst = valueEqualToIndex(arr, arr.Length);
            var ans = binarySearch(arr, 0, arr.Length);
        }
        /*
         *Fixed Point (Value equal to index)
            link: https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1#

            sol(this is for single point): https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

            here we have to find all the point fulfilling the condition
        */


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            linear search
            TC: O(N)
            SC: O(N)
        */
        private List<int> valueEqualToIndex(int[] arr, int n)
        {
            // code here
            List<int> ans = new List<int>();
            for (int i = 1; i < n; i++)
            {
                if (arr[i] == i)
                {
                    ans.Add(i);
                }
            }
            return ans;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            binary search (use only if its said to find any single fixed point)

            TC: O(logn)
            SC: O(1)
        */
        private int binarySearch(int[] arr, int low, int high)
        {
            if (high >= low)
            {
                // low + (high - low)/2;
                int mid = (low + high) / 2;

                if (mid == arr[mid])
                    return mid;
                if (mid > arr[mid])
                    return binarySearch(arr, (mid + 1), high);
                else
                    return binarySearch(arr, low, (mid - 1));
            }

            /* Return -1 if there is
            no Fixed Point */
            return -1;
        }

    }
}
