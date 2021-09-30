/*
    link: https://www.spoj.com/problems/ANARC05B/

    video: https://youtu.be/w-6YHcGmSxM
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

// ----------------------------------------------------------------------------------------------------------------------- //
using namespace std;

//void io() {
//#ifndef ONLINE_JUDGE
//    freopen("io/i.txt", "r", stdin);
//    freopen("io/o.txt", "w", stdout);
//    freopen("io/e.txt", "w", stderr);
//#endif
//}

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(SearchSort)
    {
    public:

        TEST_METHOD(find1Test)
        {
            //io();
            while (true) {
                int s1 = 0;
                cin >> s1;
                if (s1 == 0) break;

                int a[5];
                for (int i = 0; i < s1; i++) cin >> a[i];



                int s2 = 0;
                cin >> s2;
                int b[5];
                for (int i = 0; i < s2; i++) cin >> b[i];


                int i = 0, j = 0, sum1 = 0, sum2 = 0, ans = 0;

                while (i < s1 && j < s2) {
                    if (a[i] < b[j]) sum1 += a[i++];
                    else if (b[j] < a[i]) sum2 += b[j++];
                    else {
                        ans += max(sum1, sum2) + a[i];
                        i++;
                        j++;
                        sum1 = sum2 = 0;
                    }
                }

                while (i < s1) {
                    sum1 += a[i++];
                }
                while (j < s2) {
                    sum2 += b[j++];
                }
                ans += max(sum1, sum2);
                cout << ans << endl;
            }

        }
    };
}
