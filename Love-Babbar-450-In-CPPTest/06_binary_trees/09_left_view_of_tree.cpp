/*
    link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

    sol: https://www.geeksforgeeks.org/print-left-view-binary-tree/
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
class left_view_of_tree
{

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using recursion
    */
    // C++ program to print left view of Binary Tree

    //struct nodeBT
    //{
    //    int data;
    //    struct nodeBT* left, * right;
    //};

    // A utility function to
    // create a new Binary Tree nodeBT
    struct nodeBT* newNode(int item)
    {
        struct nodeBT* temp = (struct nodeBT*)malloc(
            sizeof(struct nodeBT));
        temp->data = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Recursive function to print
    // left view of a binary tree.
    void leftViewUtil(struct nodeBT* root,
        int level, int* max_level)
    {
        // Base Case
        if (root == NULL) return;

        // If this is the first nodeBT of its level
        if (*max_level < level)
        {
            cout << root->data << " ";
            *max_level = level;
        }

        // Recur for left subtree first,
        // then right subtree
        leftViewUtil(root->left, level + 1, max_level);
        leftViewUtil(root->right, level + 1, max_level);

    }

    // A wrapper over leftViewUtil()
    void leftView(struct nodeBT* root)
    {
        int max_level = 0;
        leftViewUtil(root, 1, &max_level);
    }

    // Driver Code
    int main()
    {
        nodeBT* root = level_order_traversal::newNode(10);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(7);
        root->left->right = newNode(8);
        root->right->right = newNode(15);
        root->right->left = newNode(12);
        root->right->right->left = newNode(14);

        leftView(root);

        return 0;
    }






    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using queue
    */
    // C++ program to print left view of
    // Binary Tree


    // A Binary Tree nodeBT
    //struct nodeBT
    //{
    //    int data;
    //    struct nodeBT* left, * right;
    //};

    // Utility function to create a new tree node
    //nodeBT* newNode(int data)
    //{
    //    nodeBT* temp = new nodeBT;
    //    temp->data = data;
    //    temp->left = temp->right = NULL;
    //    return temp;
    //}

    // function to print left view of
    // binary tree
    void printLeftView(nodeBT* root)
    {
        if (!root)
            return;

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

                // Print the left most element
                // at the level
                if (i == 1)
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

    // Driver code
    int main1()
    {
        // Let's construct the tree as
        // shown in example

        nodeBT* root = newNode(10);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(7);
        root->left->right = newNode(8);
        root->right->right = newNode(15);
        root->right->left = newNode(12);
        root->right->right->left = newNode(14);

        printLeftView(root);
    }


};

