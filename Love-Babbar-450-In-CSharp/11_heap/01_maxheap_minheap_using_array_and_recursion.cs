using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace heap
{
    public class _01_maxheap_minheap_using_array_and_recursion
    {

		/*
    link: https://www.geeksforgeeks.org/building-heap-from-array/

    Time Complexity: Heapify a single node takes O(log N) [as every jump will be to child]
     time complexity where N is the total number of Nodes. Therefore, building the entire Heap
    will take N heapify operations and the total time complexity will be O(N*logN).

    In reality, building a heap takes O(n) time depending on the implementation which can be seen here.
*/


		// ----------------------------------------------------------------------------------------------------------------------- //
		// C++ program for building Heap from Array



		// To heapify a subtree rooted with node i which is
		// an index in arr[]. N is size of heap
		private void heapifyMax(int[] arr, int len, int curr)
		{
			int largest = curr; // Initialize largest as root
			int l = 2 * curr + 1; // left = 2*i + 1
			int r = 2 * curr + 2; // right = 2*i + 2

			// If left child is larger than root
			if (l < len && arr[l] > arr[largest])
			{
				largest = l;
			}

			// If right child is larger than largest so far
			if (r < len && arr[r] > arr[largest])
			{
				largest = r;
			}

			// If largest is not root
			if (largest != curr)
			{
				arr[curr] = arr[curr] ^ arr[largest];
				arr[largest] = arr[curr] ^ arr[largest];
				arr[curr] = arr[curr] ^ arr[largest];
				// Recursively heapify the affected sub-tree
				heapifyMax(arr, len, largest);
			}
		}

		private void heapifyMin(int[] arr, int len, int curr)
		{
			int smallest = curr; // The node which will be heapified
			int l = 2 * curr + 1; // left child node
			int r = 2 * curr + 2; // right child node

			// Check if left child is smaller than its parent
			if (l < len && arr[l] < arr[smallest])
			{
				smallest = l;
			}

			// Check if right child is smaller than smallest
			if (r < len && arr[r] < arr[smallest])
			{
				smallest = r;
			}

			// If smallest is not parent
			if (smallest != curr)
			{
				arr[curr] = arr[curr] ^ arr[smallest];
				arr[smallest] = arr[curr] ^ arr[smallest];
				arr[curr] = arr[curr] ^ arr[smallest];
				// Recursively heapify the affected sub-tree
				heapifyMin(arr,len, smallest);
			}
		}

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
				heapifyMax(arr, len, curr);
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
				heapifyMin(arr, len, curr);
			}
		}

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
		// A utility function to print the array
		// representation of Heap
		private void printHeap(int[] arr, int n)
		{
			Console.Write("Array representation of Heap is:\n");

			for (int i = 0; i < n; ++i)
			{
				Console.Write(arr[i]);
				Console.Write(" ");
			}
			Console.Write("\n");
		}


	}
}
