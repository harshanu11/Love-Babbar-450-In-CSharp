/*
    link: https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

    sol: https://www.geeksforgeeks.org/check-mirror-n-ary-tree/
*/
#include "01_level_order_traversal.cpp"
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    //TEST_CLASS(BTSort)
    //{
    //public:

    //    TEST_METHOD(Test)
    //    {
    //        std::string charM = "harhs";
    //        int age = 14;
    //        age = 55;
    //        std::string lastName = "<<charM <<singh";

    //    }
    //};
}
class check_if_two_trees_are_mirror_or_not
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    // C++ program to check if two n-ary trees are
    // mirror.

    // Function to check given two trees are mirror
    // of each other or not
    int checkMirrorTree(int M, int N, int u1[],
        int v1[], int u2[], int v2[])
    {
        // Map to store nodes of the tree
        unordered_map<int, stack<int>>mp;

        // Traverse first tree nodes
        for (int i = 0; i < N; i++)
        {
            mp[u1[i]].push(v1[i]);
        }

        // Traverse second tree nodes
        for (int i = 0; i < N; i++)
        {
            if (mp[u2[i]].top() != v2[i])
                return 0;
            mp[u2[i]].pop();
        }

        return 1;
    }

    // Driver code
    int main()
    {
        int M = 7, N = 6;

        //Tree 1
        int u1[] = { 1, 1, 1, 10, 10, 10 };
        int v1[] = { 10, 7, 3, 4, 5, 6 };

        //Tree 2
        int u2[] = { 1, 1, 1, 10, 10, 10 };
        int v2[] = { 3, 7, 10, 6, 5, 4 };

        if (checkMirrorTree(M, N, u1, v1, u2, v2))
            cout << "Yes";
        else
            cout << "No";

        return 0;
    }


};


