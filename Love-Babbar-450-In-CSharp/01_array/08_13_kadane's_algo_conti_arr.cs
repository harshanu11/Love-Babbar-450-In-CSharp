using System;
using System.Collections.Generic;
using System.Text;using Xunit;

namespace _01_array
{
public class _13_kadane_s_algo
{[Fact] public void Test() { }
    }
}
///*
//    link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
//    Kadane's Algorithm 
//    Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

//*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//int maxSubarraySum(int arr[], int n)
//{
//    int dp[n];
//    dp[0] = max(INT_MIN, arr[0]);
//    int omax = dp[0];

//    for (int i = 1; i < n; i++)
//    {

//        dp[i] = max(arr[i] + dp[i - 1], arr[i]);

//        omax = max(dp[i], omax);
//    }
//    return omax;
//}