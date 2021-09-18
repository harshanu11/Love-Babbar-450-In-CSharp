using System.Diagnostics;

namespace Model
{
    // heap is complete binary tree(left node should complete ) which satisfy heap prop which is child ll always samll or larger form root also 
    public class NodeHeap
    {
        public void insertNode(int[] arr, int lastIndex, int value)
        {
            arr[lastIndex] = value;
            while (lastIndex > 1)
            {
                int parant = lastIndex / 2;
                if (arr[parant] < arr[lastIndex])
                {
                    arr[parant] = arr[parant] ^ arr[lastIndex];
                    arr[lastIndex] = arr[parant] ^ arr[lastIndex];
                    arr[parant] = arr[parant] ^ arr[lastIndex];
                    lastIndex = parant;
                }
                else return;
            }
        }
        public int deleteRoot(int[] arr)
        {
            int lastIndex = arr.Length - 1;
            int lastElement = arr[lastIndex ];
            arr[0] = lastElement;
            lastIndex = lastIndex - 1;
            heapifyMax(arr, lastIndex, 0);
            return lastIndex;
        }
        public void sortAse(int[] arr)
        {
            int n = arr.Length;
            BuildHeapMax(arr);
            for (int i = n - 1; i > 0; i--)
            {
                arr[0] = arr[0]^ arr[i];
                arr[i] = arr[0]^ arr[i];
                arr[0] = arr[0]^ arr[i];
                heapifyMax(arr, i, 0);
            }
        }

        public void sortDesc(int[] arr)
        {
            int n = arr.Length;
            BuildHeapMin(arr);
            for (int i = n - 1; i > 0; i--)
            {
                arr[0] = arr[0] ^ arr[i];
                arr[i] = arr[0] ^ arr[i];
                arr[0] = arr[0] ^ arr[i];
                heapifyMin(arr, i, 0);
            }
        }
        private void BuildHeapMin(int[] arr)
        {
            int n = arr.Length;
            for (int h = 0; h < n / 2; h++)
            {
                heapifyMin(arr, n, h);
            }
        }
        private void BuildHeapMax(int[] arr)
        {
            int n = arr.Length;
            for (int h = 0; h < n / 2; h++)
            {
                heapifyMax(arr, n, h);
            }
        }
        internal void heapifyMax(int[] arr, int tillPosition, int root)
        {
            int largest = root; 
            int l = 2 * root + 1;
            int r = 2 * root + 2; 
            if (l < tillPosition && arr[l] > arr[largest]) largest = l;
            if (r < tillPosition && arr[r] > arr[largest]) largest = r;
            if (largest != root)
            {
                arr[root] = arr[root] ^ arr[largest];
                arr[largest] = arr[root] ^ arr[largest];
                arr[root] = arr[root] ^ arr[largest];
                heapifyMax(arr, tillPosition, largest);
            }
        }

        public void heapifyMin(int[] arr, int len, int root)
        {
            int smallest = root; // The node which will be heapified
            int l = 2 * root + 1; // left child node
            int r = 2 * root + 2; // right child node
            if (l < len && arr[l] < arr[smallest]) smallest = l;
            if (r < len && arr[r] < arr[smallest]) smallest = r;
            if (smallest != root)
            {
                arr[root] = arr[root] ^ arr[smallest];
                arr[smallest] = arr[root] ^ arr[smallest];
                arr[root] = arr[root] ^ arr[smallest];
                // Recursively heapify the affected sub-tree
                heapifyMin(arr, len, smallest);
            }
        }


        // A utility function to print the array
        // representation of Heap
        internal void printHeap(int[] arr, int len)
        {
            Debug.Write("Array representation of Heap is:\n");

            for (int i = 0; i < len; ++i)
            {
                Debug.Write(arr[i]);
                Debug.Write(" ");
            }
            Debug.Write("\n");
        }
    }
}
