/*
    link: https://practice.geeksforgeeks.org/problems/sum-tree/1#

    sol: https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
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
class check_if_binary_tree_is_sum_tree_or_not
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        comparing sum everytime
        TC: O(N^2)
    */
    // A utility function to get the sum
    // of values in tree with root as root
    int sum(struct nodeBT* root)
    {
        if (root == NULL)
            return 0;

        return sum(root->left) + root->data +
            sum(root->right);
    }

    // Returns 1 if sum property holds for
    // the given nodeBT and both of its children
    int isSumTree(struct nodeBT* nodeBT)
    {
        int ls, rs;

        // If nodeBT is NULL or it's a leaf
        // nodeBT then return true
        if (nodeBT == NULL ||
            (nodeBT->left == NULL &&
                nodeBT->right == NULL))
            return 1;

        // Get sum of nodes in left and
        // right subtrees
        ls = sum(nodeBT->left);
        rs = sum(nodeBT->right);

        // If the nodeBT and both of its
        // children satisfy the property
        // return 1 else 0
        if ((nodeBT->data == ls + rs) &&
            isSumTree(nodeBT->left) &&
            isSumTree(nodeBT->right))
            return 1;

        return 0;
    }






    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        included sum in the recursion itself and uses extra variable to store the bool value
        TC: O(N)
    */
    int sum(nodeBT* root, bool& ans)
    {
        // if root is null current data is 0;
        if (root == NULL) return 0;

        // if root is leaf nodeBT then just return the current data.
        if (root->left == NULL && root->right == NULL) return root->data;

        int ls = sum(root->left, ans);
        int rs = sum(root->right, ans);

        // if its not sum tree set ans false
        if (root->data != ls + rs) ans = false;

        // return sum of children + current data itself
        return ls + root->data + rs;
    }

    // Returns 1 if sum property holds for
    // the given nodeBT and both of its children
    int isSumTree1(nodeBT* root)
    {
        bool ans = true;
        sum(root, ans);
        return ans;
    }


};
