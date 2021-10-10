/*
    link: https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
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
/*
    TC: O(N)
*/
//Function to find the minimum element in the given BST.
//int minValue1(nodeBT* root)
//{
//    // base case
//    if (root == NULL)
//        return -1;
//
//    struct nodeBT* current = root;
//
//    //leftmost node is minimum so we move in BST till left node is not NULL.
//    while (current->left != NULL) {
//        current = current->left;
//    }
//    //returning the data at leftmost node.
//    return(current->data);
//}
//
//
//
//// for max value (same as above)
//int maxValue1(nodeBT* root)
//{
//    // base case
//    if (root == NULL)
//        return -1;
//
//    struct nodeBT* current = root;
//
//    // rightmost node is maximum so we move in BST till right node is not NULL.
//    while (current->right != NULL) {
//        current = current->right;
//    }
//    // returning the data at rightmost node.
//    return(current->data);
//}