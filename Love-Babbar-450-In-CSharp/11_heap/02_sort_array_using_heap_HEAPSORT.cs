using System;
using System.Collections.Generic;
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
        _01_maxheap_minheap_using_array_and_recursion o = new _01_maxheap_minheap_using_array_and_recursion();
        [Fact]
        private void HeapSortTest()
        {
            int[] arr = { 12, 11, 13, 5, 6, 7 };
            //C++ TO C# CONVERTER WARNING: This 'sizeof' ratio was replaced with a direct reference to the array length:
            //ORIGINAL LINE: int n = sizeof(arr) / sizeof(arr[0]);
            int n = arr.Length;

            heapSort(arr, n);

            Console.Write("Sorted array is \n");
            o.printHeap(arr, n);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        // C++ program for implementation of Heap Sort


        // main function to do heap sort
        private void heapSort(int[] arr, int len)
        {
            // Build heap (rearrange array)
            for (int i = len / 2 - 1; i >= 0; i--)
            {
                o.heapifyMax(arr, len, i);
            }

            // One by one extract an element from heap
            for (int i = len - 1; i > 0; i--)
            {
                // Move current root to end
               // swap(arr[0], arr[i]);
                arr[0] = arr[0] ^ arr[1];
                arr[1] = arr[0] ^ arr[1];
                arr[0] = arr[0] ^ arr[1];

                // call max heapify on the reduced heap
                o.heapifyMax(arr, i, 0);
            }
        }

    }
}
