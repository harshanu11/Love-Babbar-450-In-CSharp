/*
    link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

    sol: https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
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
class top_view_of_tree
{

    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using level order traversal and hashing.

        here main logic is hd will be derived from parent root and then for children it will be hd-1 and hd+1
        so from there we can know the extreme ends, also in hashing we used heapMap hence will sort according to the
        hd value.
    */
    // C++ program to print top
    // view of binary tree


    // Structure of binary tree
    //struct nodeBT {
    //    nodeBT* left;
    //    nodeBT* right;
    //    int hd;
    //    int data;
    //};

    // function to create a new node
    //nodeBT* newNode(int key)
    //{
    //    nodeBT* node = new nodeBT();
    //    node->left = node->right = NULL;
    //    node->data = key;
    //    return node;
    //}

    // function should print the topView of
    // the binary tree
    void topview(nodeBT* root)
    {
        if (root == NULL)
            return;
        queue<nodeBT*> q;
        map<int, int> m;
        int hd = 0;
        root->hd = hd;

        // push node and horizontal distance to queue
        q.push(root);

        cout << "The top view of the tree is : \n";

        while (q.size()) {
            hd = root->hd;

            // count function returns 1 if the container
            // contains an element whose key is equivalent
            // to hd, or returns zero otherwise.
            if (m.count(hd) == 0)
                m[hd] = root->data;
            if (root->left) {
                root->left->hd = hd - 1;
                q.push(root->left);
            }
            if (root->right) {
                root->right->hd = hd + 1;
                q.push(root->right);
            }
            q.pop();
            root = q.front();
        }

        for (auto i = m.begin(); i != m.end(); i++) {
            cout << i->second << " ";
        }
    }

    // Driver Program to test above functions
    int main()
    {
        /* Create following Binary Tree
                1
            / \
            2 3
            \
                4
                \
                5
                \
                    6*/
        nodeBT* root = level_order_traversal::newNode(1);
        root->left = level_order_traversal::newNode(2);
        root->right = level_order_traversal::newNode(3);
        root->left->right = level_order_traversal::newNode(4);
        root->left->right->right = level_order_traversal::newNode(5);
        root->left->right->right->right = level_order_traversal::newNode(6);
        cout << "Following are nodes in top view of Binary "
            "Tree\n";
        topview(root);
        return 0;
    }





    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using map

        Time Complexity of the above implementation is O(nlogn)
        where n is the number of nodes in the given binary tree with each insertion operation
        in Map requiring O(log2n) complexity.
    */
    // function to fill the map
    void fillMap(nodeBT* root, int d, int l,
        map<int, pair<int, int> >& m)
    {
        if (root == NULL)
            return;

        // if that extreme end node is not in our map
        if (m.count(d) == 0) {
            m[d] = make_pair(root->data, l);
        }
        // if extreme node is there but as it is overlapped by less order level, we have to replace it.
        else if (m[d].second > l) {
            m[d] = make_pair(root->data, l);
        }

        fillMap(root->left, d - 1, l + 1, m);
        fillMap(root->right, d + 1, l + 1, m);
    }

    // function should print the topView of
    // the binary tree
    void topView1(struct nodeBT* root)
    {

        // map to store the pair of node value and its level
        // with respect to the vertical distance from root.
        map<int, pair<int, int> > m;

        // fillmap(root,vectical_distance_from_root,level_of_node,map)
        fillMap(root, 0, 0, m);

        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->second.first << " ";
        }
    }






    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using queue and stack
    */
    void topView2(nodeBT* root)
    {
        // queue for holding nodes and their horizontal
        // distance from the root node
        queue<pair<nodeBT*, int> > q;

        // pushing root node with distance 0
        q.push(make_pair(root, 0));

        // hd is currect node's horizontal distance from
        // root node l is currect left min horizontal
        // distance (or max in magnitude) so far from the
        // root node r is currect right max horizontal
        // distance so far from the root node

        int hd = 0, l = 0, r = 0;

        // stack is for holding left node's data because
        // they will appear in reverse order that is why
        // using stack
        stack<int> left;

        // vector is for holding right node's data
        vector<int> right;

        nodeBT* node;

        while (q.size()) {

            node = q.front().first;
            hd = q.front().second;

            if (hd < l) {
                left.push(node->data);
                l = hd;
            }
            else if (hd > r) {
                right.push_back(node->data);
                r = hd;
            }

            if (node->left) {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, hd + 1));
            }

            q.pop();
        }
        // printing the left node's data in reverse order
        while (left.size()) {
            cout << left.top() << " ";
            left.pop();
        }

        // then printing the root node's data
        cout << root->data << " ";

        // finally printing the right node's data
        for (auto x : right) {
            cout << x << " ";
        }
    }


};

