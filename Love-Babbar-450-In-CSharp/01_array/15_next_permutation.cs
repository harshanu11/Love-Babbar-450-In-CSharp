using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _15_next_permutation
    {
        /*
            link: https://leetcode.com/problems/next-permutation/

            video: https://www.youtube.com/watch?v=LuLCLgMElus

        Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

            If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
            
            The replacement must be in place and use only constant extra memory.
            
                    Example 1:
            
            Input: nums = [1,2,3]
            Output: [1,3,2]
            Example 2:
            
            Input: nums = [3,2,1]
            Output: [1,2,3]
            Example 3:
            
            Input: nums = [1,1,5]
            Output: [1,5,1]
            Example 4:
            
            Input: nums = [1]
            Output: [1]
        */
        [Fact] public void Test() { }
    }
}
/*
    link: https://leetcode.com/problems/next-permutation/

    video: https://www.youtube.com/watch?v=LuLCLgMElus
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//void nextPermutation(vector<int>& nums)
//{
//    int siz = nums.size();
//    int i = siz - 2;

//    // find point where after which whole sub-array is descending.
//    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
//    // so now as rest of the sub array is descending we have to increase the current index.
//    if (i >= 0)
//    {
//        int j = siz - 1;

//        // find the larger element from the end to swap with.
//        while (nums[j] <= nums[i]) j--;
//        swap(nums[j], nums[i]);
//    }

//    reverse(nums.begin() + i + 1, nums.end());
//}
