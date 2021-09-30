/*
    link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
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

        TEST_METHOD(findMinDiffTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
long long findMinDiff(vector<long long> a, long long n, long long m) {
    // sorted so that we can different window(sub-array) of size m.
    sort(a.begin(), a.end());

    long long ans = a[m - 1] - a[0];    // took first window from 0 to m-1.

    // now we iterate every window(sub-array) and check for the max-min from that range.
    for (int i = 1;i < n - m + 1;i++) {
        ans = min(a[i + m - 1] - a[i], ans);
    }
    return ans;
}