/*
    link: https://leetcode.com/problems/next-permutation/

    video: https://www.youtube.com/watch?v=LuLCLgMElus
*/
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(nextPermutationRevrseTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
void nextPermutation(vector<int>& nums) {
    int siz = nums.size();
    int i = siz - 2;

    // find point where after which whole sub-array is descending.
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    // so now as rest of the sub array is descending we have to increase the current index.
    if (i >= 0) {
        int j = siz - 1;

        // find the larger element from the end to swap with.
        while (nums[j] <= nums[i]) j--;
        swap(nums[j], nums[i]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}
