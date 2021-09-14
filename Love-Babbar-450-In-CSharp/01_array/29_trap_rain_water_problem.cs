/*
    link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// here we keep left max and right max at that point to get how much max water can be hold at current position.
using System;

private int trappingWater(int[] arr, int n)
{
	int ans = 0;
	int[] l = new int[n];
	int[] r = new int[n];
	l[0] = arr[0];
	r[n - 1] = arr[n - 1];

	for (int i = 1; i < n; i++)
	{
		l[i] = Math.Max(arr[i], l[i - 1]);
	}
	for (int i = n - 2; i >= 0; i--)
	{
		r[i] = Math.Max(arr[i], r[i + 1]);
	}

	for (int i = 1; i < n - 1; i++)
	{
		ans += Math.Max(0, Math.Min(l[i], r[i]) - arr[i]);
	}
	return ans;
}
