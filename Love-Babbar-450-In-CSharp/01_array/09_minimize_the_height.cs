using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _09_minimize_the_height
    {
        /*
    link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

    sol: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
        Input:
        K = 2, N = 4
        Arr[] = {1, 5, 8, 10}
        Output:
        5
        Explanation:
        The array can be modified as 
        {3, 3, 6, 8}. The difference between 
        the largest and the smallest is 8-3 = 5.
            note: this above sol. by geeks for geeks is not working... :(
*/


        // ----------------------------------------------------------------------------------------------------------------------- //
        // simple and correct solution.

        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

    sol: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
    note: this above sol. by geeks for geeks is not working... :(
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//// simple and correct solution.
//int getMinDiff(int arr[], int n, int k)
//{
//    if (n == 1) return 0;
//    sort(arr, arr + n);
//    int ans = arr[n - 1] - arr[0];

//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] < k) continue;     // to avoid negative height in curr_min
//        int curr_min = min(arr[0] + k, arr[i] - k);
//        int curr_max = max(arr[n - 1] - k, arr[i - 1] + k);
//        if (curr_max < curr_min) continue;      // as max till now can't be smaller than min till now hence ignore that element.
//        ans = min(ans, curr_max - curr_min);
//    }
//    return ans;
//}