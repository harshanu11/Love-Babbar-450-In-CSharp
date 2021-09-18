using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _11_heap
{
    public class _02_sort_array_using_heap_HEAPSORT
    {
        /*
            link: https://www.geeksforgeeks.org/heap-sort/

            build heap means: either build max heap or min heap there is no such thing as only heap

            note: to get ascending sorted array use maxHeap,
                  to get descending sorted array use minHeap
        */
        NodeHeap o = new NodeHeap();
        [Fact]
        private void HeapSortTest()
        {
            int[] arr = { 12, 11, 13, 5, 6, 7 };
            int n = arr.Length;
            o.sortAse(arr);
            Debug.Write("Sorted array is \n");
            o.printHeap(arr, n);
        }

    }
}
