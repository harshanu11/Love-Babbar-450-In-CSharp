using System;
using Xunit;

namespace _01_array
{
    public class _08_largest_sum_conti_arr
    {
        [Fact]
        public void Test()
        {
            //var nums = new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            var nums = new int[] { -2, -2 };
            var ans = ContiguousMaxSubArray1N2Complexity(nums);
            ans = ContiguousMaxSubArrayKadaneAlgo_nComplexity(nums);
            ans = ContiguousmaxSubarraySumDp(nums, nums.Length);
        }
        /*
			link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
			kadane's algorithm is find sum of Contiguous array
        */
        public int ContiguousMaxSubArray1N2Complexity(int[] nums)
        {
            int max = int.MinValue;
            for (int i = 0; i < nums.Length; i++)
            {
                int current = 0;
                for (int j = i; j < nums.Length; j++)
                {
                    current = current + nums[j];
                    if (current > max)
                    {
                        max = current;
                    }
                }
            }
            return max;
        }
        public int ContiguousMaxSubArrayKadaneAlgo_nComplexity(int[] nums)
        {
            int max = int.MinValue;
            int current = 0;
            if (nums.Length == 1)
            {
                return nums[0];
            }
            for (int i = 0; i < nums.Length; i++)
            {
                current = current + nums[i];
                if (current > max)
                {
                    max = current;
                }
                if (current < 0)
                {
                    current = 0;
                }
            }
            return max;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        private int ContiguousmaxSubarraySumDp(int[] arr, int n)
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
        public int ContiguousMaxSubArrayKadan_mostOptimize(int[] nums)
        {
            if (nums.Length == 0) return int.MinValue;
            int currSum = nums[0], maxSum = nums[0];

            for (int i = 1; i < nums.Length; i++)
            {
                currSum = Math.Max(nums[i], currSum + nums[i]);
                maxSum = Math.Max(maxSum, currSum);
            }
            return maxSum;
        }
    }
}
