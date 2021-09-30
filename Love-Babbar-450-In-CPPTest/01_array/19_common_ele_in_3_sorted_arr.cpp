/*
    link: https://practice.geeksforgeeks.org/problems/common-elements1132/1
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(commonElementsRevrseTest)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
vector <int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    set<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3) {
        if (a[i] == b[j] && a[i] == c[k]) {
            ans.insert(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j] || a[i] < c[k]) i++;
        else if (b[j] < a[i] || b[j] < c[k]) j++;
        else if (c[k] < b[j] || c[k] < a[i]) k++;
    }
    vector<int> nn;
    for (auto ele : ans) {
        nn.push_back(ele);
    }
    return nn;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// alternate solution (improved)
vector <int> commonElements1(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;

    vector <int> res;
    int last = INT_MIN;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && A[i] == C[k] && A[i] != last)
        {
            res.push_back(A[i]);
            last = A[i];
            i++;
            j++;
            k++;
        }
        else if (min({ A[i], B[j], C[k] }) == A[i]) i++;
        else if (min({ A[i], B[j], C[k] }) == B[j]) j++;
        else k++;
    }
    return res;
}