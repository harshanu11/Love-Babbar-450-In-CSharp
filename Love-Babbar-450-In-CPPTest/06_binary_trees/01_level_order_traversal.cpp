/*
    link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

    sol: https://www.geeksforgeeks.org/level-order-tree-traversal/
*/

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
    by printing current level

    Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes
        O(n) time where n is the number of nodes in the skewed tree.
        So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).

    Space Complexity: O(n) in worst case. For a skewed tree, printGivenLevel() uses
        O(n) space for call stack. For a Balanced tree, the call stack uses O(log n) space,
        (i.e., the height of the balanced tree).
*/
// Recursive CPP program for level
// order traversal of Binary Tree

/* A binary tree nodeBT has data,
pointer to left child
and a pointer to right child */
class nodeBT
{
public:
    int data;
    nodeBT* left, * right;
    int c = 0;
    int hd;
    nodeBT() {}
    nodeBT(int data) 
    {
        nodeBT* nodeBT;
        nodeBT->data = data;
        nodeBT->left = NULL;
        nodeBT->right = NULL;
    }
};

class level_order_traversal
{
public:
    /* Function protoypes */
    //void printCurrentLevel(nodeBT* root, int level);
    //int height(nodeBT* nodeBT);
    //nodeBT* newNode(int data);

    /* Function to print level
    order traversal a tree*/
    void printLevelOrder(nodeBT* root)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }

    /* Print nodes at a current level */
    void printCurrentLevel(nodeBT* root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
            cout << root->data << " ";
        else if (level > 1)
        {
            printCurrentLevel(root->left, level - 1);
            printCurrentLevel(root->right, level - 1);
        }
    }
    // Function to print the inrder traversal
    void inorder(nodeBT* root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    // A utility function to do inorder traversal of BST
    static void inorder1(struct nodeBT* root, int s)
    {
        if (root != NULL) {
            inorder1(root->left, s);

            if (root->c > (s / 2))
                printf("%d \n", root->data);

            inorder1(root->right, s);
        }
    }

    /* Compute the "height" of a tree -- the number of
        nodes along the longest path from the root nodeBT
        down to the farthest leaf nodeBT.*/
    static int height(nodeBT* nodeBT)
    {
        if (nodeBT == NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(nodeBT->left);
            int rheight = height(nodeBT->right);

            /* use the larger one */
            if (lheight > rheight)
            {
                return(lheight + 1);
            }
            else {
                return(rheight + 1);
            }
        }
    }

    /* Helper function that allocates
    a new nodeBT with the given data and
    NULL left and right pointers. */
    static nodeBT* newNode(int data)
    {
        nodeBT* nodeBT ;
        nodeBT->data = data;
        nodeBT->left = NULL;
        nodeBT->right = NULL;

        return(nodeBT);
    }
    static void preorder(nodeBT* root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using queue
        TC: O(N)
        SC: O(N)
        ---> where n is the number of nodes in the binary trees
    */
    //void printLevelOrder(nodeBT* root)
    //{
    //    // Base Case
    //    if (root == NULL)  return;

    //    // Create an empty queue for level order traversal
    //    queue<nodeBT*> q;

    //    // Enqueue Root and initialize height
    //    q.push(root);

    //    while (q.empty() == false)
    //    {
    //        // Print front of queue and remove it from queue
    //        nodeBT* nodeBT = q.front();
    //        cout << nodeBT->data << " ";
    //        q.pop();

    //        /* Enqueue left child */
    //        if (nodeBT->left != NULL)
    //            q.push(nodeBT->left);

    //        /*Enqueue right child */
    //        if (nodeBT->right != NULL)
    //            q.push(nodeBT->right);
    //    }
    //}
    /* Driver code*/
    int main()
    {
        nodeBT* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);

        cout << "Level Order traversal of binary tree is \n";
        printLevelOrder(root);

        return 0;
    }
};










