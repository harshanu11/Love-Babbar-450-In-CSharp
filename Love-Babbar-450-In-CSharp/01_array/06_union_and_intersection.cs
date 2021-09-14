/*
    link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

    sol: https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
    for different approach
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System.Collections.Generic;

private int doUnion(int[] a, int n, int[] b, int m)
{
	SortedSet<int> s = new SortedSet<int>();
	for (int i = 0; i < n; i++)
	{
		s.Add(a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		s.Add(b[i]);
	}
	return s.Count;
}

private int doIntersection(int[] a, int n, int[] b, int m)
{
	sort(a, a + n);
	sort(b, b + m);

	int i = 0;
	int j = 0;
	int ans = 0;

	while (i <= j)
	{
		if (a[i] == b[j])
		{
			ans++;
			i++;
			j++;
		}
		else if (a[i] < b[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return ans;
}


