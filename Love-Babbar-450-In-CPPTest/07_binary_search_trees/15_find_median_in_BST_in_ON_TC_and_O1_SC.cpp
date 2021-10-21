///*
//    link: https://www.geeksforgeeks.org/find-median-bst-time-o1-space/
//
//    The task is very simple if we are allowed to use extra space but Inorder traversal using recursion
//    and stack both use Space which is not allowed here.
//    So, the solution is to do Morris Inorder traversal as it doesn’t require any extra space.
//*/
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    simple way store every element in array in inorder fashion,
//    and then return median (as it will already be sorted)
//*/
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
//    without extra space
//    using morris traversal
//*/
///* C++ program to find the median of BST in O(n)
//time and O(1) space*/
//
//using namespace std;
//
///* A binary search tree nodeBT has data, pointer
//to left child and a pointer to right child */
////struct nodeBT
////{
////    int data;
////    struct nodeBT* left, * right;
////};
//
//// A utility function to create a new BST node
//struct nodeBT* newNode11(int item)
//{
//    struct nodeBT* temp = new nodeBT;
//    temp->data = item;
//    temp->left = temp->right = NULL;
//    return temp;
//}
//
///* A utility function to insert a new node with
//given key in BST */
//struct nodeBT* insert(struct nodeBT* node, int key)
//{
//    /* If the tree is empty, return a new node */
//    if (node == NULL) return newNode11(key);
//
//    /* Otherwise, recur down the tree */
//    if (key < node->data)
//        node->left = insert(node->left, key);
//    else if (key > node->data)
//        node->right = insert(node->right, key);
//
//    /* return the (unchanged) node pointer */
//    return node;
//}
//
///* Function to count nodes in a binary search tree
//using Morris Inorder traversal*/
//int counNodes(struct nodeBT* root)
//{
//    struct nodeBT* current, * pre;
//
//    // Initialise count of nodes as 0
//    int count = 0;
//
//    if (root == NULL)
//        return count;
//
//    current = root;
//    while (current != NULL)
//    {
//        if (current->left == NULL)
//        {
//            // Count node if its left is NULL
//            count++;
//
//            // Move to its right
//            current = current->right;
//        }
//        else
//        {
//            /* Find the inorder predecessor of current */
//            pre = current->left;
//
//            while (pre->right != NULL &&
//                pre->right != current)
//                pre = pre->right;
//
//            /* Make current as right child of its
//            inorder predecessor */
//            if (pre->right == NULL)
//            {
//                pre->right = current;
//                current = current->left;
//            }
//
//            /* Revert the changes made in if part to
//            restore the original tree i.e., fix
//            the right child of predecssor */
//            else
//            {
//                pre->right = NULL;
//
//                // Increment count if the current
//                // node is to be visited
//                count++;
//                current = current->right;
//            } /* End of if condition pre->right == NULL */
//        } /* End of if condition current->left == NULL*/
//    } /* End of while */
//
//    return count;
//}
//
//
///* Function to find median in O(n) time and O(1) space
//using Morris Inorder traversal*/
//int findMedian(struct nodeBT* root)
//{
//    root = NULL;
//    if (root == NULL)
//        return 0;
//
//    int count = counNodes(root);
//    int currCount = 0;
//    struct nodeBT* current = root, * pre, * prev;
//
//    while (current != NULL)
//    {
//        if (current->left == NULL)
//        {
//            // count current node
//            currCount++;
//
//            // check if current node is the median
//            // Odd case
//            //if (count % 2 != 0 && currCount == (count + 1) / 2)
//            //    return prev->data;
//
//            // Even case
//            //else if (count % 2 == 0 && currCount == (count / 2) + 1)
//            //    return (prev->data + current->data) / 2;
//
//            // Update prev for even no. of nodes
//            prev = current;
//
//            //Move to the right
//            current = current->right;
//        }
//        else
//        {
//            /* Find the inorder predecessor of current */
//            pre = current->left;
//            while (pre->right != NULL && pre->right != current)
//                pre = pre->right;
//
//            /* Make current as right child of its inorder predecessor */
//            if (pre->right == NULL)
//            {
//                pre->right = current;
//                current = current->left;
//            }
//
//            /* Revert the changes made in if part to restore the original
//            tree i.e., fix the right child of predecssor */
//            else
//            {
//                pre->right = NULL;
//
//                prev = pre;
//
//                // Count current node
//                currCount++;
//
//                // Check if the current node is the median
//                if (count % 2 != 0 && currCount == (count + 1) / 2)
//                    return current->data;
//
//                else if (count % 2 == 0 && currCount == (count / 2) + 1)
//                    return (prev->data + current->data) / 2;
//
//                // update prev node for the case of even
//                // no. of nodes
//                prev = current;
//                current = current->right;
//
//            } /* End of if condition pre->right == NULL */
//        } /* End of if condition current->left == NULL*/
//    } /* End of while */
//}
//
///* Driver program to test above functions*/
//int main34()
//{
//
//    /* Let us create following BST
//                50
//            /	 \
//            30	 70
//            / \ / \
//        20 40 60 80 */
//    struct nodeBT* root = NULL;
//    root = insert(root, 50);
//    insert(root, 30);
//    insert(root, 20);
//    insert(root, 40);
//    insert(root, 70);
//    insert(root, 60);
//    insert(root, 80);
//
//    cout << "\nMedian of BST is "
//        << findMedian(root);
//    return 0;
//}
