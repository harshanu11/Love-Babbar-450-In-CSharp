/*
    link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

    kadane's algorithm
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

        TEST_METHOD(maxSubarraySumTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
int maxSubarraySum(int arr[], int n) {
    n = 5;
    int dp[5];

    dp[0] = max(0, arr[0]);
    int omax = dp[0];
    for (int i = 1;i < n;i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        omax = max(dp[i], omax);
    }
    return omax;
}