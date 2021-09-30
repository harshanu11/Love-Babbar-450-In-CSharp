/*
    link: https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1#
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

        TEST_METHOD(minFlipsTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
int minFlips(string s)
{
    // your code here
    int ans1 = 0, ans2 = 0;


    for (int i = 0;i < s.size();i++) {
        // for 1010101....
        if (i % 2 == 0 && s[i] != '1' || i % 2 && s[i] != '0') ans1++;
        // for 0101010...
        if (i % 2 == 0 && s[i] != '0' || i % 2 && s[i] != '1') ans2++;
    }
    return min(ans1, ans2);
}