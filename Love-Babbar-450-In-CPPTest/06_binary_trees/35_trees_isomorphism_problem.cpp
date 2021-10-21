///*
//    link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
//
//    sol: https://www.geeksforgeeks.org/tree-isomorphism-problem/
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
//
//class trees_isomorphism_problem
//{
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        Time Complexity:
//        The above solution does a traversal of both trees.
//        So time complexity is O(min(m,n)*2) or O(min(m,n)) where m and n are number of nodes in given trees.
//    */
//
//    // A C++ program to check if two given trees are isomorphic
//
//    /* A binary tree nodeBT has data, pointer to left and right children */
//
//    /* Given a binary tree, print its nodes in reverse level order */
//    bool isIsomorphic(nodeBT* n1, nodeBT* n2)
//    {
//        // Both roots are NULL, trees isomorphic by definition
//        if (n1 == NULL && n2 == NULL)
//            return true;
//
//        // Exactly one of the n1 and n2 is NULL, trees not isomorphic
//        if (n1 == NULL || n2 == NULL)
//            return false;
//
//        if (n1->data != n2->data)
//            return false;
//
//        // There are two possible cases for n1 and n2 to be isomorphic
//        // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
//        // Both of these subtrees have to be isomorphic, hence the &&
//        // Case 2: The subtrees rooted at these nodes have been "Flipped"
//        return
//            (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
//            (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
//    }
//
//    /* Helper function that allocates a new nodeBT with the
//    given data and NULL left and right pointers. */
//    nodeBT* newNode(int data)
//    {
//        nodeBT* temp = new nodeBT;
//        temp->data = data;
//        temp->left = NULL;
//        temp->right = NULL;
//
//        return (temp);
//    }
//
//    /* Driver program to test above functions*/
//    int main30()
//    {
//        // Let us create trees shown in above diagram
//        struct nodeBT* n1 = newNode(1);
//        n1->left = newNode(2);
//        n1->right = newNode(3);
//        n1->left->left = newNode(4);
//        n1->left->right = newNode(5);
//        n1->right->left = newNode(6);
//        n1->left->right->left = newNode(7);
//        n1->left->right->right = newNode(8);
//
//        struct nodeBT* n2 = newNode(1);
//        n2->left = newNode(3);
//        n2->right = newNode(2);
//        n2->right->left = newNode(4);
//        n2->right->right = newNode(5);
//        n2->left->right = newNode(6);
//        n2->right->right->left = newNode(8);
//        n2->right->right->right = newNode(7);
//
//        if (isIsomorphic(n1, n2) == true)
//            cout << "Yes";
//        else
//            cout << "No";
//
//        return 0;
//    }
//
//
//};
//
//
