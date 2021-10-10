/*
    link: https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/

    trees can be traversed:
        depth-first order: preorder, inorder, postorder
        breadth-first order: level order traversal

    inorder: left->root->right
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
class inorder_traversal_recursion_itertion
{

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        recursive solution
        TC: O(N), n is the no. of nodes
        SC: O(1),  if we neglect implicit call stack neither it will be O(N-1)=>O(N) in worst case.
    */

    // Data structure to store a binary tree node
    //struct nodeBT
    //{
    //    int data;
    //    nodeBT* left, * right;

    //    nodeBT(int data)
    //    {
    //        this->data = data;
    //        this->left = this->right = nullptr;
    //    }
    //};

    // Recursive function to perform inorder traversal on the tree
    //void inorder(nodeBT* root)
    //{
    //    // return if the current node is empty
    //    if (root == nullptr) {
    //        return;
    //    }

    //    // Traverse the left subtree
    //    inorder(root->left);

    //    // Display the data part of the root (or current node)
    //    cout << root->data << " ";

    //    // Traverse the right subtree
    //    inorder(root->right);
    //}

    int main3()
    {
        /* Construct the following tree
                   1
                 /   \
                /     \
               2       3
              /      /   \
             /      /     \
            4      5       6
                  / \
                 /   \
                7     8
        */

        nodeBT* root = new nodeBT(1);
        root->left = new nodeBT(2);
        root->right = new nodeBT(3);
        root->left->left = new nodeBT(4);
        root->right->left = new nodeBT(5);
        root->right->right = new nodeBT(6);
        root->right->left->left = new nodeBT(7);
        root->right->left->right = new nodeBT(8);

        //inorder(root);

        return 0;
    }




    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        iterative solution

        here we have used stack
    */

    // Data structure to store a binary tree node
    //struct nodeBT
    //{
    //    int data;
    //    nodeBT* left, * right;

    //    nodeBT(int data)
    //    {
    //        this->data = data;
    //        this->left = this->right = nullptr;
    //    }
    //};

    // Recursive function to perform inorder traversal on the tree
    //void inorder(nodeBT* root)
    //{
    //    // return if the current node is empty
    //    if (root == nullptr) {
    //        return;
    //    }

    //    // Traverse the left subtree
    //    inorder(root->left);

    //    // Display the data part of the root (or current node)
    //    cout << root->data << " ";

    //    // Traverse the right subtree
    //    inorder(root->right);
    //}

    int main2()
    {
        /* Construct the following tree
                   1
                 /   \
                /     \
               2       3
              /      /   \
             /      /     \
            4      5       6
                  / \
                 /   \
                7     8
        */

        nodeBT* root = new nodeBT(1);
        root->left = new nodeBT(2);
        root->right = new nodeBT(3);
        root->left->left = new nodeBT(4);
        root->right->left = new nodeBT(5);
        root->right->right = new nodeBT(6);
        root->right->left->left = new nodeBT(7);
        root->right->left->right = new nodeBT(8);

        //inorder(root);

        return 0;
    }

};

