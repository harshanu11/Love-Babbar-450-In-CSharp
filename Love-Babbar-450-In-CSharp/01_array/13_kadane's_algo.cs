/*
    link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System;

private int maxSubarraySum(int[] arr, int n)
{
	int[] dp = new int[n];
	dp[0] = Math.Max(int.MinValue, arr[0]);
	int omax = dp[0];

	for (int i = 1; i < n; i++)
	{

		dp[i] = Math.Max(arr[i] + dp[i - 1], arr[i]);

		omax = Math.Max(dp[i], omax);
	}
	return omax;
}
