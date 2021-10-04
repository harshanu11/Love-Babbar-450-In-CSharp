/*
    link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
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
class find_LCA_in_BT
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        storing and comparing path of n1 and n2
        TC: O(N)
        SC: O(N)
    */
    // C++ Program for Lowest Common Ancestor in a Binary Tree
    // A O(n) solution to find LCA of two given values n1 and n2




    // Utility function creates a new binary tree node with given key
    nodeBT* newNode(int k)
    {
        nodeBT* temp = new nodeBT;
        temp->data = k;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Finds the path from root node to given root of the tree, Stores the
    // path in a vector path[], returns true if path exists otherwise false
    bool findPath(nodeBT* root, vector<int>& path, int k)
    {
        // base case
        if (root == NULL) return false;

        // Store this node in path vector. The node will be removed if
        // not in path from root to k
        path.push_back(root->data);

        // See if the k is same as root's key
        if (root->data == k)
            return true;

        // Check if k is found in left or right sub-tree
        if ((root->left && findPath(root->left, path, k)) ||
            (root->right && findPath(root->right, path, k)))
            return true;

        // If not present in subtree rooted with root, remove root from
        // path[] and return false
        path.pop_back();
        return false;
    }

    // Returns LCA if node n1, n2 are present in the given binary tree,
    // otherwise return -1
    int findLCA1(nodeBT* root, int n1, int n2)
    {
        // to store paths to n1 and n2 from the root
        vector<int> path1, path2;

        // Find paths from root to n1 and root to n1. If either n1 or n2
        // is not present, return -1
        if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
            return -1;

        /* Compare the paths to get the first different value */
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++)
            if (path1[i] != path2[i])
                break;
        return path1[i - 1];
    }

    // Driver program to test above functions
    int main()
    {
        // Let us create the Binary Tree shown in above diagram.
        nodeBT* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->right->right = newNode(7);
        cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
        cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);
        cout << "nLCA(3, 4) = " << findLCA(root, 3, 4);
        cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);
        return 0;
    }






    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        finding in single traversal (assuming that keys are present)
        TC: O(N)
        SC: O(1)
    */
    // This function returns pointer to LCA of two given values n1 and n2.
    // This function assumes that n1 and n2 are present in Binary Tree
    struct nodeBT* findLCA2(struct nodeBT* root, int n1, int n2)
    {
        // Base case
        if (root == NULL) return NULL;

        // If either n1 or n2 matches with root's key, report
        // the presence by returning root (Note that if a key is
        // ancestor of other, then the ancestor key becomes LCA
        if (root->data == n1 || root->data == n2)
            return root;

        // Look for keys in left and right subtrees
        nodeBT* left_lca = findLCA2(root->left, n1, n2);
        nodeBT* right_lca = findLCA2(root->right, n1, n2);

        // If both of the above calls return Non-NULL, then one key
        // is present in once subtree and other is present in other,
        // So this node is the LCA
        if (left_lca && right_lca)  return root;

        // Otherwise check if left subtree or right subtree is LCA
        return (left_lca != NULL) ? left_lca : right_lca;
    }







    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        also proving if keys are present or not
    */

    // This function returns pointer to LCA of two given values n1 and n2.
    // v1 is set as true by this function if n1 is found
    // v2 is set as true by this function if n2 is found
    struct nodeBT* findLCAUtil(struct nodeBT* root, int n1, int n2, bool& v1, bool& v2)
    {
        // Base case
        if (root == NULL) return NULL;

        // If either n1 or n2 matches with root's key, report the presence
        // by setting v1 or v2 as true and return root (Note that if a key
        // is ancestor of other, then the ancestor key becomes LCA)
        if (root->data == n1)
        {
            v1 = true;
            return root;
        }
        if (root->data == n2)
        {
            v2 = true;
            return root;
        }

        // Look for keys in left and right subtrees
        nodeBT* left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
        nodeBT* right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

        // If both of the above calls return Non-NULL, then one key
        // is present in once subtree and other is present in other,
        // So this node is the LCA
        if (left_lca && right_lca) return root;

        // Otherwise check if left subtree or right subtree is LCA
        return (left_lca != NULL) ? left_lca : right_lca;
    }

    // Returns true if key k is present in tree rooted with root
    bool find(nodeBT* root, int k)
    {
        // Base Case
        if (root == NULL)
            return false;

        // If key is present at root, or in left subtree or right subtree,
        // return true;
        if (root->data == k || find(root->left, k) || find(root->right, k))
            return true;

        // Else return false
        return false;
    }

    // This function returns LCA of n1 and n2 only if both n1 and n2 are present
    // in tree, otherwise returns NULL;
    nodeBT* findLCA(nodeBT* root, int n1, int n2)
    {
        // Initialize n1 and n2 as not visited
        bool v1 = false, v2 = false;

        // Find lca of n1 and n2 using the technique discussed above
        nodeBT* lca = findLCAUtil(root, n1, n2, v1, v2);

        // Return LCA only if both n1 and n2 are present in tree
        if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
            return lca;

        // Else return NULL
        return NULL;
    }


};

