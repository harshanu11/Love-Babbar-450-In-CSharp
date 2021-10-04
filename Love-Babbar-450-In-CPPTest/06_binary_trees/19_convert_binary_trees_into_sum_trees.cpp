/*
    link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

    sol: https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
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
class convert_binary_trees_into_sum_trees
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    // Convert a given tree to a tree where 
    // every node contains sum of values of 
    // nodes in left and right subtrees in the original tree
    int sum(nodeBT* node) {

        // base case
        if (node == NULL) return 0;

        // currData before changing
        int currData = node->data;

        // Recursively call for left and
        // right subtrees and store the sum as 
        // new value of this node 
        int lSum = sum(node->left);
        int rSum = sum(node->right);

        node->data = lSum + rSum;

        // Return the sum of values of nodes
        // in left and right subtrees and 
        // old_value of this node
        return (node->data + currData);
    }
    void toSumTree(nodeBT* node)
    {
        // Your code here
        sum(node);
    }

};


