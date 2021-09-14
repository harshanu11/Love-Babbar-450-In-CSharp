/*
    link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
using System.Collections.Generic;

private void threeWayPartition(List<int> array, int a, int b)
{
	int low = 0;
	int high = array.Count - 1;
	int mid = 0;

	while (mid <= high)
	{
		if (array[mid] < a)
		{
			swap(array[mid++], array[low++]); // we r sure after swap we won't get <a, bcoz it would have processed earlier.
		}
		else if (array[mid] > b)
		{
			swap(array[high--], array[mid]); // here it is possible that after swap we can get >b value again hence no increment in mid.
		}
		else
		{
			mid++;
		}
	}
}
