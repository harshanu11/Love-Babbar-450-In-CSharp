/*
    link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

    sol: https://www.geeksforgeeks.org/check-leaves-level/
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
class check_if_all_leaf_node_are_at_same_level
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using recursion
        TC: O(N)
    */
    /* Recursive function which checks whether
    all leaves are at same level */
    bool checkUtil(struct nodeBT* root,
        int level, int* leafLevel)
    {
        // Base case
        if (root == NULL) return true;

        // If a leaf nodeBT is encountered
        if (root->left == NULL &&
            root->right == NULL)
        {
            // When a leaf nodeBT is found
            // first time
            if (*leafLevel == 0)
            {
                *leafLevel = level; // Set first found leaf's level
                return true;
            }

            // If this is not first leaf nodeBT, compare
            // its level with first leaf's level
            return (level == *leafLevel);
        }

        // If this nodeBT is not leaf, recursively
        // check left and right subtrees
        return checkUtil(root->left, level + 1, leafLevel) &&
            checkUtil(root->right, level + 1, leafLevel);
    }

    /* The main function to check
    if all leafs are at same level.
    It mainly uses checkUtil() */
    bool check(struct nodeBT* root)
    {
        int level = 0, leafLevel = 0;
        return checkUtil(root, level, &leafLevel);
    }





    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using iteration
        TC: O(N)
    */
    // return true if all leaf nodes are
    // at same level, else false
    int checkLevelLeafNode(nodeBT* root)
    {
        if (!root)
            return 1;

        // create a queue for level order traversal
        queue<nodeBT*> q;
        q.push(root);

        int result = INT_MAX;
        int level = 0;

        // traverse until the queue is empty
        while (!q.empty()) {
            int size = q.size();
            level += 1;

            // traverse for complete level
            while (size > 0) {
                nodeBT* temp = q.front();
                q.pop();

                // check for left child
                if (temp->left) {
                    q.push(temp->left);

                    // if its leaf nodeBT
                    if (!temp->left->right && !temp->left->left) {

                        // if it's first leaf nodeBT, then update result
                        if (result == INT_MAX)
                            result = level;

                        // if it's not first leaf nodeBT, then compare
                        // the level with level of previous leaf nodeBT
                        else if (result != level)
                            return 0;
                    }
                }

                // check for right child
                if (temp->right) {
                    q.push(temp->right);

                    // if it's leaf nodeBT
                    if (!temp->right->left && !temp->right->right)

                        // if it's first leaf nodeBT till now,
                        // then update the result
                        if (result == INT_MAX)
                            result = level;

                    // if it is not the first leaf nodeBT,
                    // then compare the level with level
                    // of previous leaf nodeBT
                        else if (result != level)
                            return 0;

                }
                size -= 1;
            }
        }

        return 1;
    }

};

