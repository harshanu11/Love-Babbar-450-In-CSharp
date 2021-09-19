using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _08_largest_sum_conti_arr
    {
        [Fact] public void Test() { }
        /*
			link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
			kadane's algorithm
        */
        // ----------------------------------------------------------------------------------------------------------------------- //
        private int maxSubarraySumDp(int[] arr, int n)
        {
            int[] dp = new int[n];

            dp[0] = Math.Max(0, arr[0]);
            int omax = dp[0];
            for (int i = 1; i < n; i++)
            {
                dp[i] = Math.Max(dp[i - 1] + arr[i], arr[i]);
                omax = Math.Max(dp[i], omax);
            }
            return omax;
        }
        public long maxSubarraySum(int[] arr, int n)
        {
            long maxh = 0, maxf = int.MinValue;

            //Iterating over the array.
            for (int i = 0; i < n; i++)
            {
                //Updating max sum till current index.
                maxh += arr[i];
                //Storing max sum so far by choosing maximum between max 
                //sum so far and max till current index.
                maxf = Math.Max(maxh, maxf);

                //If max sum at current index is negative, we do not need to add
                //it to result so we update it to zero.
                if (maxh < 0)
                    maxh = 0;

            }
            //returning the result.
            return maxf;

        }

    }



}
