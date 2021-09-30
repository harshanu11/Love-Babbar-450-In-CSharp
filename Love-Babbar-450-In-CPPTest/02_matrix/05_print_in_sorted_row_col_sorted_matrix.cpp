/*
    link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
// ----------------------------------------------------------------------------------------------------------------------- //
vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat) {
        // code here
    vector<int> temp;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(), temp.end());

    int k = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            mat[i][j] = temp[k++];
        }
    }
    return mat;
}