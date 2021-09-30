/*
    link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

    sol: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ----------------------------------------------------------------------------------------------------------------------- //
void recur(vector<string>& ans, string s, int l, int r)
{
    // Base case
    if (l == r) ans.push_back(s);
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(ans[l], ans[i]);

            // Recursion called
            recur(ans,"", l + 1, r);

            //backtrack
            swap(ans[l], ans[i]);
        }
    }
}

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(StringClass)
    {
    public:

        TEST_METHOD(recurTest)
        {
            string S = "ABC";
            vector<string> ans;
            recur(ans, S, 0, S.size() - 1);
            sort(ans.begin(), ans.end());
        }
    };
}