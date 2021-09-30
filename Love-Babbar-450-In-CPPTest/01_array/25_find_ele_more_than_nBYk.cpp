/*
    link: https://practice.geeksforgeeks.org/problems/count-element-occurences/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// using count method
#include <vcruntime_string.h>
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
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
int countOccurence(int arr[], int n, int k) {
    long long range = 1e6 + 7;
    long long cnt[5];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0;i < n;i++) {
        cnt[arr[i]]++;
    }

    int global = 0;
    for (int i = 0;i < range;i++) {
        if (cnt[i] && cnt[i] > n / k) global++;
    }

    return global;
}


// ----------------------------------------------------------------------------------------------------------------------- //
// using hashig
void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k;

      // unordered_map initialization
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

      // Traversing the map
    for (auto i : freq)
    {

        // Checking if value of a key-value pair
        // is greater than x (where x=n/k)
        if (i.second > x)
        {

            // Print the key of whose value
            // is greater than x
            cout << i.first << endl;
        }
    }
}
