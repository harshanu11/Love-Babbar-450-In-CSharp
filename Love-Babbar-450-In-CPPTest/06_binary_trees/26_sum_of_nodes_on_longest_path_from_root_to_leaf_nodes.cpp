/*
    link: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    sol: https://www.geeksforgeeks.org/sum-nodes-longest-path-root-leaf-node/
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

class sum_of_nodes_on_longest_path_from_root_to_leaf_nodes
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using recursion
        TC: O(N)
    */
    // recursive function
    void recur(nodeBT* root, int level, int& maxLevel, int sum, int& ans) {
        if (!root) return;

        // update sum with current data
        sum += root->data;

        // if level has increased then update the current ans.
        if (level >= maxLevel) {
            maxLevel = level;
            ans = sum;
        }

        // recursively call both the children
        recur(root->left, level + 1, maxLevel, sum, ans);
        recur(root->right, level + 1, maxLevel, sum, ans);
    }

    int sumOfLongRootToLeafPath(nodeBT* root)
    {
        // variable to maintain value throughout the code
        int ans = 0;
        int maxLevel = 0;


        recur(root, 0, maxLevel, 0, ans);
        return ans;
    }







    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using list
        (just go through the logic... using queue will be almost similar)
    */
    int longestPathLeaf(nodeBT* root) {

        /* structure to store current nodeBT,it's level and sum in the path*/
        struct Element {
            nodeBT* data;
            int level;
            int sum;
        };

        /*
          maxSumLevel stores maximum sum so far in the path
          maxLevel stores maximum level so far
        */
        int maxSumLevel = root->data, maxLevel = 0;

        /* queue to implement level order traversal */

        list<Element> que;
        Element e;

        /* Each element variable stores the current nodeBT, it's level, sum in the path */

        e.data = root;
        e.level = 0;
        e.sum = root->data;

        /* push the root element*/
        que.push_back(e);

        /* do level order traversal on the tree*/
        while (!que.empty()) {

            Element front = que.front();
            nodeBT* curr = front.data;
            que.pop_front();

            /* if the level of current front element is greater than the maxLevel so far then update maxSum*/
            if (front.level > maxLevel) {
                maxSumLevel = front.sum;
                maxLevel = front.level;
            }
            /* if another path competes then update if the sum is greater than the previous path of same height*/
            else if (front.level == maxLevel && front.sum > maxSumLevel)
                maxSumLevel = front.sum;

            /* push the left element if exists*/
            if (curr->left) {
                e.data = curr->left;
                e.sum = e.data->data;
                e.sum += front.sum;
                e.level = front.level + 1;
                que.push_back(e);
            }
            /*push the right element if exists*/
            if (curr->right) {
                e.data = curr->right;
                e.sum = e.data->data;
                e.sum += front.sum;
                e.level = front.level + 1;
                que.push_back(e);
            }
        }

        /*return the answer*/
        return maxSumLevel;
    }

};


