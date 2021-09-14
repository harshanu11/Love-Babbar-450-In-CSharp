/*
    link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System;
using System.Collections.Generic;

private long findMinDiff(List<long> a, long n, long m)
{
	// sorted so that we can different window(sub-array) of size m.
	a.Sort();

	long ans = a[m - 1] - a[0]; // took first window from 0 to m-1.

	// now we iterate every window(sub-array) and check for the max-min from that range.
	for (int i = 1; i < n - m + 1; i++)
	{
		ans = Math.Min(a[i + m - 1] - a[i], ans);
	}
	return ans;
}
