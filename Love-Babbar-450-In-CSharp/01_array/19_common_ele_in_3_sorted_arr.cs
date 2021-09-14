/*
    link: https://practice.geeksforgeeks.org/problems/common-elements1132/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System.Collections.Generic;

private List<int> commonElements(int[] a, int[] b, int[] c, int n1, int n2, int n3)
{
	SortedSet<int> ans = new SortedSet<int>();
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2 && k < n3)
	{
		if (a[i] == b[j] && a[i] == c[k])
		{
			ans.Add(a[i]);
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j] || a[i] < c[k])
		{
			i++;
		}
		else if (b[j] < a[i] || b[j] < c[k])
		{
			j++;
		}
		else if (c[k] < b[j] || c[k] < a[i])
		{
			k++;
		}
	}
	List<int> nn = new List<int>();
	//C++ TO C# CONVERTER TODO TASK: The following line could not be converted:
	for (ele : ans)
	{
	nn.Add(ele);
}
return new List<int>(nn);
}



// ----------------------------------------------------------------------------------------------------------------------- //
// alternate solution (improved)
private List<int> commonElements(int[] A, int[] B, int[] C, int n1, int n2, int n3)
{
	int i = 0;
	int j = 0;
	int k = 0;

	List<int> res = new List<int>();
	int last = int.MinValue;
	while (i < n1 && j < n2 && k < n3)
	{
		if (A[i] == B[j] && A[i] == C[k] && A[i] != last)
		{
			res.Add(A[i]);
			last = A[i];
			i++;
			j++;
			k++;
		}
		else if (min({ A[i], B[j], C[k]}) == A[i])
		{
	i++;
}
		else if (min({ A[i], B[j], C[k]}) == B[j])
		{
	j++;
}
		else
{
	k++;
}
	}
	return new List<int>(res);
}
