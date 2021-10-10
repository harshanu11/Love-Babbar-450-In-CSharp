///*
//    link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
//
//    sol: https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
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
//    //TEST_CLASS(BTSort)
//    //{
//    //public:
//
//    //    TEST_METHOD(Test)
//    //    {
//    //        std::string charM = "harhs";
//    //        int age = 14;
//    //        age = 55;
//    //        std::string lastName = "<<charM <<singh";
//
//    //    }
//    //};
//}
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    TC: O(N)
//*/
//// C++ program to find predecessor and successor in a BST
//
//
//// BST nodeBT
////struct nodeBT
////{
////    int key;
////    struct nodeBT* left, * right;
////};
//
//// This function finds predecessor and successor of key in BST.
//// It sets pre and suc as predecessor and successor respectively
//void findPreSuc(nodeBT* root, nodeBT*& pre, nodeBT*& suc, int key)
//{
//    // Base case
//    if (root == NULL) return;
//
//    // If key is present at root
//    if (root->data == key)
//    {
//        // the maximum value in left subtree is predecessor
//        if (root->left != NULL)
//        {
//            nodeBT* tmp = root->left;
//            while (tmp->right)
//                tmp = tmp->right;
//            pre = tmp;
//        }
//
//        // the minimum value in right subtree is successor
//        if (root->right != NULL)
//        {
//            nodeBT* tmp = root->right;
//            while (tmp->left)
//                tmp = tmp->left;
//            suc = tmp;
//        }
//        return;
//    }
//
//    // If key is smaller than root's key, go to left subtree
//    if (root->data > key)
//    {
//        suc = root;
//        findPreSuc(root->left, pre, suc, key);
//    }
//    else // go to right subtree
//    {
//        pre = root;
//        findPreSuc(root->right, pre, suc, key);
//    }
//}
//
//// A utility function to create a new BST node
//nodeBT* newNode(int item)
//{
//    nodeBT* temp= new nodeBT();
//    temp->data = item;
//    temp->left = temp->right = NULL;
//    return temp;
//}
//
///* A utility function to insert a new node with given key in BST */
//nodeBT* insert(nodeBT* node, int key)
//{
//    if (node == NULL) return newNode(key);
//    if (key < node->data)
//        node->left = insert(node->left, key);
//    else
//        node->right = insert(node->right, key);
//    return node;
//}
//
//// Driver program to test above function
//int mainbt()
//{
//    int key = 65; //Key to be searched in BST
//
///* Let us create following BST
//            50
//        /	 \
//        30	 70
//        / \ / \
//    20 40 60 80 */
//    nodeBT* root = NULL;
//    root = insert(root, 50);
//    insert(root, 30);
//    insert(root, 20);
//    insert(root, 40);
//    insert(root, 70);
//    insert(root, 60);
//    insert(root, 80);
//
//
//    nodeBT* pre = NULL, * suc = NULL;
//
//    findPreSuc(root, pre, suc, key);
//    if (pre != NULL)
//        cout << "Predecessor is " << pre->data << endl;
//    else
//        cout << "No Predecessor";
//
//    if (suc != NULL)
//        cout << "Successor is " << suc->data;
//    else
//        cout << "No Successor";
//    return 0;
//}
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    TC: O(N)
//*/
//
///*
//since inorder traversal results in
//ascending order visit to node , we
//can store the values of the largest
//no which is smaller than a (predecessor)
//and smallest no which is large than
//a (successor) using inorder traversal
//*/
//void find_p_s(nodeBT* root, int a,
//    nodeBT** p, nodeBT** q)
//{
//    // If root is null return
//    if (!root)
//        return;
//
//    // traverse the left subtree   
//    find_p_s(root->left, a, p, q);
//
//    // root data is greater than a
//    if (root && root->data > a)
//    {
//
//        // q stores the node whose data is greater
//        // than a and is smaller than the previously
//        // stored data in *q which is successor
//        if ((!*q) || (*q) && (*q)->data > root->data)
//            *q = root;
//    }
//
//    // if the root data is smaller than
//    // store it in p which is predecessor
//    else if (root && root->data < a)
//    {
//        *p = root;
//    }
//
//    // traverse the right subtree
//    find_p_s(root->right, a, p, q);
//}
