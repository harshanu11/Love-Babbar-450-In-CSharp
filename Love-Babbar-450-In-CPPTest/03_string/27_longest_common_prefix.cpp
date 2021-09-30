/*
    link: https://leetcode.com/problems/longest-common-prefix/
*/
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(StringClass)
    {
    public:

        TEST_METHOD(Test)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
string longestCommonPrefix(vector<string>& strs) {
    string ans = strs[0];
    int n = strs.size();

    for (int i = 1;i < n;i++) {
        string curr = strs[i];

        // this confirms that we will always have advantage of reducing the ans.
        // neither it will move on.
        if (curr == ans) continue;

        int j = 0;
        // compare till the char matches 
        while (j < min(curr.size(), ans.size()) && curr[j] == ans[j]) j++;
        // ofc new matching string will be less than ans hence update the ans 
        // till the char were matched
        ans = ans.substr(0, j);
    }
    return ans;
}

