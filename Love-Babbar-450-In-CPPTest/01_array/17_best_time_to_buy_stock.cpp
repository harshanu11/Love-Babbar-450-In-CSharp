/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    also refer to 26_sell_...twice.cpp
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

        TEST_METHOD(maxProfitRevrseTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int local = 0, global = 0;
    for (int i = 1;i < n;i++) {
        /*
            if the loss is going negative then make it 0 either continue with the profit as higher as possible.
        */
        local = max(0, local += prices[i] - prices[i - 1]);
        global = max(local, global);
    }
    return global;
}
