/*
    link: https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/

    postorder: left->right->root
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
class postorder_traversal_recursion_itertion {


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

    // Recursive function to perform postorder traversal on the tree
    void postorder(nodeBT* root)
    {
        // if the current node is empty
        if (root == nullptr) {
            return;
        }

        // Traverse the left subtree
        postorder(root->left);

        // Traverse the right subtree
        postorder(root->right);

        // Display the data part of the root (or current node)
        cout << root->data << " ";
    }


    int main6()
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

        postorder(root);

        return 0;
    }






    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        iterative solution
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

    // Iterative function to perform postorder traversal on the tree
    void postorderIterative(nodeBT* root)
    {
        // create an empty stack and push the root node
        stack<nodeBT*> s;
        s.push(root);

        // create another stack to store postorder traversal
        stack<int> out;

        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and push the data into the output stack
            nodeBT* curr = s.top();
            s.pop();

            out.push(curr->data);

            // push the left and right child of the popped node into the stack
            if (curr->left) {
                s.push(curr->left);
            }

            if (curr->right) {
                s.push(curr->right);
            }
        }

        // print postorder traversal
        while (!out.empty())
        {
            cout << out.top() << " ";
            out.pop();
        }
    }


    int main7()
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

        postorderIterative(root);

        return 0;
    }

};

