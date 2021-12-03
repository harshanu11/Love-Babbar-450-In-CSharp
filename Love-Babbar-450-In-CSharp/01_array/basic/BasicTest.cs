using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array.basic
{
    public class BasicTest
    {
        [Fact]
        public void Test()
        {
            //var nums = new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            var nums = new int[] { -2, -2 };
            
        }
        // AllContiguousPossibleSubArray count = n
        public void AllContiguousPossibleSubArray(int[] nums)
        {
            List<string> vs = new List<string>();
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i; j < nums.Length; j++)
                {
                    string s = "";
                    for (int k = i; k < nums.Length; k++)
                    {
                        s += "," + nums[j];
                    }
                    vs.Add(s);
                }
            }
        }
    }
}
