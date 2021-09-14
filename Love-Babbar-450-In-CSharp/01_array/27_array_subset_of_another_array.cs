/*
    link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
// SC: O(N)
using System.Collections.Generic;

private string isSubset(int[] a1, int[] a2, int n, int m)
{
	HashSet<int> s = new HashSet<int>();
	for (int i = 0; i < n; i++)
	{
		s.Add(a1[i]);
	}
	for (int i = 0; i < m; i++)
	{
		if (s.find(a2[i]) == s.end())
		{
			return "No";
		}
	}
	return "Yes";
}



// ----------------------------------------------------------------------------------------------------------------------- //
// similar solution.
private string isSubset(int[] a1, int[] a2, int n, int m)
{

	Dictionary<int, int> um = new Dictionary<int, int>();
	Dictionary<int, int> um2 = new Dictionary<int, int>();

	for (int i = 0; i < n; i++)
	{
		um[a1[i]]++;
	}
	for (int i = 0; i < m; i++)
	{
		um2[a2[i]]++;
	}

	int count = 0;
	for (var it = um2.GetEnumerator(); it != um2.end(); it++)
	{
		if (um[it.first] >= it.second)
		{
			count++;
		}
	}

	if (count == m)
	{
		return "Yes";
	}
	else
	{
		return "No";
	}
}
