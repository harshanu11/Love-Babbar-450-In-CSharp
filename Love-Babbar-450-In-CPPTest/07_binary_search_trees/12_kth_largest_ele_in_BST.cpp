/*
    link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

    sol1: https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
    sol2 (morris traversal): https://www.geeksforgeeks.org/kth-largest-element-bst-using-constant-extra-space/

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
    using min Heap.
    TC: O(N), N is the no. of nodes
    SC: O(K), K is kth given
*/
void getKthLargest(nodeBT* root, priority_queue<int, vector<int>, greater<int>>& pq, int sz) {
    if (!root) return;

    getKthLargest(root->left, pq, sz);
    pq.push(root->data);
    if (pq.size() > sz) pq.pop();
    getKthLargest(root->right, pq, sz);
}

int kthLargest(nodeBT* root, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    getKthLargest(root, pq, K);

    return pq.top();
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by counting the node

    Time Complexity: O(h + k).
        The code first traverses down to the rightmost node which takes O(h) time, then traverses k elements in O(k) time. Therefore overall time complexity is O(h + k).
    Auxiliary Space: O(1).
        As no extra space is needed.
*/
void kthLargestUtil(nodeBT* root, int k, int& c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;

    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);

    // Increment count of visited nodes
    c++;

    // If c becomes k now, then this is the k'th largest
    if (c == k)
    {
        cout << "K'th largest element is "
            << root->data << endl;
        return;
    }

    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}

// Function to find k'th largest element
void kthLargest2(nodeBT* root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;

    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    morris traversal
*/
nodeBT* KthLargestUsingMorrisTraversal(nodeBT* root, int k)
{
    nodeBT* curr = root;
    nodeBT* Klargest = NULL;

    // count variable to keep count of visited Nodes
    int count = 0;

    while (curr != NULL) {
        // if right child is NULL
        if (curr->right == NULL) {

            // first increment count and check if count = k
            if (++count == k)
                Klargest = curr;

            // otherwise move to the left child
            curr = curr->left;
        }

        else {

            // find inorder successor of current nodeBT
            nodeBT* succ = curr->right;

            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;

            if (succ->left == NULL) {

                // set left child of successor to the
                // current nodeBT
                succ->left = curr;

                // move current to its right
                curr = curr->right;
            }

            // restoring the tree back to original binary
            //  search tree removing threaded links
            else {

                succ->left = NULL;

                if (++count == k)
                    Klargest = curr;

                // move current to its left child
                curr = curr->left;
            }
        }
    }

    return Klargest;
}