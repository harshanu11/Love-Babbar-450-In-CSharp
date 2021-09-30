/*
    link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

    sol: https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
    for different approach
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(doUnionTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
int doUnion(int a[], int n, int b[], int m) {
    set<int> s;
    for (int i = 0;i < n;i++) s.insert(a[i]);
    for (int i = 0;i < m;i++) s.insert(b[i]);
    return s.size();
}

int doIntersection(int a[], int n, int b[], int m) {
    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0, ans = 0;

    while (i <= j) {
        if (a[i] == b[j]) {
            ans++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return ans;
}

