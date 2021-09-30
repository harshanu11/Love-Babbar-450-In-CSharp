///*
//    link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
//
//    sol: https://www.geeksforgeeks.org/flattening-a-linked-list/
//*/
//
//#include "01_reverse_linklist.cpp"
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
//    TEST_CLASS(SearchSort)
//    {
//    public:
//
//        TEST_METHOD(find1Test)
//        {
//            std::string charM = "harhs";
//            int age = 14;
//            age = 55;
//            std::string lastName = "<<charM <<singh";
//
//        }
//    };
//}
//// ----------------------------------------------------------------------------------------------------------------------- //
//// An utility function to merge two sorted linked lists
//Node* merge(Node* a, Node* b) {
//
//    // if first linked list is empty then second is the answer
//    if (a == NULL) return b;
//
//    // if second linked list is empty then first is the answer
//    if (b == NULL) return a;
//
//    // compare the data members of the two linked lists
//    // and put the larger one in the result
//    Node* result;
//
//    if (a->data < b->data) {
//        result = a;
//        result->bottom = merge(a->bottom, b);
//    }
//    else {
//        result = b;
//        result->bottom = merge(a, b->bottom);
//    }
//    result->next = NULL;
//    return result;
//}
//
//Node* flatten(Node* root)
//{
//    // base condition
//    if (root == NULL || root->next == NULL) return root;
//
//    // recur the LL in next till end so that we can flatten last 2 node.
//    root->next = flatten(root->next);
//
//    // now merge both 
//    root = merge(root, root->next);
//
//    // it will be merged LL in bottom of the smaller node.
//    return root;
//}
