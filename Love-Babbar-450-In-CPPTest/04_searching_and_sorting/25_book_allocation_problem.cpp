/*
    link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

    video [approach]: https://youtu.be/2JSQIhPcHQg

    ref: 30_painters_partition...
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(SearchSort)
    {
    public:

        TEST_METHOD(find1Test)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
bool isValidBook(int* arr, int n, int k, long long maxTime) {
    long long painters = 1;
    long long t = 0;
    for (long long i = 0;i < n;i++) {
        t += arr[i];
        if (t > maxTime) {
            painters++;
            t = arr[i];
        }
        if (painters > k) return false;
    }
    return true;
}

int findPages(int arr[], int n, int k)
{
    long long lb = 0, ub = 0;
    long long ans = 0;
    for (long long i = 0;i < n;i++) {
        lb = max(lb, (long long)arr[i]);
        ub += arr[i];
    }

    while (lb <= ub) {
        long long mid = (lb + ub) / 2;

        if (isValidBook(arr, n, k, mid)) {
            ans = mid;
            ub = mid - 1;
        }
        else lb = mid + 1;
    }
    return ans;
}
