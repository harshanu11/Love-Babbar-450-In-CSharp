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
        */

        [Fact]
        public void Test()
        {
            int[] arr = { 12, 3, 5, 7, 19 };
            int n = arr.Length, k = 2;
            Debug.Write("K'th smallest element is " +  kthSmallest(arr, n, k));

            int[] arr1 = { 12, 3, 5, 7, 4, 19, 26 };
            k = 3;
            Debug.Write("K'th smallest element is " + kthSmallest(arr, 0, arr.Length - 1, k));
        }
        int kthSmallest(int[] arr, int n, int k)
        {

            // Build a heap of first k elements: O(k) time
            MinHeap mh = new MinHeap(arr, n);

            // Process remaining n-k elements. If current element is
            // smaller than root, replace root with current element
            for (int i = 0; i < k - 1; i++)
                mh.extractMin();

            // Return root
            return mh.getMin();
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
        public static int partition(int[] arr,
                                    int l, int r)
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
        public static int kthSmallest(int[] arr, int l,
                                      int r, int k)
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
                    return kthSmallest(arr, l, pos - 1, k);

                // Else recur for right subarray
                return kthSmallest(arr, pos + 1, r,
                                   k - pos + l - 1);
            }

            // If k is more than number
            // of elements in array
            return int.MaxValue;
        }

    }
    public class MinHeap
    {
        int[] harr; // pointer to array of elements in heap
                    //    int capacity; // maximum possible size of min heap
        int heap_size; // Current number of elements in min heap

        int parent(int i) { return (i - 1) / 2; }
        int left(int i) { return ((2 * i) + 1); }
        int right(int i) { return ((2 * i) + 2); }
        public int getMin() { return harr[0]; } // Returns minimum

        // to replace root with new node x and heapify() new root
        public void replaceMax(int x)
        {
            this.harr[0] = x;
            minHeapify(0);
        }

        public MinHeap(int[] a, int size)
        {
            heap_size = size;
            harr = a; // store address of array
            int i = (heap_size - 1) / 2;
            while (i >= 0)
            {
                minHeapify(i);
                i--;
            }
        }

        // Method to remove maximum element (or root) from min heap
        public int extractMin()
        {
            if (heap_size == 0)
                return Int32.MaxValue;

            // Store the maximum vakue.
            int root = harr[0];

            // If there are more than 1 items, move the last item to root
            // and call heapify.
            if (heap_size > 1)
            {
                harr[0] = harr[heap_size - 1];
                minHeapify(0);
            }
            heap_size--;
            return root;
        }

        // A recursive method to heapify a subtree with root at given index
        // This method assumes that the subtrees are already heapified
        public void minHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < heap_size && harr[l] < harr[i])
                smallest = l;
            if (r < heap_size && harr[r] < harr[smallest])
                smallest = r;
            if (smallest != i)
            {
                int t = harr[i];
                harr[i] = harr[smallest];
                harr[smallest] = t;
                minHeapify(smallest);
            }
        }
    };
}
