/*
    link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System;
using System.Collections.Generic;

private int findLongestConseqSubseq(int[] arr, int N)
{
	//Your code here
	int range = 1e6;
	int[] cnt = new int[range];
	//C++ TO C# CONVERTER TODO TASK: The memory management function 'memset' has no equivalent in C#:
	memset(cnt, 0, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		cnt[arr[i]]++;
	}
	int local = 0;
	int global = 0;
	for (int i = 0; i < range; i++)
	{
		if (cnt[i] > 0)
		{
			local++;
		}
		else
		{
			local = 0;
		}
		global = Math.Max(global, local);
	}
	return global;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// using hashing
private int findLongestConseqSubseq(int[] arr, int n)
{
	//using a Set to store elements.
	HashSet<int> S = new HashSet<int>();
	int ans = 0;

	//inserting all the array elements in Set.
	for (int i = 0; i < n; i++)
	{
		S.Add(arr[i]);
	}

	//checking each possible sequence from the start.
	for (int i = 0; i < n; i++)
	{
		//if current element is starting element of a sequence then only 
		//we try to find out the length of sequence.
		if (S.find(arr[i] - 1) == S.end())
		{

			int j = arr[i];
			//then we keep checking whether the next consecutive elements
			//are present in Set and we keep incrementing the counter.
			while (S.find(j) != S.end())
			{
				j++;
			}

			//storing the maximum count.
			ans = Math.Max(ans, j - arr[i]);
		}
	}
	//returning the length of longest subsequence
	return ans;
}
