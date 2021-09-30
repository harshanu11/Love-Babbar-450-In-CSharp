/*
    link: https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include <map>
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
void common_ele(int mat[5][5], int n, int m) {
    map<int, int> mp;

    // store 1st row in map with 1 occurence
    for (int j = 0;j < m;j++) {
        mp[mat[0][j]] = 1;
    }

    // for every row
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < m;j++) {

            // if the count of ele. is i (means till now it is present in every row) then update with current row count.
            if (mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i + 1;
            }

            // if it is last row and count of the current ele. is n then print it.
            if (i == n - 1 && mp[mat[i][j]] == n) cout << mat[i][j] << " ";
        }
    }
}


namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(Matrix)
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