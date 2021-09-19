using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _04_sort_arr_0_1_2
    {
		/*
			link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

			logic: iterate mid and if mid==0 then swap with low and then low++, mid++
				   if mid==2 then swap with high and then high--, mid
				   else mid++ as it would be 1.

			variation: 2-pointer

		arr[]= {0 2 1 2 0}
		Output:
		0 0 1 2 2
		*/
		[Fact]
        public void sort_arr_0_1_2_arrayTest()
        {
			int a = 5;
			int b = 6;
			a.Swap(ref b);
			int[] arr = { 0, 2, 1, 2, 0 };
			sort012(arr);
		}


		// ----------------------------------------------------------------------------------------------------------------------- //

		void sort012(int[] a)
		{
			int low = 0, high =a.Length - 1, mid = 0;
			while (mid <= high)
			{
				if (a[mid] == 0)
				{
					a[low].Swap(ref a[mid]);
					low++;
					mid++;
				}
				else if (a[mid] == 1)
				{
					mid++;
				}
				else
				{
					a[mid].Swap(ref a[high]);
					high--;
				}
			}
		}
	}
}
