using System.Diagnostics;

namespace _11_heap
{
    public class NodeHeap
    {
        // To heapify a subtree rooted with node i which is
        // an index in arr[]. N is size of heap
        internal void heapifyMax(int[] arr, int len, int curr)
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

        public void heapifyMin(int[] arr, int len, int curr)
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
                heapifyMin(arr, len, smallest);
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
