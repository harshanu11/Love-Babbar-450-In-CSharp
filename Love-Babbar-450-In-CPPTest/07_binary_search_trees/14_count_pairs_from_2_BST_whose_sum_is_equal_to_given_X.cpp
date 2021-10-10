/*
    link: https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
*/
#include "../06_binary_trees/01_level_order_traversal.cpp"
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
    TEST_CLASS(BTSort)
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
/*
    TC: O(N logN)
    SC: O(1)
*/
bool findPair(nodeBT* root, int key) {
    if (!root) return false;

    if (root->data > key) {
        return findPair(root->left, key);
    }
    else if (root->data < key) {
        return findPair(root->right, key);
    }
    else return true;
}

void inorderCheck(nodeBT* root, nodeBT* root2, int x, int& cnt) {
    if (!root || root->data >= x) return;

    if (findPair(root2, x - root->data)) cnt++;

    inorderCheck(root->left, root2, x, cnt);
    inorderCheck(root->right, root2, x, cnt);
}

int countPairs(nodeBT* root1, nodeBT* root2, int x)
{
    int cnt = 0;
    inorderCheck(root1, root2, x, cnt);
    return cnt;
}