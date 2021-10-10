/*
    link: https://leetcode.com/problems/delete-node-in-a-bst/

    video: https://youtu.be/5_AZcOOc-kM
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


// ----------------------------------------------------------------------------------------------------------------------- //
nodeBT* deleteNode(nodeBT* root, int key) {
    // base case
    if (!root) return NULL;

    // if value of root matches with the key
    if (root->data == key) {

        // if there is no right child then simply attach root's parent with root's child
        if (!root->right) {
            nodeBT* left = root->left;
            delete root;
            return left;
        }
        // if there is no left child then simply attach root's parent with root's child
        else if (!root->left) {
            nodeBT* right = root->right;
            delete root;
            return right;
        }
        // then swap with the right-subtrees' smallest child with curr-value, also BST won't change (trace it!)
        // alternative way we can also swap left-subtrees' greatest child with curr-value, still BST won't change
        else {
            nodeBT* right = root->right;
            while (right->left) {
                right = right->left;
            }
            swap(root->data, right->data);
        }
    }

    // get deleted and arranged root from the recursion
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}
