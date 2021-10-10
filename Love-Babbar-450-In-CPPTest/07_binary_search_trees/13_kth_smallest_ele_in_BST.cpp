/*
    link: https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

    sol: https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
    sol (morris traversal): https://www.geeksforgeeks.org/kth-smallest-element-in-bst-using-o1-extra-space/

    video (just to understand morris traversal): https://youtu.be/wGXB9OWhPTg
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
/*
    using max Heap.
    TC: O(N), N is the no. of nodes
    SC: O(K), K is kth given
*/
void getKthSmallest(nodeBT* root, priority_queue<int>& pq, int sz) {
    if (!root) return;

    getKthSmallest(root->left, pq, sz);
    pq.push(root->data);
    if (pq.size() > sz) pq.pop();
    getKthSmallest(root->right, pq, sz);
}

int KthSmallestElement(nodeBT* root, int K)
{
    priority_queue<int> pq;
    getKthSmallest(root, pq, K);

    return (pq.size() == K) ? pq.top() : -1;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    traversing in-order
*/
nodeBT* kthSmallest(nodeBT* root, int& k)
{
    // base case
    if (root == NULL)
        return NULL;

    // search in left subtree
    nodeBT* left = kthSmallest(root->left, k);

    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;

    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root;

    // else search in right subtree
    return kthSmallest(root->right, k);
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    iterating (morris traversal)
*/
int KSmallestUsingMorris(nodeBT* root, int k)
{
    // Count to iterate over elements till we
    // get the kth smallest number
    int count = 0;

    int ksmall = INT_MIN; // store the Kth smallest
    nodeBT* curr = root; // to store the current node

    while (curr != NULL)
    {
        // Like Morris traversal if current does
        // not have left child rather than printing
        // as we did in inorder, we will just
        // increment the count as the number will
        // be in an increasing order
        if (curr->left == NULL)
        {
            count++;

            // if count is equal to K then we found the
            // kth smallest, so store it in ksmall
            if (count == k)
                ksmall = curr->data;

            // go to current's right child
            curr = curr->right;
        }
        else
        {
            // we create links to Inorder Successor and
            // count using these links
            nodeBT* pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;

            // building links
            if (pre->right == NULL)
            {
                //link made to Inorder Successor
                pre->right = curr;
                curr = curr->left;
            }

            // While breaking the links in so made temporary
            // threaded tree we will check for the K smallest
            // condition
            else
            {
                // Revert the changes made in if part (break link
                // from the Inorder Successor)
                pre->right = NULL;

                count++;

                // If count is equal to K then we found
                // the kth smallest and so store it in ksmall
                if (count == k)
                    ksmall = curr->data;

                curr = curr->right;
            }
        }
    }
    return ksmall; //return the found value
}