/*
    link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(trappingWaterTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
// here we keep left max and right max at that point to get how much max water can be hold at current position.
int trappingWater(int arr[], int n) {
    int ans = 0;
    int l[5], r[5];
    l[0] = arr[0];
    r[n - 1] = arr[n - 1];

    for (int i = 1;i < n;i++) {
        l[i] = max(arr[i], l[i - 1]);
    }
    for (int i = n - 2;i >= 0;i--) {
        r[i] = max(arr[i], r[i + 1]);
    }

    for (int i = 1;i < n - 1;i++) {
        ans += max(0, min(l[i], r[i]) - arr[i]);
    }
    return ans;
}