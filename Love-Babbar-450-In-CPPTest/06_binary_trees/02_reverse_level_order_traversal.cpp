///*
//    link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#
//
//    sol: https://www.geeksforgeeks.org/reverse-level-order-traversal/
//*/
//
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
//
//class reverse_level_order_traversal{
//    // ----------------------------------------------------------------------------------------------------------------------- //
///*
//    same code as in 1_level_order.....
//    here just change the level iteration from i=height to 1.
//*/
//    //int height(nodeBT* node) {
//    //    if (node == NULL) return 0;
//    //    else {
//    //        int lHeight = height(node->left);
//    //        int rHeight = height(node->right);
//
//    //        if (lHeight > rHeight) return lHeight + 1;
//    //        else return rHeight + 1;
//    //    }
//    //}
//
//    void getCurrentLevel(nodeBT* root, int level, vector<int>& ans) {
//        if (root == NULL) return;
//
//        if (level == 1) ans.push_back(root->data);
//        else if (level > 1) {
//            getCurrentLevel(root->left, level - 1, ans);
//            getCurrentLevel(root->right, level - 1, ans);
//        }
//    }
//
//    void levelOrderTraversal(nodeBT* root, vector<int>& ans) {
//        int h = height(root);
//        for (int i = h; i >= 1; i--) {
//            getCurrentLevel(root, i, ans);
//        }
//    }
//
//    vector<int> reverseLevelOrder(nodeBT* root)
//    {
//        // code here
//        vector<int> ans;
//        levelOrderTraversal(root, ans);
//        return ans;
//    }
//
//
//
//
//
//
//
//
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        using queue and stack
//
//        same code as in 1_level_order.....
//        here just change
//            1. push right node first as in reverse we want left node first
//            2. after pushing everything in queue, pop it and push to stack (it will make reverse)
//
//    */
//    //vector<int> printLevelOrder(nodeBT* root)
//    //{
//    //    // Base Case
//    //    if (root == NULL)  return;
//
//    //    // Create an empty queue for level order traversal
//    //    queue<nodeBT*> q;
//    //    stack<nodeBT*> s;
//    //    vector<int> ans;
//
//    //    // Enqueue Root and initialize height
//    //    q.push(root);
//
//    //    while (q.empty() == false)
//    //    {
//    //        // Print front of queue and remove it from queue
//    //        nodeBT* node = q.front();
//
//    //        /*Enqueue right child */
//    //        if (node->right != NULL) q.push(node->right);
//
//    //        /* Enqueue left child */
//    //        if (node->left != NULL) q.push(node->left);
//
//    //        s.push(node);
//    //        q.pop();
//    //    }
//    //    while (s.size()) {
//    //        ans.push_back(s.top()->data);
//    //        s.pop();
//    //    }
//    //    return ans;
//    //}
//};