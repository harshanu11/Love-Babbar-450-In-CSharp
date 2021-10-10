/*
    link: https://www.spoj.com/problems/EKO/

    video: https://youtu.be/tkoucfh10SI
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
/*
    using binary search

    TC: O(n logn)
    SC: O(1)
*/

// return amount of wood will be cutted for the given height of machine
long total_wood(vector<long long>& h, int n, int machine_height) {
    long wood = 0;
    for (int i = 0;i < n;i++) {
        if (h[i] > machine_height) wood += h[i] - machine_height;
    }
    return wood;
}

void solveKEO() {
    long long n, m;
    cin >> n >> m;

    vector<long long> h(n), res(n);

    long mx = 100000;// LONG_LONG_MIN;
    for (int i = 0;i < n;i++) {
        cin >> h[i];
        //mx = max(h[i], mx);
    }

    // we will implement binary_search for 0 height to max height
    long l = 0, r = mx;
    long ans = 0;
    while (l <= r) {
        // we will find mid and will get wood cutted
        long mid = l + (r - l) / 2;

        //debug(mid);
        long wood = total_wood(h, n, mid);

        // if wood cutted is of exact amount then ans = mid;
        if (wood == m) {
            ans = mid;
            break;
        }
        // if wood cutted is less then we will decrease the height of the machine.
        else if (wood < m) {
            r = mid - 1;
        }
        // if wood cutted is more than enough then we will store ans as well as increase height of machine.
        else {
            ans = max(ans, mid);
            l = mid + 1;
        }
    }
    cout << ans << endl;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using sorting

    TC: O(N logN)
    SC: O(N)
*/
void solve3() {
    long long n, m;
    cin >> n >> m;

    vector<long long> h(n), res(n);
    for (int i = 0;i < n;i++) cin >> h[i];

    // sort the height
    sort(h.begin(), h.end());

    // cutting at the height of max is 0.
    res[n - 1] = 0;
    int high = n - 1;
    for (int i = high - 1;i >= 0;i--) {
        // this mathematical equation will store the wood will be cutted at curr. height
        res[i] = (high - i) * (h[i + 1] - h[i]) + res[i + 1];
    }

    int r = high;
    // traverse till the total wood is less than required
    while (r >= 0 && res[r] < m) r--;

    if (res[r] == m) cout << h[r] << endl;
    else {
        // here wood will be more than enough hence increase the height and decrease the wood.
        long long ans = h[r] + (res[r] - m) / (high - r);
        cout << ans << endl;
    }
}
