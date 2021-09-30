/*
    link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(SearchSort)
    {
    public:

        TEST_METHOD(find1Test)
        {
            // total ele.
            int n;
            cin >> n;
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            // total rounds 
            int q;
            cin >> q;
            while (q--) {
                // power for current round
                int pow;
                cin >> pow;

                // total sum by killing enemy
                int sum = 0;
                // count of enemy dead by curr power
                int count = 0;

                for (int i = 0; i < n; i++) {
                    if (arr[i] <= pow) sum += arr[i], count++;
                }
                cout << count << " " << sum << endl;
            }

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
using namespace std;
