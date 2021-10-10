/*
    link: https://www.spoj.com/problems/GCJ101BB/

    video: https://youtu.be/vrRWIbhGK7o
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    // TEST_CLASS(BTSort)
    // {
    // public:

    //     TEST_METHOD(Test)
    //     {
    //         std::string charM = "harhs";
    //         int age = 14;
    //         age = 55;
    //         std::string lastName = "<<charM <<singh";

    //     }
    // };
}
using namespace std;
#define endl "\n"

int main56()
{
    long long int t, j;
    cin >> t;
    for (j = 1;j <= t;++j)
    {
        long long int n, k, b, time;
        cin >> n >> k >> b >> time;

        long long int x[5], v[5], i;
        for (i = 0;i < n;++i)
            cin >> x[i];

        for (i = 0;i < n;++i)
            cin >> v[i];

        int count = 0, swaps = 0, penalty = 0;
        for (i = n - 1;i >= 0;--i)
        {
            int distance_needed = b - x[i];
            int distance_possible = v[i] * time;

            // chick will be able to reach barn
            if (distance_possible >= distance_needed)
            {
                count++;
                // if (penalty > 0)
                swaps += penalty;
            }
            // chick will not be able to reach
            else
                // hence penalty increases
                penalty++;

            if (count >= k)
                break;
        }

        if (count >= k)
            cout << "Case #" << j << ": " << swaps << endl;

        else
            cout << "Case #" << j << ": " << "IMPOSSIBLE" << endl;
    }
    return 0;
}
