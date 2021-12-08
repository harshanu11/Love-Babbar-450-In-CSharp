using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;
// devide and concore
//https://leetcode.com/problems/maximum-subarray/
// sliding window 
//https://leetcode.com/problems/contains-duplicate-ii/
namespace ConsoleTest
{
    public class ConsoleTest
    {
        [Fact]
        public void reverse_arrayTest()
        {
            var nums = new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            ContainsNearbyDuplicate1(new int[] { 99, 99 }, 2);
            //var nums = new int[] { -2, -2 };
        }
        public bool ContainsNearbyDuplicate(int[] nums, int k)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] == nums[j])
                    {
                        if (Math.Abs(i - j) <= k)
                        {
                            return true;
                        }
                        Debug.WriteLine($"{i},{j}");
                    }
                }
            }
            return false;
        }
        public bool ContainsNearbyDuplicate1(int[] nums, int k)
        {
            if (k > nums.Length)
            {

            }
            int flagS = 0;
            for (int i = flagS; i <= k; i++)
            {
                if (k < nums.Length && nums[flagS] == nums[k])
                {
                    if (Math.Abs(i - k) <= k)
                    {
                        return true;
                    }
                }
                else if (i == k && k < nums.Length)
                {
                    flagS++;
                    i = flagS;
                    k++;
                }
                if (k == nums.Length)
                {
                    break;
                }
            }
            return false;
        }
    }

}
