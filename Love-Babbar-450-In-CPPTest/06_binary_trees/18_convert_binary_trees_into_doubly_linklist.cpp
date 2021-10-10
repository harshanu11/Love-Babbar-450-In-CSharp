/*
    link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

    sol: https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
    sol: https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
    sol: https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/

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
class convert_binary_trees_into_doubly_linklist
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using recursion
    */
    // A C++ program for in-place
    // conversion of Binary Tree to DLL

    /* A binary tree nodeBT has data,
    and left and right pointers */
    //class nodeBT {
    //public:
    //    int data;
    //    nodeBT* left;
    //    nodeBT* right;
    //};

    /* This is the core function to convert
    Tree to list. This function follows
    steps 1 and 2 of the above algorithm */
    nodeBT* bintree2listUtil(nodeBT* root)
    {
        // Base case
        if (root == NULL)
            return root;

        // Convert the left subtree and link to root
        //if (root->left != NULL) {
        //    // Convert the left subtree
        //    nodeBT* left = bintree2listUtil(root->left);

        //    // Find inorder predecessor. After this loop, left
        //    // will point to the inorder predecessor
        //    for (; left->right != NULL; left = left->right)
        //        ;

        //    // Make root as next of the predecessor
        //    left->right = root;

        //    // Make predecssor as previous of root
        //    root->left = left;
        //}

        //// Convert the right subtree and link to root
        //if (root->right != NULL) {
        //    // Convert the right subtree
        //    nodeBT* right = bintree2listUtil(root->right);

        //    // Find inorder successor. After this loop, right
        //    // will point to the inorder successor
        //    for (right->left != NULL; right = right->left);

        //    // Make root as previous of successor
        //    right->left = root;

        //    // Make successor as next of root
        //    root->right = right;
        //}

        return root;
    }

    // The main function that first calls
    // bintree2listUtil(), then follows step 3
    // of the above algorithm
    nodeBT* bintree2list(nodeBT* root)
    {
        // Base case
        if (root == NULL)
            return root;

        // Convert to DLL using bintree2listUtil()
        root = bintree2listUtil(root);

        // bintree2listUtil() returns root nodeBT of the converted
        // DLL. We need pointer to the leftmost nodeBT which is
        // head of the constructed DLL, so move to the leftmost
        // nodeBT
        while (root->left != NULL)
            root = root->left;

        return (root);
    }

    /* Helper function that allocates a new nodeBT with the
    given data and NULL left and right pointers. */
    //nodeBT* newNode(int data)
    //{
    //    nodeBT* new_node = new nodeBT();
    //    new_node->data = data;
    //    new_node->left = new_node->right = NULL;
    //    return new_node;
    //}

    /* Function to print nodes in a given doubly linked list */
    void printList(nodeBT* nodeBT)
    {
        while (nodeBT != NULL) {
            cout << nodeBT->data << " ";
            nodeBT = nodeBT->right;
        }
    }

    /* Driver code*/
    int main16()
    {
        // Let us create the tree shown in above diagram
        nodeBT* root = newNode(10);
        root->left = newNode(12);
        root->right = newNode(15);
        root->left->left = newNode(25);
        root->left->right = newNode(30);
        root->right->left = newNode(36);

        // Convert to DLL
        nodeBT* head = bintree2list(root);

        // Print the converted list
        printList(head);

        return 0;
    }











    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using head and tail pointer
    */
    // A C++ program for in-place
    // conversion of Binary Tree to DLL

    /* A binary tree nodeBT has data,
    and left and right pointers */
    //class nodeBT {
    //public:
    //    int data;
    //    nodeBT* left;
    //    nodeBT* right;
    //};

    /* This is the core function to convert
    Tree to list.*/
    nodeBT* bintree2listUtil(nodeBT* root, nodeBT** head, nodeBT** tail)
    {
        if (root == NULL)
            return NULL;

        nodeBT* left = root->left;
        nodeBT* right = root->right;

        bintree2listUtil(root->left, head, tail);

        if (*head == NULL) {
            *head = root;
        }

        root->left = *tail;

        if (*tail != NULL) {
            (*tail)->right = root;
        }

        *tail = root;

        bintree2listUtil(root->right, head, tail);

        return root;
    }

    // The main function that first calls
    // bintree2listUtil()
    nodeBT* bintree2list2(nodeBT* root)
    {
        // Base case
        if (root == NULL)
            return root;

        nodeBT* head = NULL;
        nodeBT* tail = NULL;

        bintree2listUtil(root, &head, &tail);

        return head;
    }

    /* Helper function that allocates a new nodeBT with the
    given data and NULL left and right pointers. */
    nodeBT* newNode(int data)
    {
        nodeBT* new_node = new nodeBT();
        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return (new_node);
    }

    /* Function to print nodes in a given doubly linked list */
    //void printList(nodeBT* nodeBT)
    //{
    //    while (nodeBT != NULL) {
    //        cout << nodeBT->data << " ";
    //        nodeBT = nodeBT->right;
    //    }
    //}

    /* Driver code*/
    int main17()
    {
        // Let us create the tree shown in above diagram
        nodeBT* root = newNode(10);
        root->left = newNode(12);
        root->right = newNode(15);
        root->left->left = newNode(25);
        root->left->right = newNode(30);
        root->right->left = newNode(36);

        // Convert to DLL
        nodeBT* head = bintree2list(root);

        // Print the converted list
        printList(head);

        return 0;
    }










    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        fix next pointer and prev pointer
        TC: O(N)
    */

    // Changes left pointers to work as
    // previous pointers in converted DLL
    // The function simply does inorder
    // traversal of Binary Tree and updates
    // left pointer using previously visited nodeBT
    void fixPrevPtr(nodeBT* root)
    {
        static nodeBT* pre = NULL;

        if (root != NULL)
        {
            fixPrevPtr(root->left);
            root->left = pre;
            pre = root;
            fixPrevPtr(root->right);
        }
    }

    // Changes right pointers to work
    // as next pointers in converted DLL
    nodeBT* fixNextPtr(nodeBT* root)
    {
        nodeBT* prev = NULL;

        // Find the right most nodeBT
        // in BT or last nodeBT in DLL
        while (root && root->right != NULL)
            root = root->right;

        // Start from the rightmost nodeBT,
        // traverse back using left pointers.
        // While traversing, change right pointer of nodes.
        while (root && root->left != NULL)
        {
            prev = root;
            root = root->left;
            root->right = prev;
        }

        // The leftmost nodeBT is head
        // of linked list, return it
        return (root);
    }

    // The main function that converts
    // BST to DLL and returns head of DLL
    nodeBT* BTToDLL(nodeBT* root)
    {
        // Set the previous pointer
        fixPrevPtr(root);

        // Set the next pointer and return head of DLL
        return fixNextPtr(root);
    }











    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        just doing inorder traversal
        TC: O(N)
        n is the number of nodes in given binary tree
    */
    // A simple recursive function to convert a given Binary tree to Doubly
    // Linked List
    // root --> Root of Binary Tree
    // head --> Pointer to head nodeBT of created doubly linked list
    void BinaryTree2DoubleLinkedList(nodeBT* root, nodeBT** head)
    {
        // Base case
        if (root == NULL) return;

        // Initialize previously visited nodeBT as NULL. This is
        // static so that the same value is accessible in all recursive
        // calls
        static nodeBT* prev = NULL;

        // Recursively convert left subtree
        BinaryTree2DoubleLinkedList(root->left, head);

        // Now convert this nodeBT
        if (prev == NULL)
            *head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        // Finally convert right subtree
        BinaryTree2DoubleLinkedList(root->right, head);
    }

};

