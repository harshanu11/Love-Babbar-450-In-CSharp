/*
    link: https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/

    preorder: root->left->right
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
class preorder_traversal_recursion_itertion
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using recursion
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

    // Recursive function to perform preorder traversal on the tree
    //void preorder(nodeBT* root)
    //{
    //    // if the current node is empty
    //    if (root == nullptr) {
    //        return;
    //    }

    //    // Display the data part of the root (or current node)
    //    cout << root->data << " ";

    //    // Traverse the left subtree
    //    preorder(root->left);

    //    // Traverse the right subtree
    //    preorder(root->right);
    //}


    int main4()
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

       // level_order_traversal::preorder(root);

        return 0;
    }







    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        iterative approach
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

    // Iterative function to perform preorder traversal on the tree
    void preorderIterative(nodeBT* root)
    {
        // return if the tree is empty
        if (root == nullptr)
            return;

        // create an empty stack and push the root node
        stack<nodeBT*> stack;
        stack.push(root);

        // loop till stack is empty
        while (!stack.empty())
        {
            // pop a node from the stack and print it
            nodeBT* curr = stack.top();
            stack.pop();

            cout << curr->data << " ";

            // push the right child of the popped node into the stack
            if (curr->right) {
                stack.push(curr->right);
            }

            // push the left child of the popped node into the stack
            if (curr->left) {
                stack.push(curr->left);
            }

            // the right child must be pushed first so that the left child
            // is processed first (LIFO order)
        }
    }


    int main5()
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

        preorderIterative(root);

        return 0;
    }

};

