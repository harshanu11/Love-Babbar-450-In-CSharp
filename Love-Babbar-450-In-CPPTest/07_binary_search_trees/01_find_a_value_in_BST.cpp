/*
    link (insertion node): https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

    sol (find and insertion): https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
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

    TEST_CLASS(BSTClass)
    {
    public:

        TEST_METHOD(FindValInBstTest)
        {
           
            nodeBT  * root = NULL;
            root = InsertBST(root, 50);
            InsertBST(root, 30);
            InsertBST(root, 20);
            InsertBST(root, 40);
            InsertBST(root, 70);
            InsertBST(root, 60);
            InsertBST(root, 80);
            auto ans = searchBST(root,20);
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using recursion
            TC: O(log N)
        */
        // C++ function to search a given key in a given BST
        nodeBT* searchBST(nodeBT* root, int key)
        {
            // Base Cases: root is null or key is present at root
            if (root == NULL || root->data == key)
                return root;

            // Key is greater than root's key
            if (root->data < key)
                return searchBST(root->right, key);

            // Key is smaller than root's key
            return searchBST(root->left, key);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            insert a node in BST
            TC: O(log N)    // if its not skewed tree
                O(N)        // it skewed tree
        */
        // Insert function definition.
        nodeBT* InsertBST(nodeBT* root, int key)
        {
            if (!root)
            {
                // Insert the first node, if root is NULL.
                return new nodeBT(key);
            }

            // Insert data.
            if (key > root->data)
            {
                // Insert right node data, if the 'key'
                // to be inserted is greater than 'root' node data.

                // Process right nodes.
                root->right = InsertBST(root->right, key);
            }
            else
            {
                // Insert left node data, if the 'key'
                // to be inserted is greater than 'root' node data.

                // Process left nodes.
                root->left = InsertBST(root->left, key);
            }
            // Return 'root' node, after insertion.
            return root;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using iteration
            TC: O(log N) not skewed
                O(N) for skewed
        */
        void insertBST1(nodeBT* root, int key) {
            nodeBT* node = new nodeBT(key);
            if (root == NULL) {
                root = node;
                return;
            }


            nodeBT* prev = NULL;
            nodeBT* temp = root;
            while (temp != NULL) {
                if (temp->data > key) {
                    prev = temp;
                    temp = temp->left;
                }
                else if (temp->data < key) {
                    prev = temp;
                    temp = temp->right;
                }
            }

            if (prev->data > key) prev->left = node;
            else prev->right = node;
        }
    };
}
