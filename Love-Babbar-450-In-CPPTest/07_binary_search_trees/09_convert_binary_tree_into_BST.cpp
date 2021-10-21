///*
//    link: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
//
//    sol: https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
//*/
//
//#include "../06_binary_trees/01_level_order_traversal.cpp"
//#include "CppUnitTest.h"
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <unordered_set>
//#include <set>
//#include <unordered_map>
//#include <queue>
//#include <stack>
//
//using namespace std;
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace LoveBabbar450InCPPTest
//{
//    TEST_CLASS(BTSort)
//    {
//    public:
//
//        TEST_METHOD(Test)
//        {
//            std::string charM = "harhs";
//            int age = 14;
//            age = 55;
//            std::string lastName = "<<charM <<singh";
//
//        }
//    };
//}
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    C code,
//    TC: O(N), N is the no. of nodeBT
//*/
///* A program to convert Binary Tree to Binary Search Tree */
//
///* A binary tree nodeBT structure */
////struct nodeBT {
////    int data;
////    struct nodeBT* left;
////    struct nodeBT* right;
////};
//
///* A helper function that stores v traversal of a tree rooted
//with nodeBT */
//void storev(struct nodeBT* nodeBT, int v[], int* index_ptr)
//{
//    // Base Case
//    if (nodeBT == NULL)
//        return;
//
//    /* first store the left subtree */
//    storev(nodeBT->left, v, index_ptr);
//
//    /* Copy the root's data */
//    v[*index_ptr] = nodeBT->data;
//    (*index_ptr)++; // increase index for next entry
//
//    /* finally store the right subtree */
//    storev(nodeBT->right, v, index_ptr);
//}
//
///* A helper function to count nodes in a Binary Tree */
//int countNodes(struct nodeBT* root)
//{
//    if (root == NULL)
//        return 0;
//    return countNodes(root->left) + countNodes(root->right) + 1;
//}
//
//// Following function is needed for library function qsort()
////int compare(const void* a, const void* b)
////{
////    return (*(int*)a - *(int*)b);
////}
//
///* A helper function that copies contents of arr[] to Binary Tree.
//This function basically does v traversal of Binary Tree and
//one by one copy arr[] elements to Binary Tree nodes */
//void arrayToBST(int* arr, struct nodeBT* root, int* index_ptr)
//{
//    // Base Case
//    if (root == NULL)
//        return;
//
//    /* first update the left subtree */
//    arrayToBST(arr, root->left, index_ptr);
//
//    /* Now update root's data and increment index */
//    root->data = arr[*index_ptr];
//    (*index_ptr)++;
//
//    /* finally update the right subtree */
//    arrayToBST(arr, root->right, index_ptr);
//}
//
//// This function converts a given Binary Tree to BST
//void binaryTreeToBST(struct nodeBT* root)
//{
//    // base case: tree is empty
//    if (root == NULL)
//        return;
//
//    /* Count the number of nodes in Binary Tree so that
//    we know the size of temporary array to be created */
//    int n = countNodes(root);
//
//    // Create a temp array arr[] and store v traversal of tree in arr[]
//    int* arr = new int[n];
//    int i = 0;
//    storev(root, arr, &i);
//
//    // Sort the array using library function for quick sort
//    //qsort(arr, n, sizeof(arr[0]), compare);
//
//    // Copy array elements back to Binary Tree
//    i = 0;
//    arrayToBST(arr, root, &i);
//
//    // delete dynamically allocated memory to avoid memory leak
//    delete[] arr;
//}
//
///* Utility function to create a new Binary Tree nodeBT */
//struct nodeBT* newNode(int data)
//{
//    struct nodeBT* temp = new struct nodeBT;
//    temp->data = data;
//    temp->left = NULL;
//    temp->right = NULL;
//    return temp;
//}
//
///* Utility function to print v traversal of Binary Tree */
//void printv(struct nodeBT* nodeBT)
//{
//    if (nodeBT == NULL)
//        return;
//
//    /* first recur on left child */
//    printv(nodeBT->left);
//
//    /* then print the data of nodeBT */
//    printf("%d ", nodeBT->data);
//
//    /* now recur on right child */
//    printv(nodeBT->right);
//}
//
///* Driver function to test above functions */
//int mainBT1()
//{
//    struct nodeBT* root = NULL;
//
//    /* Constructing tree given in the above figure
//        10
//        / \
//        30 15
//    /	 \
//    20	 5 */
//    root = newNode(10);
//    root->left = newNode(30);
//    root->right = newNode(15);
//    root->left->left = newNode(20);
//    root->right->right = newNode(5);
//
//    // convert Binary Tree to BST
//    binaryTreeToBST(root);
//
//    printf("Following is v Traversal of the converted BST: \n");
//    printv(root);
//
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    c++ solution [accepted]
//*/
//
//void getInorder(nodeBT* root, vector<int>& v) {
//    if (!root) return;
//
//    getInorder(root->left, v);
//    v.push_back(root->data);
//    getInorder(root->right, v);
//}
//
//void setInorder(vector<int> v, nodeBT* root, int& i) {
//    if (!root) return;
//
//    setInorder(v, root->left, i);
//    root->data = v[i];
//    i++;
//    setInorder(v, root->right, i);
//}
//
//nodeBT* binaryTreeToBST2(nodeBT* root)
//{
//    vector<int> v;
//    getInorder(root, v);
//    sort(v.begin(), v.end());
//
//    int i = 0;
//    setInorder(v, root, i);
//    return root;
//}