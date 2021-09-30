/*
    link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
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

        TEST_METHOD(rotateTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
void rotate(int arr[], int n)
{
    int temp = arr[n - 1];

    for (int i = n - 1;i > 0;i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}