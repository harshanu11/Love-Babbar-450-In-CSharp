/*
    link: https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System;

private bool isPalindrom(int n)
{
	string a = Convert.ToString(n);
	int i = 0;
	int j = a.Length - 1;
	while (i <= j)
	{
		if (a[i] != a[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
private int PalinArray(int[] a, int n)
{ //add code here.
	for (int i = 0; i < n; i++)
	{
		if (!isPalindrom(a[i]))
		{
			return 0;
		}
	}
	return 1;
}
