/*
    link: https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
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

        TEST_METHOD(isPalindromTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
bool isPalindrom(int n) {
    string a = to_string(n);
    int i = 0, j = a.size() - 1;
    while (i <= j) {
        if (a[i] != a[j]) return false;
        i++;
        j--;
    }
    return true;
}
int PalinArray(int a[], int n)
{  //add code here.
    for (int i = 0;i < n;i++) {
        if (!isPalindrom(a[i])) return 0;
    }
    return 1;
}