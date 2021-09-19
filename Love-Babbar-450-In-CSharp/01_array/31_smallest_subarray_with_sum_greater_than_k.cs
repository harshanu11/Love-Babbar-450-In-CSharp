using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _31_smallest_subarray_with_sum_greater_than_k
    {
        /*
    link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
        Smallest subarray with sum greater than x 
Easy Accuracy: 49.92% Submissions: 28619 Points: 2
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).
        Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}
*/

        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
//// TC: O(n) 

//// Returns length of smallest subarray with sum greater than x. If there is no subarray with given sum, then returns n+1
//int smallestSubWithSum(int arr[], int n, int x)
//{
//    // Initialize current sum and minimum length
//    int curr_sum = 0, min_len = n + 1;

//    // Initialize starting and ending indexes
//    int start = 0, end = 0;
//    while (end < n)
//    {
//        // Keep adding array elements while current sum is smaller than or equal to x
//        while (curr_sum <= x && end < n)
//            curr_sum += arr[end++];

//        // If current sum becomes greater than x.
//        while (curr_sum > x && start < n)
//        {
//            // Update minimum length if needed
//            if (end - start < min_len)
//                min_len = end - start;

//            // remove starting elements
//            curr_sum -= arr[start++];
//        }
//    }
//    return min_len;
//}
