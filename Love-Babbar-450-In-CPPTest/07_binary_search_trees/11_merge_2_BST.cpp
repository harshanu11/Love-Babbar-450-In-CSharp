/*
    link: https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

    also read other methods given in above link
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
// C++ program to Merge Two Balanced Binary Search Trees
//#include<bits/stdc++.h>
using namespace std;

/* A binary tree nodeBT has data, pointer to left child
and a pointer to right child */
//class nodeBT
//{
//public:
//    int data;
//    nodeBT* left;
//    nodeBT* right;
//};

// A utility unction to merge two sorted arrays into one
int* merge(int arr1[], int arr2[], int m, int n);

// A helper function that stores inorder
// traversal of a tree in inorder array
void storeInorder(nodeBT* nodeBT, int inorder[],
    int* index_ptr);

/* A function that constructs Balanced
Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
nodeBT* sortedArrayToBST(int arr[], int start, int end);

/* This function merges two balanced
BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
nodeBT* mergeTrees(nodeBT* root1, nodeBT* root2, int m, int n)
{
    // Store inorder traversal of
    // first tree in an array arr1[]
    int* arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);

    // Store inorder traversal of second
    // tree in another array arr2[]
    int* arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);

    // Merge the two sorted array into one
    int* mergedArr = merge(arr1, arr2, m, n);

    // Construct a tree from the merged
    // array and return root of the tree
    return sortedArrayToBST(mergedArr, 0, m + n - 1);
}

/* Helper function that allocates
a new nodeBT with the given data and
NULL left and right pointers. */
nodeBT* newNode10(int data)
{
    nodeBT* Node = new nodeBT();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}

// A utility function to print inorder
// traversal of a given binary tree
void printInorder(nodeBT* nodeBT)
{
    if (nodeBT == NULL)
        return;

    /* first recur on left child */
    printInorder(nodeBT->left);

    cout << nodeBT->data << " ";

    /* now recur on right child */
    printInorder(nodeBT->right);
}

// A utility unction to merge
// two sorted arrays into one
int* merge(int arr1[], int arr2[], int m, int n)
{
    // mergedArr[] is going to contain result
    int* mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;

    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaller element and put it in mergedArr
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }

    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }

    return mergedArr;
}

// A helper function that stores inorder
// traversal of a tree rooted with nodeBT
void storeInorder(nodeBT* nodeBT, int inorder[], int* index_ptr)
{
    if (nodeBT == NULL)
        return;

    /* first recur on left child */
    storeInorder(nodeBT->left, inorder, index_ptr);

    inorder[*index_ptr] = nodeBT->data;
    (*index_ptr)++; // increase index for next entry

    /* now recur on right child */
    storeInorder(nodeBT->right, inorder, index_ptr);
}

/* A function that constructs Balanced
// Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
nodeBT* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
        return NULL;

        /* Get the middle element and make it root */
    int mid = (start + end) / 2;
    nodeBT* root = newNode10(arr[mid]);

    /* Recursively construct the left subtree and make it
    left child of root */
    root->left = sortedArrayToBST(arr, start, mid - 1);

    /* Recursively construct the right subtree and make it
    right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

/* Driver code*/
int main33()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    nodeBT* root1 = newNode10(100);
    root1->left = newNode10(50);
    root1->right = newNode10(300);
    root1->left->left = newNode10(20);
    root1->left->right = newNode10(70);

    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    nodeBT* root2 = newNode10(80);
    root2->left = newNode10(40);
    root2->right = newNode10(120);

    nodeBT* mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);

    return 0;
}
