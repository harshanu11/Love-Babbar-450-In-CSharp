using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _11_heap
{
    public class _01_maxheap_minheap_using_array_and_recursion
    {
        NodeHeap heap = new NodeHeap();

        /*
            link: https://www.geeksforgeeks.org/building-heap-from-array/

            Time Complexity: Heapify a single node takes O(log N) [as every jump will be to child]
             time complexity where N is the total number of Nodes. Therefore, building the entire Heap
            will take N heapify operations and the total time complexity will be O(N*logN).

            In reality, building a heap takes O(n) time depending on the implementation which can be seen here.
        */
        [Fact]
        public void buildHeapWithReverseLevelOrder_HeapTest()
        {
            // Binary Tree Representation
            // of input array
            // 1
            //		 /	
            //	// 3		 5
            //	 / \	 /
            //	// 4	 6 13 10
            // / \ /
            //	// 9 8 15 17
            int[] arr = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

            buildMaxHeapWithReverseLevelOrder(arr, arr.Length);
            buildMinHeapWithReverseLevelOrder(arr, arr.Length);

            printHeap(arr, arr.Length);
            // Final Heap:
            // 17
            //		 /	
            //	// 15		 13
            //	 / \	 /
            //	// 9	 6 5 10
            //	 / \ /
            //	// 4 8 3 1
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        // C++ program for building Heap from Array

        // Function to build a Max-Heap from the given array
        private void buildMaxHeapWithReverseLevelOrder(int[] arr, int len)
        {
            // Index of last non-leaf node  [parent of last leaf node]
            int startIdx = (len / 2) - 1;

            // Perform reverse level order traversal
            // from last non-leaf node and heapify
            // each node
            for (int curr = startIdx; curr >= 0; curr--)
            {
                heap.heapifyMax(arr, len, curr);
            }
        }
        private void buildMinHeapWithReverseLevelOrder(int[] arr, int len)
        {
            // Index of last non-leaf node  [parent of last leaf node]
            int startIdx = (len / 2) - 1;

            // Perform reverse level order traversal
            // from last non-leaf node and heapify
            // each node
            for (int curr = startIdx; curr >= 0; curr--)
            {
                heap.heapifyMin(arr, len, curr);
            }
        }


        // A utility function to print the array
        // representation of Heap
        internal void printHeap(int[] arr, int n)
        {
            Debug.Write("Array representation of Heap is:\n");

            for (int i = 0; i < n; ++i)
            {
                Debug.Write(arr[i]);
                Debug.Write(" ");
            }
            Debug.Write("\n");
        }
    }
}
