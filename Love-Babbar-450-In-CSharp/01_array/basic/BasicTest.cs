using System.Collections.Generic;
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
            subArray(nums);
            AllContiguousPossibleSubArray(new int[] { 1, 2, 3 });
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
        List<List<int>> vs2 = new List<List<int>>();
        public void subArray(int[] n)
        {
            for (int i = 0; i < n.Length; i++)
            {
                for (int j = i; j < n.Length; j++)
                {
                    List<int> temp = new List<int>();
                    for (int k = i; k <= j; k++)
                        temp.Add(n[k]);
                    vs2.Add(temp);
                }
            }
        }
    }
}
