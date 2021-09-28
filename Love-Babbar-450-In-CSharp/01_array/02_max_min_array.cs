using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _02_max_min_array
    {
        /*
            link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
            can also be done using several methods, visit link for more methods
            int []arr = {1000, 11, 445, 1, 330, 3000};
            Minimum element is 1
            Maximum element is 3000

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
            Debug.Write("MIN: ");
            Debug.Write(mn);
            Debug.Write(" MAX: ");
            Debug.Write(mx);
            var ans = MaxAndMin(arr);
        }
        public List<int> MaxAndMin(int[] arr)
        {
            List<int> ans = new List<int>();
            int max = int.MinValue;
            int min = int.MaxValue;
            for (int a = 0; a < arr.Length; a++)
            {
                if (arr[a] > max) max = arr[a];
                else if (arr[a] < min) min = arr[a];
            }
            ans.Add(max);
            ans.Add(min);
            return ans;
        }
    }
}
