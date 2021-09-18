/*
    link: https://practice.geeksforgeeks.org/problems/count-element-occurences/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// using count method
using System;
using System.Collections.Generic;

private int countOccurence(int[] arr, int n, int k)
{
	long range = 1e6 + 7;
	long[] cnt = new long[range];
	//C++ TO C# CONVERTER TODO TASK: The memory management function 'memset' has no equivalent in C#:
	memset(cnt, 0, sizeof(long));

	for (int i = 0; i < n; i++)
	{
		cnt[arr[i]]++;
	}

	int global = 0;
	for (int i = 0; i < range; i++)
	{
		if (cnt[i] != 0 && cnt[i] > n / k)
		{
			global++;
		}
	}

	return global;
}


// ----------------------------------------------------------------------------------------------------------------------- //
// using hashig
private void morethanNbyK(int[] arr, int n, int k)
{
	int x = n / k;

	// unordered_map initialization
	Dictionary<int, int> freq = new Dictionary<int, int>();

	for (int i = 0; i < n; i++)
	{
		freq[arr[i]]++;
	}

	// Traversing the map
	foreach (var i in freq)
	{

		// Checking if value of a key-value pair
		// is greater than x (where x=n/k)
		if (i.second > x)
		{

			// Print the key of whose value
			// is greater than x
			Debug.Write(i.first);
			Debug.Write("\n");
		}
	}
}

