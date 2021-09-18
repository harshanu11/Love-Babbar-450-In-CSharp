using System;
using System.Collections.Generic;
using System.Text;
using Xunit;
using Model;


namespace _01_array
{
    public class _05_negative_ele_to_one_side_of_array
    {
		/*
			link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

			variation: 2-pointer
		*/

		[Fact]
		public void arrangeNegative_arrayTest() 
		{
			int[] arr = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
            arrange(arr);
		}
		static void rearrangeQuickSort(int[] arr)
		{
			int n = arr.Length - 1;
			int j = 0, temp;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] < 0)
				{
					arr[i].Swap(ref arr[j]);
					j++;
				}
			}
		}
        // ----------------------------------------------------------------------------------------------------------------------- //
        internal void arrange(int[] arr)
        {
            int negi = 0;
            int pos = arr.Length - 1;

            while (negi <= pos)
            {
                if (arr[negi] < 0 && arr[pos] < 0)
                {
                    negi++;
                }
                else if (arr[negi] > 0 && arr[pos] < 0)
                {
                    //swap(a[negi], a[pos]);
                    arr[negi].Swap(ref arr[pos]);
                    negi++;
                    pos--;
                }
                else if (arr[negi] > 0 && arr[pos] > 0)
                {
                    pos--;
                }
                else
                {
                    negi++;
                    pos--;
                }
            }
        }

    }
}
