/*
    link: https://leetcode.com/problems/find-the-duplicate-number/submissions/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    perfect solution. (very tricky)
    here we take every element and make negative to its 0 based index hence whenever we get again positive int. its the ans.

    for eg. nums = [3,1,3,4,2]
    here as 3 is repeating observe that while tracing whole program (3-1=2 to make 0 based) position will be negative and will again become positive.
*/
using System;
using System.Collections.Generic;

private int findDuplicate(List<int> nums)
{
	int size = nums.Count;
	for (int i = 0; i < size; i++)
	{
		int n = Math.Abs(nums[i]) - 1;
		nums[n] = -nums[n];
		if (nums[n] > 0)
		{
			return n + 1;
		}
	}
	return 0; // of no use just to avoid error
}


// ----------------------------------------------------------------------------------------------------------------------- //
// space comp.: less than n. but not O(1)
private int findDuplicate(List<int> nums)
{
	SortedSet<int> s = new SortedSet<int>();
	for (int i = 0; i < nums.Count; i++)
	{
		if (s.find(nums[i]) != s.end())
		{
			return nums[i];
		}
		s.Add(nums[i]);
	}
	return 1;
}

