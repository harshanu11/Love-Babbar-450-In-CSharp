/*
    link: https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#

    sol: https://www.geeksforgeeks.org/smallest-number-least-n-trailing-zeroes-factorial/

    logic: Trailing 0s in x! = Count of 5s in prime factors of x! =
             floor(x/5) + floor(x/25) + floor(x/125) + ....
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
bool check(int p, int n)
{
    int temp = p, count = 0, f = 5;
    while (f <= temp)
    {
        count += temp / f;
        f = f * 5;
    }
    return (count >= n);
}


int findNum(int n)
{
// If n equal to 1, return 5.
// since 5! = 120.
    if (n == 1)
        return 5;

    // Initalising low and high for binary
    // search.
    int low = 0;
    int high = 5 * n;

    // Binary Search.
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        // Checking if mid's factorial contains
        // n trailing zeroes.
        if (check(mid, n))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}