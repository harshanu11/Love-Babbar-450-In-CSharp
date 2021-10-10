/*
    link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

    sol: https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
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
    iterative solution
    TC: O(H), H is the height of the tree
*/
struct nodeBT* lca(struct nodeBT* root, int n1, int n2)
{
    while (root != NULL)
    {
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;

            // If both n1 and n2 are greater than root, 
            // then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;

        else break;
    }
    return root;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    recursive solution
    TC: O(H), H is the height of the tree.
*/
nodeBT* lca2(nodeBT* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller
    // than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    // If both n1 and n2 are greater than 
    // root, then LCA lies in right 
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}
