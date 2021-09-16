using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _02_max_min_array
    {
        /*
    link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

    can also be done using several methods, visit link for more methods
*/
        [Fact]
        public void MaxMin_arrayTest() 
        {
			int[] arr = { 1000, 11, 445, 1, 330, 3000 };
			int arr_size = 6;

			int mx = arr[0];
			int mn = arr[1];

			for (int i = 1; i < arr_size; i++)
			{
				if (arr[i] > mx)
				{
					mx = arr[i];
				}
				if (arr[i] < mn)
				{
					mn = arr[i];
				}
			}
			Console.Write("MIN: ");
			Console.Write(mn);
			Console.Write(" MAX: ");
			Console.Write(mx);
		}
    }
}
