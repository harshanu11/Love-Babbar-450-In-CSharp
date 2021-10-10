/*
    link (insertion node): https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

    sol (find and insertion): https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
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
    using recursion
    TC: O(log N)
*/
// C++ function to search a given key in a given BST
nodeBT* search(nodeBT* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

        // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

        // Key is smaller than root's key
    return search(root->left, key);
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    insert a node in BST
    TC: O(log N)    // if its not skewed tree
        O(N)        // it skewed tree
*/
// Insert function definition.
nodeBT* Insert(nodeBT* root, int key)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new nodeBT(key);
    }

    // Insert data.
    if (key > root->data)
    {
        // Insert right node data, if the 'key'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, key);
    }
    else
    {
        // Insert left node data, if the 'key'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, key);
    }
    // Return 'root' node, after insertion.
    return root;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using iteration
    TC: O(log N) not skewed
        O(N) for skewed
*/
void insert(nodeBT* root, int key) {
    nodeBT* node = new nodeBT(key);
    if (root == NULL) {
        root = node;
        return;
    }


    nodeBT* prev = NULL;
    nodeBT* temp = root;
    while (temp != NULL) {
        if (temp->data > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < key) {
            prev = temp;
            temp = temp->right;
        }
    }

    if (prev->data > key) prev->left = node;
    else prev->right = node;
}