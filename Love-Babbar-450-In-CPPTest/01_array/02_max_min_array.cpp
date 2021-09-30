/*
    link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

    can also be done using several methods, visit link for more methods
*/

#include "CppUnitTest.h"
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    // ----------------------------------------------------------------------------------------------------------------------- //
// O(N)
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(max_min_arrayTest)
        {
            int arr[] = { 1000, 11, 445,
                1, 330, 3000 };
            int arr_size = 6;

            int mx = arr[0];
            int mn = arr[1];

            for (int i = 1; i < arr_size; i++) {
                if (arr[i] > mx) mx = arr[i];
                if (arr[i] < mn) mn = arr[i];
            }
            cout << "MIN: " << mn << " MAX: " << mx;

        }
    };
}

