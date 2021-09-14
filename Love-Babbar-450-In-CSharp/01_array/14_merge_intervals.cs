/*
    link: https://leetcode.com/problems/merge-intervals/

    simple greedy approach
*/

// ----------------------------------------------------------------------------------------------------------------------- //
using System;
using System.Collections.Generic;

private List<List<int>> merge(List<List<int>> intervals)
{
	int n = intervals.Count;
	int idx = 0;
	for (int i = 1; i < n; i++)
	{
		//C++ TO C# CONVERTER TODO TASK: C# does not have an equivalent to references to value types:
		//ORIGINAL LINE: long& idx_end = intervals[idx].second;
		long idx_end = intervals[idx].second;
		if (idx_end >= intervals[i].first)
		{
			idx_end = Math.Max(idx_end, intervals[i].first);
		}
		else
		{
			idx++;
			intervals[idx] = new List<int>(intervals[i]);
		}
	}

	List<List<int>> ans = new List<List<int>>(intervals.GetRange(0, idx + 1));
	return new List<List<int>>(ans);
}


// ----------------------------------------------------------------------------------------------------------------------- //
private List<List<int>> merge(List<List<int>> intervals)
{
	List<List<int>> ans = new List<List<int>>();
	int k = 0;
	intervals.Sort();

	int start = intervals[0][0];
	int end = intervals[0][1];
	for (int i = 1; i < intervals.Count; i++)
	{
		if (intervals[i][0] <= end)
		{
			end = Math.Max(end, intervals[i][1]);
		}
		else
		{
			ans.Add(new List<int>(start, end));
			start = intervals[i][0];
			end = intervals[i][1];
		}
	}
	if (ans.Count == 0 || ans[ans.Count - 1][1] != intervals[intervals.Count - 1][1])
	{
		ans.Add(new List<int>(start, end));
	}
	return new List<List<int>>(ans);
}



// ----------------------------------------------------------------------------------------------------------------------- //
private List<List<int>> merge(List<List<int>> intervals)
{
	if (intervals.Count == 0)
	{
		return new List<List<int>>();
	}

	intervals.Sort();

	int right = 1;
	int lval = intervals[0][0];
	int rval = intervals[0][1];
	int n = intervals.Count;
	List<List<int>> ans = new List<List<int>>();

	while (right < n)
	{
		if (rval > intervals[right][1])
		{
			right++;
		}
		else if (rval < intervals[right][0])
		{
			ans.Add(new List<int>(lval, rval));
			lval = intervals[right][0];
			rval = intervals[right][1];
			right++;
		}
		else if (rval >= intervals[right][0] && rval <= intervals[right][1])
		{
			rval = intervals[right][1];
			right++;
		}

	}
	ans.Add(new List<int>(lval, rval));
	return new List<List<int>>(ans);
}
