/*
    link: https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1

    sol: https://www.geeksforgeeks.org/find-duplicate-subtrees/
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
class find_all_duplicate_subtree_in_BT
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using hashing
        TC: O(N)
        SC: O(N)
    */

    // C++ program to find averages of all levels
    // in a binary tree.

    /* A binary tree node has data, pointer to
    left child and a pointer to right child */
    struct Node {
        int data;
        struct Node* left, * right;
    };

    string inorder(Node* node, unordered_map<string, int>& m)
    {
        if (!node)
            return "";

        string str = "(";
        str += inorder(node->left, m);
        str += to_string(node->data);
        str += inorder(node->right, m);
        str += ")";

        // Subtree already present (Note that we use
        // unordered_map instead of unordered_set
        // because we want to print multiple duplicates
        // only once, consider example of 4 in above
        // subtree, it should be printed only once.
        if (m[str] == 1)
            cout << node->data << " ";

        m[str]++;

        return str;
    }

    // Wrapper over inorder()
    void printAllDups(Node* root)
    {
        unordered_map<string, int> m;
        inorder(root, m);
    }

    /* Helper function that allocates a
    new node with the given data and
    NULL left and right pointers. */
    Node* newNode(int data)
    {
        Node* temp = new Node;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Driver code
    int main29()
    {
        Node* root = NULL;
        root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->right->left = newNode(2);
        root->right->left->left = newNode(4);
        root->right->right = newNode(4);
        printAllDups(root);
        return 0;
    }


};


