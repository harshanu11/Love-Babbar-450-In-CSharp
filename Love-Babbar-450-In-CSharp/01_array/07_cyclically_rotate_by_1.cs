using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _07_cyclically_rotate_by_1
    {
        /*
            link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
        Input:
        N = 5
        A[] = {1, 2, 3, 4, 5}
        Output:
        5 1 2 3 4
        */


        // ----------------------------------------------------------------------------------------------------------------------- //
        private void rotate(int[] arr, int n)
        {
            int temp = arr[n - 1];

            for (int i = n - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }

        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//void rotate(int arr[], int n)
//{
//    int temp = arr[n - 1];

//    for (int i = n - 1; i > 0; i--)
//    {
//        arr[i] = arr[i - 1];
//    }
//    arr[0] = temp;
//}