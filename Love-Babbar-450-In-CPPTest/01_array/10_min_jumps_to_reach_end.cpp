/*
    link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(minJumpsRevrseTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
int minJumps(int arr[], int n) {

    // base condition
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1;i < n;i++) {
        if (i == n - 1) return jump;

        maxReach = max(maxReach, arr[i] + i);

        step--;     // do step-- until its 0 as we r sure we can reach till that end but parallely keep updating maxReach

        if (step == 0) {
            jump++;

            if (i >= maxReach) return -1;

            step = maxReach - i;    // here we got help of that maxReach
            // this shows that why iterating all the elements till now how max. farthest we can go and we will set step as such.
        }
    }
    return -1;
}