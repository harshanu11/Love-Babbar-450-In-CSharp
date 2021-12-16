using System.Collections.Generic;
using Xunit;
// devide and concore
//https://leetcode.com/problems/maximum-subarray/
// sliding window 
namespace ConsoleTest
{
    public class ConsoleTest
    {
        [Fact]
        public void reverse_arrayTest()
        {
            var nums = new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            ContainsNearbyDuplicate(new int[] { 99, 99 }, 2);
            ContainsNearbyDuplicate(new int[] { 1, 2, 3, 1 }, 3);
            ContainsNearbyDuplicate(new int[] { 1, 0, 1, 1 }, 1);
            ContainsNearbyDuplicate(new int[] { 1, 2, 3, 1, 2, 3 }, 2);
            //ContainsNearbyDuplicate1(new int[] { 1, 2, 3, 1, 2, 3 }, 2);
            //var nums = new int[] { -2, -2 };
        }
        //https://leetcode.com/problems/contains-duplicate-ii/
        public bool ContainsNearbyDuplicate(int[] nums, int k)
        {
            Dictionary<int, int> hashMap = new Dictionary<int, int>();
            for (int i = 0; i< nums.Length; i++)
            {
                if (hashMap.ContainsKey(nums[i]) && i-hashMap[nums[i]]<=k)
                {
                    return true;
                }
                hashMap[nums[i]] = i;

            }

            return false;
        }
    }

}
