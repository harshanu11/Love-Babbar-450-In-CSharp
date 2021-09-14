/*
    link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

    sol: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
    note: this above sol. by geeks for geeks is not working... :(
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System;

// simple and correct solution.
private int getMinDiff(int[] arr, int n, int k)
{
	if (n == 1)
	{
		return 0;
	}
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < k)
		{
			continue; // to avoid negative height in curr_min
		}
		int curr_min = Math.Min(arr[0] + k, arr[i] - k);
		int curr_max = Math.Max(arr[n - 1] - k, arr[i - 1] + k);
		if (curr_max < curr_min)
		{
			continue; // as max till now can't be smaller than min till now hence ignore that element.
		}
		ans = Math.Min(ans, curr_max - curr_min);
	}
	return ans;
}
