using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _04_searching_and_sorting
{
    /*
    link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
    x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
*/

    public class _01_first_pos_and_last_pos
    {
        [Fact]
        public void first_pos_and_last_pos_SearchSortTest()
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
        private List<int> findBf(int[] arr, int len, int num)
        {
            // code here
            int start = len;
            int end = 0;
            bool noNumflag = true;
            for (int k = 0; k < len; k++)
            {
                if (arr[k] == num)
                {
                    start = Math.Min(start, k);
                    end = Math.Max(end, k);
                    noNumflag = false;
                }
            }
            // if ele is not present
            if (noNumflag)
            {
                return new List<int>() { -1, -1 };
            }
            // if ele is present
            return new List<int>() { start, end };
        }

        /*
            using binary search
            TC: O(logn)
            SC: O(1)
        */
        private List<int> findBST(int[] arr, int len, int num)
        {
            int low = 0;
            int high = len - 1;
            int first_occ = -1;
            int last_occ = -1;
            while (low <= high)
            {
                // Normal Binary Search Logic
                int mid = low + (high - low) / 2;
                if (num < arr[mid]) high = mid - 1;
                else if (num > arr[mid]) low = mid + 1;
                else
                {
                    first_occ = mid;
                    high = mid - 1;
                }
            }

            low = 0; high = len - 1;
            while (low <= high)
            {
                // Normal Binary Search Logic
                int mid = low + (high - low) / 2;
                if (num < arr[mid]) high = mid - 1;
                else if (num > arr[mid]) low = mid + 1;
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
        private List<int> findBST1(int[] arr, int len, int num)
        {
            // by default i and j have value -1 and -1.
            int i = -1;
            int j = -1;

            // searching for first occurence
            int low = 0;
            int high = len - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;

                // main logic to check first occurence
                if ((mid == 0 || arr[mid - 1] < num) && arr[mid] == num)
                {
                    i = mid;
                    break;
                }
                else if (arr[mid] < num)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            // searching for last occurence 
            low = 0; high = len - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;

                // main logic for last occurence  
                if ((mid == len - 1 || arr[mid + 1] > num) && arr[mid] == num)
                {
                    j = mid;
                    break;
                }
                else if (num < arr[mid])
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
