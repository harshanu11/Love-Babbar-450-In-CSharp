/*
    link: https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
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
    By splitting the array
    TC: O(N^2)
*/
nodeBT* constructTreeUtil(int pre[], int* preIndex, int low,
    int high, int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;

    // The first nodeBT in preorder traversal is root. So take
    // the nodeBT at preIndex from pre[] and make it root, and
    // increment preIndex
    nodeBT* root=  NULL;// = nodeBT(pre[*preIndex]);
    //root = nodeBT(pre[*preIndex]);
    *preIndex = *preIndex + 1;

    // If the current subarry has only one element, no need
    // to recur
    if (low == high)
        return root;

    // Search for the first element greater than root
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;

    // Use the index of element found in preorder to divide
    // preorder array in two parts. Left subtree and right
    // subtree
    root->left = constructTreeUtil(pre, preIndex, *preIndex,
        i - 1, size);
    root->right
        = constructTreeUtil(pre, preIndex, i, high, size);

    return root;
}

// The main function to construct BST from given preorder
// traversal. This function mainly uses constructTreeUtil()
nodeBT* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,
        size);
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    By using range
    TC: O(N)
*/
nodeBT* constructTreeUtil(int pre[], int* preIndex, int key,
    int min, int max, int size)
{
    // Base case
    if (*preIndex >= size)
        return NULL;

    nodeBT* root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max) {
        // Allocate memory for root of this
        // subtree and increment *preIndex
       // root = nodeBT(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size) {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such nodeBT
            // will be root of left subtree.
            root->left = constructTreeUtil(pre, preIndex,
                pre[*preIndex],
                min, key, size);
        }
        if (*preIndex < size) {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such nodeBT
            // will be root of right subtree.
            root->right = constructTreeUtil(pre, preIndex,
                pre[*preIndex],
                key, max, size);
        }
    }

    return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
nodeBT* constructTree1(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0],
        INT_MIN, INT_MAX, size);
}