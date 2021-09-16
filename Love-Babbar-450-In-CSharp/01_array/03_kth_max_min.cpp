/*
    link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

    sol: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
    or
    refer heap/5th_kth....cpp

*/

using System;

// A class for Min Heap
public class MinHeap
{
	private int[] harr; // pointer to array of elements in heap
	private int capacity; // maximum possible size of min heap
	private int heap_size; // Current number of elements in min heap
	public MinHeap(int[] a, int size)
	{
		heap_size = size;
		harr = a; // store address of array
		int i = (heap_size - 1) / 2;
		while (i >= 0)
		{
			MinHeapify(i);
			i--;
		}
	}


	// A recursive method to heapify a subtree with root at given index
	// This method assumes that the subtrees are already heapified
	public void MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && harr[l] < harr[i])
		{
			smallest = l;
		}
		if (r < heap_size && harr[r] < harr[smallest])
		{
			smallest = r;
		}
		if (smallest != i)
		{
			GlobalMembers.swap(ref harr[i], ref harr[smallest]);
			MinHeapify(smallest);
		}
	}

	public int parent(int i)
	{
		return (i - 1) / 2;
	}
	public int left(int i)
	{
		return (2 * i + 1);
	}
	public int right(int i)
	{
		return (2 * i + 2);
	}


	// Method to remove minimum element (or root) from min heap
	public int extractMin()
	{
		if (heap_size == 0)
		{
			return int.MaxValue;
		}

		// Store the minimum vakue.
		int root = harr[0];

		// If there are more than 1 items, move the last item to root
		// and call heapify.
		if (heap_size > 1)
		{
			harr[0] = harr[heap_size - 1];
			MinHeapify(0);
		}

		heap_size--;

		return root;
	}

	public int getMin()
	{
		return harr[0];
	} // Returns minimum
}

public static class GlobalMembers
{
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


	// ----------------------------------------------------------------------------------------------------------------------- //
	/*
	    naive solution (using sorting)
	*/
	// Function to return k'th smallest element in a given array
	public static int kthSmallest(int[] arr, int n, int k)
	{
		// Sort the given array
		sort(arr, arr + n);

		// Return k'th element in the sorted array
		return arr[k - 1];
	}




	// ----------------------------------------------------------------------------------------------------------------------- //
	// better solution using heap (n logk) 
	public static int kthSmallest(int[] arr, int l, int r, int k)
	{
		//code here
		priority_queue<int> maxH = new priority_queue<int>();
		for (int i = l; i <= r; i++)
		{
			maxH.push(arr[i]);
			if (maxH.size() > k)
			{
				maxH.pop();
			}
		}
		return maxH.top();
	}

	// A utility function to swap two elements
	// ----------------------------------------------------------------------------------------------------------------------- //
	/*
	    same as above but heap
	    implementation from scratch
	*/
	// A C++ program to find k'th smallest element using min heap

	// Prototype of a utility function to swap two integers
	public static void swap(ref int x, ref int y)
	{
		int temp = x;
		x = y;
		y = temp;
	}

	// Function to return k'th smallest element in a given array
	public static int kthSmallest(int[] arr, int n, int k)
	{
		// Build a heap of n elements: O(n) time
		MinHeap mh = new MinHeap(arr, n);

		// Do extract min (k-1) times
		for (int i = 0; i < k - 1; i++)
		{
			mh.extractMin();
		}

		// Return root
		return mh.getMin();
	}

	// Driver program to test above methods
	internal static void Main()
	{
		int[] arr = { 12, 3, 5, 7, 19 };
		//C++ TO C# CONVERTER WARNING: This 'sizeof' ratio was replaced with a direct reference to the array length:
		//ORIGINAL LINE: int n = sizeof(arr) / sizeof(arr[0]), k = 2;
		int n = arr.Length;
		int k = 2;
		Console.Write("K'th smallest element is ");
		Console.Write(kthSmallest(arr, n, k));
	}

	// Standard partition process of QuickSort(). It considers the last
	// element as pivot and moves all smaller element to left of it
	// and greater elements to right

	// ----------------------------------------------------------------------------------------------------------------------- //
	/*
	    avg. TC: O(N)
	    worst TC: O(N^2)
	*/

	public static int partition(int[] arr, int l, int r)
	{
		int x = arr[r];
		int i = l;
		for (int j = l; j <= r - 1; j++)
		{
			if (arr[j] <= x)
			{
				swap(ref arr[i], ref arr[j]);
				i++;
			}
		}
		swap(ref arr[i], ref arr[r]);
		return i;
	}

	// This function returns k'th smallest element in arr[l..r] using
	// QuickSort based method. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
	public static int kthSmallest(int[] arr, int l, int r, int k)
	{
		// If k is smaller than number of elements in array
		if (k > 0 && k <= r - l + 1)
		{
			// Partition the array around last element and get
			// position of pivot element in sorted array
			int pos = partition(arr, l, r);

			// If position is same as k
			if (pos - l == k - 1)
			{
				return arr[pos];
			}
			if (pos - l > k - 1) // If position is more, recur for left subarray
			{
				return kthSmallest(arr, l, pos - 1, k);
			}

			// Else recur for right subarray
			return kthSmallest(arr, pos + 1, r, k - (pos + 1) + l);
		}

		// If k is more than number of elements in array
		return int.MaxValue;
	}

	public static void swap(ref int a, ref int b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	// Driver program to test above methods
	internal static void Main()
	{
		int[] arr = { 12, 3, 5, 7, 4, 19, 26 };
		//C++ TO C# CONVERTER WARNING: This 'sizeof' ratio was replaced with a direct reference to the array length:
		//ORIGINAL LINE: int n = sizeof(arr) / sizeof(arr[0]), k = 3;
		int n = arr.Length;
		int k = 3;
		Console.Write("K'th smallest element is ");
		Console.Write(kthSmallest(arr, 0, n - 1, k));
	}
}

