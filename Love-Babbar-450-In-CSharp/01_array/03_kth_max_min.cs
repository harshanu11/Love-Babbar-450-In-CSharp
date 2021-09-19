using _11_heap;
using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _03_kth_max_min
    {
        /*
            link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
            sol: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
            or
            refer heap/5th_kth....cpp
            
        arr[] = 7 10 4 3 20 15
        K = 3
            
        */

        [Fact]
        public void kth_max_miTest()
        {
            NodeHeap o = new NodeHeap();
            int[] arr = { 12, 3, 5, 7, 19 };
            int n = arr.Length, k = 2;
            o.sortDesc(arr);//  ans 7

            int[] arr1 = { 12, 3, 5, 7, 4, 19, 26 };
            k = 3;
            Debug.Write("K'th smallest element is " + kthSmallestUsingQuickSort(arr, 0, arr.Length - 1, k));
        }


        /*
            link: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
            quick-sort:
            The key process in quickSort is partition().
            Target of partitions is, given an array and an element x of array as pivot,
            put x at its correct position in sorted array and put all smaller elements
            (smaller than x) before x, and put all greater elements (greater than x)
            after x. All this should be done in linear time.

            more about quick sort: https://www.geeksforgeeks.org/quick-sort/
        */
        // Standard partition process of QuickSort.
        // It considers the last element as pivot
        // and moves all smaller element to left of
        // it and greater elements to right
        public static int partition(int[] arr, int l, int r)
        {
            int x = arr[r], i = l;
            int temp = 0;
            for (int j = l; j <= r - 1; j++)
            {

                if (arr[j] <= x)
                {
                    // Swapping arr[i] and arr[j]
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    i++;
                }
            }

            // Swapping arr[i] and arr[r]
            temp = arr[i];
            arr[i] = arr[r];
            arr[r] = temp;

            return i;
        }

        // This function returns k'th smallest
        // element in arr[l..r] using QuickSort
        // based method. ASSUMPTION: ALL ELEMENTS
        // IN ARR[] ARE DISTINCT
        public static int kthSmallestUsingQuickSort(int[] arr, int l, int r, int k)
        {
            // If k is smaller than number
            // of elements in array
            if (k > 0 && k <= r - l + 1)
            {
                // Partition the array around last
                // element and get position of pivot
                // element in sorted array
                int pos = partition(arr, l, r);

                // If position is same as k
                if (pos - l == k - 1)
                    return arr[pos];

                // If position is more, recur for
                // left subarray
                if (pos - l > k - 1)
                    return kthSmallestUsingQuickSort(arr, l, pos - 1, k);

                // Else recur for right subarray
                return kthSmallestUsingQuickSort(arr, pos + 1, r, k - pos + l - 1);
            }

            // If k is more than number
            // of elements in array
            return int.MaxValue;
        }

    }

}
