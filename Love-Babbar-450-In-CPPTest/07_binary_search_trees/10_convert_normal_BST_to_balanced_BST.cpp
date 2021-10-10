/*
    link: https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/
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
// C++ program to convert a left unbalanced BST to
// a balanced BST


//struct nodeBT
//{
//    int data;
//    nodeBT* left, * right;
//};

/* This function traverse the skewed binary tree and
stores its nodes pointers in vector nodes[] */
void storeBSTNodes(nodeBT* root, vector<nodeBT*>& nodes)
{
    // Base case
    if (root == NULL)
        return;

    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
nodeBT* buildTreeUtil(vector<nodeBT*>& nodes, int start,
    int end)
{
    // base case
    if (start > end)
        return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end) / 2;
    nodeBT* root = nodes[mid];

    /* Using index in Inorder traversal, construct
    left and right subtress */
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);

    return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
nodeBT* buildTree(nodeBT* root)
{
    // Store nodes of given BST in sorted order
    vector<nodeBT*> nodes;
    storeBSTNodes(root, nodes);

    // Constucts BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n - 1);
}

// Utility function to create a new node
//nodeBT* newNode(int data)
//{
//    nodeBT* node = new nodeBT;
//    node->data = data;
//    node->left = node->right = NULL;
//    return (node);
//}

/* Function to do preorder traversal of tree */
void preOrder(nodeBT* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// Driver program
//int main()
//{
//    /* Constructed skewed binary tree is
//                10
//            /
//            8
//            /
//            7
//        /
//        6
//        /
//        5 */
//
//    nodeBT* root = newNode(10);
//    root->left = newNode(8);
//    root->left->left = newNode(7);
//    root->left->left->left = newNode(6);
//    root->left->left->left->left = newNode(5);
//
//    root = buildTree(root);
//
//    printf("Preorder traversal of balanced "
//        "BST is : \n");
//    preOrder(root);
//
//    return 0;
//}
