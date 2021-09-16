using Xunit;

namespace _01_array
{
    /*
        link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
        note: array is pass by reference so no need to worry while changing value it will change in original array.
    */

    public class _01_reverse_array
    {
        [Fact]
        public void reverse_arrayTest()
        {
            int[] arr = { 1000, 11, 445, 1, 330, 3000 };
            rvereseArray(arr, 0, arr.Length - 1);
            rvereseArrayRecursion(arr, 0, arr.Length - 1);
        }
        // TC: O(N)
        private void rvereseArray(int[] arr, int start, int end)
        {
            while (start < end)
            {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
        // TC: O(N)
        private void rvereseArrayRecursion(int[] arr, int start, int end)
        {
            if (start >= end) return;
            var temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            rvereseArrayRecursion(arr, start + 1, end - 1);
        }
    }
}
