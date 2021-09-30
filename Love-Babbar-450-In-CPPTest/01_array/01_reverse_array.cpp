/*
    link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

    note: array is pass by reference so no need to worry while changing value it will change in original array.
*/
//#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(RevrseTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
void rvereseArray1(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
void rvereseArray(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
}