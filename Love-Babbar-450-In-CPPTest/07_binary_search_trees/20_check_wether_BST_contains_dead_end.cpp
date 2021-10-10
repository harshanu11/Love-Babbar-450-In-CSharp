/*
    link: https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

    sol: https://www.geeksforgeeks.org/check-whether-bst-contains-dead-end-not/
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
    using hashmap
    TC: O(N)
*/
// C++ program check weather BST contains
// dead end or not

using namespace std;

//// A BST node
//struct nodeBT
//{
//    int data;
//    struct nodeBT* left, * right;
//};

// A utility function to create a new node
nodeBT* newNode14(int data)
{
    nodeBT* temp = new nodeBT;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new nodeBT
with given key in BST */
struct nodeBT* insert1(struct nodeBT* node, int key)
{
    /* If the tree is empty, return a new nodeBT */
    if (node == NULL) return newNode14(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert1(node->left, key);
    else if (key > node->data)
        node->right = insert1(node->right, key);

    /* return the (unchanged) nodeBT pointer */
    return node;
}

// Function to store all node of given binary search tree
void storeNodes(nodeBT* root, unordered_set<int>& all_nodes,
    unordered_set<int>& leaf_nodes)
{
    if (root == NULL)
        return;

    // store all node of binary search tree
    all_nodes.insert(root->data);

    // store leaf node in leaf_hash
    if (root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }

    // recur call rest tree
    storeNodes(root->left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

// Returns true if there is a dead end in tree,
// else false.
bool isDeadEnd(nodeBT* root)
{
    // Base case
    if (root == NULL)
        return false;

    // create two empty hash sets that store all
    // BST elements and leaf nodes respectively.
    unordered_set<int> all_nodes, leaf_nodes;

    // insert1 0 in 'all_nodes' for handle case
    // if bst contain value 1
    all_nodes.insert(0);

    // Call storeNodes function to store all BST nodeBT
    storeNodes(root, all_nodes, leaf_nodes);

    // Traversal leaf node and check Tree contain
    // continuous sequence of
    // size tree or Not
    for (auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++)
    {
        int x = (*i);

        // Here we check first and last element of
        // continuous sequence that are x-1 & x+1
        if (all_nodes.find(x + 1) != all_nodes.end() &&
            all_nodes.find(x - 1) != all_nodes.end())
            return true;
    }

    return false;
}

// Driver program
int main36()
{
/*	 8
    / \
    5 11
    / \
    2 7
    \
    3
    \
        4 */
    nodeBT* root = NULL;
    root = insert1(root, 8);
    root = insert1(root, 5);
    root = insert1(root, 2);
    root = insert1(root, 3);
    root = insert1(root, 7);
    root = insert1(root, 11);
    root = insert1(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
