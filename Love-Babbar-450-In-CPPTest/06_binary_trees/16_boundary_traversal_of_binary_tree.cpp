///*
//    link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
//
//    sol (recursive): https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
//    sol (iterative): https://www.geeksforgeeks.org/iterative-boundary-traversal-of-complete-binary-tree/
//*/
//#include "01_level_order_traversal.cpp"
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
//class boundary_traversal_of_binary_tree
//{
//
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        TC: O(N), N is the no. of nodes.
//    */
//
//    /* A binary tree node has data, pointer to left child
//    and a pointer to right child */
//    //struct nodeBT {
//    //    int data;
//    //    struct nodeBT* left, * right;
//    //};
//
//    // A simple function to print leaf nodes of a binary tree
//    void printLeaves(nodeBT* root, vector<int>& ans)
//    {
//        if (root == NULL) return;
//
//        printLeaves(root->left, ans);
//
//        // Print it if it is a leaf node
//        if (!(root->left) && !(root->right))
//            ans.push_back(root->data);
//
//        printLeaves(root->right, ans);
//    }
//
//    // A function to print all left boundary nodes, except a leaf node.
//    // Print the nodes in TOP DOWN manner
//    void printBoundaryLeft(nodeBT* root, vector<int>& ans)
//    {
//        if (root == NULL) return;
//
//        if (root->left) {
//
//            // to ensure top down order, print the node
//            // before calling itself for left subtree
//            ans.push_back(root->data);
//            printBoundaryLeft(root->left, ans);
//        }
//        else if (root->right) {
//            ans.push_back(root->data);
//            printBoundaryLeft(root->right, ans);
//        }
//        // do nothing if it is a leaf node, this way we avoid
//        // duplicates in output
//    }
//
//    // A function to print all right boundary nodes, except a leaf node
//    // Print the nodes in BOTTOM UP manner
//    void printBoundaryRight(nodeBT* root, vector<int>& dummy)
//    {
//        if (root == NULL) return;
//
//        if (root->right) {
//            // to ensure bottom up order, first call for right
//            // subtree, then print this node
//            printBoundaryRight(root->right, dummy);
//            dummy.push_back(root->data);
//        }
//        else if (root->left) {
//            printBoundaryRight(root->left, dummy);
//            dummy.push_back(root->data);
//        }
//        // do nothing if it is a leaf node, this way we avoid
//        // duplicates in output
//    }
//
//    // A function to do boundary traversal of a given binary tree
//    vector <int> printBoundary(nodeBT* root)
//    {
//        if (root == NULL) return {};
//
//        vector<int> ans;
//
//        ans.push_back(root->data);
//
//        // Print the left boundary in top-down manner.
//        printBoundaryLeft(root->left, ans);
//
//        // Print all leaf nodes
//        printLeaves(root, ans);
//
//        // Print the right boundary in bottom-up manner
//        printBoundaryRight(root->right, ans);
//
//        return ans;
//    }
//
//    // A utility function to create a node
//    //nodeBT* newNode(int data)
//    //{
//    //    nodeBT* temp;
//
//    //    temp->data = data;
//    //    temp->left = temp->right = NULL;
//
//    //    return temp;
//    //}
//
//    // Driver program to test above functions
//    int main13()
//    {
//        // Let us construct the tree given in the above diagram
//        nodeBT* root = level_order_traversal::newNode(20);
//        root->left = level_order_traversal::newNode(8);
//        root->left->left = level_order_traversal::newNode(4);
//        root->left->right = level_order_traversal::newNode(12);
//        root->left->right->left = level_order_traversal::newNode(10);
//        root->left->right->right = level_order_traversal::newNode(14);
//        root->right = level_order_traversal::newNode(22);
//        root->right->right = level_order_traversal::newNode(25);
//
//        printBoundary(root);
//
//        return 0;
//    }
//
//
//
//
//
//
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        only iterative approach
//    */
//    // Function to print the nodes of a complete
//    // binary tree in boundary traversal order
//    void boundaryTraversal(nodeBT* root)
//    {
//        if (root) {
//
//            // If there is only 1 node print it
//            // and return
//            if (!(root->left) && !(root->right)) {
//                cout << root->data << endl;
//                return;
//            }
//
//            // List to store order of traversed
//            // nodes
//            vector<nodeBT*> list;
//            list.push_back(root);
//
//            // Traverse left boundary without root
//            // and last node
//            nodeBT* L = root->left;
//            while (L->left) {
//                list.push_back(L);
//                L = L->left;
//            }
//
//            // BFS designed to only include leaf nodes
//            queue<nodeBT*> q;
//            q.push(root);
//            while (!q.empty()) {
//                nodeBT* temp = q.front();
//                q.pop();
//                if (!(temp->left) && !(temp->right)) {
//                    list.push_back(temp);
//                }
//                if (temp->left) {
//                    q.push(temp->left);
//                }
//                if (temp->right) {
//                    q.push(temp->right);
//                }
//            }
//
//            // Traverse right boundary without root
//            // and last node
//            vector<nodeBT*> list_r;
//            nodeBT* R = root->right;
//            while (R->right) {
//                list_r.push_back(R);
//                R = R->right;
//            }
//
//            // Reversing the order
//            reverse(list_r.begin(), list_r.end());
//
//            // Concatenating the two lists
//            list.insert(list.end(), list_r.begin(),
//                list_r.end());
//
//            // Printing the node's data from the list
//            for (auto i : list) {
//                cout << i->data << " ";
//            }
//            cout << endl;
//            return;
//        }
//    }
//
//};
