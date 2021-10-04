/*
    link: https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
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

class argest_subtree_sum_in_tree
{

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        Time Complexity: O(n), where n is number of nodes.
        Auxiliary Space: O(n), function call stack size.
    */
    // C++ program to find largest subtree
    // sum in a given binary tree.

    // Structure of a tree node.
    struct nodeBT {
        int key;
        nodeBT* left, * right;
    };

    // Function to create new tree node.
    nodeBT* newNode(int key)
    {
        nodeBT* temp = new nodeBT;
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Helper function to find largest
    // subtree sum recursively.
    int findLargestSubtreeSumUtil(nodeBT* root, int& ans)
    {
        // If current node is null then
        // return 0 to parent node.
        if (root == NULL)
            return 0;

        // Subtree sum rooted at current node.
        int currSum = root->key + findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right, ans);

        // Update answer if current subtree
        // sum is greater than answer so far.
        ans = max(ans, currSum);

        // Return current subtree sum to
        // its parent node.
        return currSum;
    }

    // Function to find largest subtree sum.
    int findLargestSubtreeSum(nodeBT* root)
    {
        // If tree does not exist,
        // then answer is 0.
        if (root == NULL)
            return 0;

        // Variable to store maximum subtree sum.
        int ans = INT_MIN;

        // Call to recursive function to
        // find maximum subtree sum.
        findLargestSubtreeSumUtil(root, ans);

        return ans;
    }

    // Driver function
    int main()
    {
        /*
                1
                / \
                /	 \
            -2	 3
            / \	 / \
            / \ / \
            4	 5 -6	 2
        */

        nodeBT* root = newNode(1);
        root->left = newNode(-2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(-6);
        root->right->right = newNode(2);

        cout << findLargestSubtreeSum(root);
        return 0;
    }


};


