/*
    link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#

    sol: https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
    sol: https://www.geeksforgeeks.org/right-view-binary-tree-using-queue/
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
class right_view_of_tree
{

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using recursion
    */
    // C++ program to print right view of Binary Tree

    //struct nodeBT
    //{
    //    int data;
    //    struct nodeBT* left, * right;
    //};

    // A utility function to
    // create a new Binary Tree nodeBT
    //struct nodeBT* newNode(int item)
    //{
    //    struct nodeBT* temp = (struct nodeBT*)malloc(
    //        sizeof(struct nodeBT));
    //    temp->data = item;
    //    temp->left = temp->right = NULL;
    //    return temp;
    //}

    // Recursive function to print
    // right view of a binary tree.
    void rightViewUtil(struct nodeBT* root,
        int level, int* max_level)
    {
        // Base Case
        if (root == NULL) return;

        // If this is the last nodeBT of its level
        if (*max_level < level)
        {
            cout << root->data << "\t";
            *max_level = level;
        }

        // Recur for right subtree first,
        // then left subtree
        rightViewUtil(root->right, level + 1, max_level);       // main logic (to iterate right sub-tree first)
        rightViewUtil(root->left, level + 1, max_level);
    }

    // A wrapper over rightViewUtil()
    void rightView(struct nodeBT* root)
    {
        int max_level = 0;
        rightViewUtil(root, 1, &max_level);
    }

    // Driver Code
    int main()
    {
        struct nodeBT* root = level_order_traversal::newNode(1);
        root->left = level_order_traversal::newNode(2);
        root->right = level_order_traversal::newNode(3);
        root->left->left = level_order_traversal::newNode(4);
        root->left->right = level_order_traversal::newNode(5);
        root->right->left = level_order_traversal::newNode(6);
        root->right->right = level_order_traversal::newNode(7);
        root->right->left->right = level_order_traversal::newNode(8);

        rightView(root);

        return 0;
    }






    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using queue
    */
    void printRightView(nodeBT* root)
    {
        if (!root) return;

        queue<nodeBT*> q;
        q.push(root);

        while (!q.empty())
        {
            // number of nodes at current level
            int n = q.size();

            // Traverse all nodes of current level 
            for (int i = 1; i <= n; i++)
            {
                nodeBT* temp = q.front();
                q.pop();

                // Print the right most element 
                // at the level
                if (i == n)
                    cout << temp->data << " ";

                // Add left node to queue
                if (temp->left != NULL)
                    q.push(temp->left);

                // Add right node to queue
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
    }


};
