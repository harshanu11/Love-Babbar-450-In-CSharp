using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _33_min_swaps_require_to_grp_together
    {
        /*
    link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

    sol: https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/

        equired to bring all the numbers less than or equal to k together.

        Example 1:
        
        Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
        Output : 1
        Explanation:
        To bring elements 2, 1, 3 together, swap element '5' with '3'
        such that final array will be- arr[] = {2, 1, 3, 6, 5}
*/

        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

    sol: https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
//int minSwap(int* arr, int n, int k)
//{

//    // Find count of elements which are
//    // less than equals to k
//    int count = 0;
//    for (int i = 0; i < n; ++i)
//        if (arr[i] <= k)
//            ++count;

//    // Find unwanted elements in current
//    // window of size 'count'
//    int bad = 0;
//    for (int i = 0; i < count; ++i)
//        if (arr[i] > k)
//            ++bad;

//    // Initialize answer with 'bad' value of
//    // current window
//    int ans = bad;
//    for (int i = 0, j = count; j < n; ++i, ++j)
//    {

//        // Decrement count of previous window
//        if (arr[i] > k)
//            --bad;

//        // Increment count of current window
//        if (arr[j] > k)
//            ++bad;

//        // Update ans if count of 'bad'
//        // is less in current window
//        ans = min(ans, bad);
//    }
//    return ans;
//}
