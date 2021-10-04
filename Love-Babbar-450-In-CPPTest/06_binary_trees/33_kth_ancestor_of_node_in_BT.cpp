/*
    link: https://www.geeksforgeeks.org/kth-ancestor-nodeBT-binary-tree/
    link: https://www.geeksforgeeks.org/kth-ancestor-nodeBT-binary-tree-set-2/
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
class kth_ancestor_of_node_in_BT
{

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using BFS (queue)

        Time Complexity : O( n )
        Auxiliary Space : O( n )
    */
    /* C++ program to calculate Kth ancestor of given nodeBT */

    //// A Binary Tree nodeBT
    //struct nodeBT
    //{
    //    int data;
    //    struct nodeBT* left, * right;
    //};

    // fucntion to generate array of ancestors
    void generateArray(nodeBT* root, int ancestors[])
    {
        // There will be no ancestor of root nodeBT
        ancestors[root->data] = -1;

        // level order traversal to
        // generate 1st ancestor
        queue<nodeBT*> q;
        q.push(root);

        while (!q.empty())
        {
            nodeBT* temp = q.front();
            q.pop();

            if (temp->left)
            {
                ancestors[temp->left->data] = temp->data;
                q.push(temp->left);
            }

            if (temp->right)
            {
                ancestors[temp->right->data] = temp->data;
                q.push(temp->right);
            }
        }
    }

    // function to calculate Kth ancestor
    int kthAncestor(nodeBT* root, int n, int k, int nodeBT)
    {
        // create array to store 1st ancestors
        int ancestors[5] = { 0 };//n + 1

        // generate first ancestor array
        generateArray(root, ancestors);

        // variable to track record of number of
        // ancestors visited
        int count = 0;

        while (nodeBT != -1)
        {
            nodeBT = ancestors[nodeBT];
            count++;

            if (count == k)
                break;
        }

        // print Kth ancestor
        return nodeBT;
    }

    // Utility function to create a new tree nodeBT
    nodeBT* newNode(int data)
    {
        nodeBT* temp = new nodeBT;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    // Driver program to test above functions
    int main()
    {
        // Let us create binary tree shown in above diagram
        nodeBT* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);

        int k = 2;
        int nodeBT = 5;

        // print kth ancestor of given nodeBT
        cout << kthAncestor(root, 5, k, nodeBT);
        return 0;
    }







    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using simple recursion
    */
    // Program to find kth ancestor
    bool ancestor(struct nodeBT* root, int item, int& k)
    {
        if (root == NULL)
            return false;

        // Element whose ancestor is to be searched
        if (root->data == item)
        {
            //reduce count by 1
            k = k - 1;
            return true;
        }
        else
        {

            // Checking in left side
            bool flag = ancestor(root->left, item, k);
            if (flag)
            {
                if (k == 0)
                {

                    // If count = 0 i.e. element is found
                    cout << "[" << root->data << "] ";
                    return false;
                }

                // if count !=0 i.e. this is not the
                // ancestor we are searching for
                // so decrement count
                k = k - 1;
                return true;
            }

            // Similarly Checking in right side
            bool flag2 = ancestor(root->right, item, k);
            if (flag2)
            {
                if (k == 0)
                {
                    cout << "[" << root->data << "] ";
                    return false;
                }
                k = k - 1;
                return true;
            }
        }
    }







    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using DFS
    */

    /* C++ program to calculate Kth ancestor of given nodeBT */

    // A Binary Tree nodeBT


    // temporary nodeBT to keep track of nodeBT returned
    // from previous recursive call during backtrack
    nodeBT* temp = NULL;

    // recursive function to calculate Kth ancestor
    nodeBT* kthAncestorDFS(nodeBT* root, int nodeBT, int& k)
    {
        // Base case
        if (!root)
            return NULL;

        if (root->data == nodeBT || kthAncestorDFS(root->left, nodeBT, k) ||
            kthAncestorDFS(root->right, nodeBT, k))
        {
            if (k > 0)
                k--;

            else if (k == 0)
            {
                // print the kth ancestor
                cout << "Kth ancestor is: " << root->data;

                // return NULL to stop further backtracking
                return NULL;
            }

            // return current nodeBT to previous call
            return root;
        }
    }

    // Utility function to create a new tree nodeBT
    //nodeBT* newNode(int data)
    //{
    //    nodeBT* temp = new nodeBT;
    //    temp->data = data;
    //    temp->left = temp->right = NULL;
    //    return temp;
    //}

    // Driver program to test above functions
    int main1()
    {
        // Let us create binary tree shown in above diagram
        nodeBT* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);

        int k = 2;
        int nodeBT = 5;
        // print kth ancestor of given nodeBT
        auto parent = kthAncestorDFS(root, nodeBT, k);

        // check if parent is not NULL, it means
        // there is no Kth ancestor of the nodeBT
        if (parent)
            cout << "-1";

        return 0;
    }


};


