/*
    link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

    for detailed explanation as well as other solutions: DP/31_print_longest...
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(StringClass)
    {
    public:

        TEST_METHOD(longestPalinTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
string longestPalin(string s)
{
    int low, high, maxLen = 1, start = 0, len = s.size();

    for (int i = 1;i < len;i++) {
        // for even length
        // fixing the point i and i+1.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--;
            high++;
        }

        // for odd length 
        // fixing the point i.
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, maxLen);
}