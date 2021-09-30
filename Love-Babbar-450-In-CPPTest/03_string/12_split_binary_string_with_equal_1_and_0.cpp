/*
    link: https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
*/
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(StringClass)
    {
    public:

        TEST_METHOD(Test)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
int split(string stringToSplit, int n) {
    int arr[5];

    int count = 0;

    for (int i = 0;i < n;i++) {
        if (stringToSplit[i] == '0') arr[i] = -1;
        else arr[i] = 1;
        if (i) arr[i] += arr[i - 1];

        if (arr[i] == 0) count++;
    }

    return count;
}


// ----------------------------------------------------------------------------------------------------------------------- //
int maxSubStr(string str, int n)
{

    // To store the count of 0s and 1s
    int count0 = 0, count1 = 0;

    // To store the count of maximum
    // substrings str can be divided into
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            cnt++;
        }
    }

    // It is not possible to
    // split the string
    if (count0 != count1) {
        return -1;
    }

    return cnt;
}
