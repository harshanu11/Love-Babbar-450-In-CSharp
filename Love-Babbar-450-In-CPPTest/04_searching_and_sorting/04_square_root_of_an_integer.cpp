/*
    link: https://practice.geeksforgeeks.org/problems/count-squares3649/1
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>

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
    note: said "less than N"
    TC: O(1)
*/
int countSquares(int N) {

    int ans = sqrt(N - 1);

    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(sqrt(n-1))
*/
int countSquares2(int N) {
        // code here
    int i = 1, count = 0;
    while ((i * i) < N) i++;
    return i - 1;
}
