///*
//    link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
//
//    sol: https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
//*/
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
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using the size of LL.
//    TC: O(N)
//    SC: O(1)
//*/
//
//// returns size of LL
//int size(Node* temp) {
//    Node* head = temp;
//    int count = 0;
//    while (head) {
//        count++;
//        head = head->next;
//    }
//    return count;
//}
//int getNthFromLast(Node* head, int n)
//{
//    // size of LL
//    int sz = size(head);
//
//    // if desired node is out of size
//    if (sz - n < 0) return -1;
//
//    // iterate till the desired node 
//    // eg. if n=2 and size=9 then from 0 to (9-2) means it will iterate 8 times.
//    for (int i = 0;i < sz - n;i++) {
//        head = head->next;
//    }
//    return head->data;
//}
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    2 pointer
//*/
//int getNthFromLast(Node* head, int n)
//{
//    Node* left = head, * right = head;
//
//    // first make distance of left and right of n.
//    while (n && right) {
//        right = right->next;
//        n--;
//    }
//
//    // check if the size of n is large than size of LL.
//    if (right == NULL && n > 0) return -1;
//
//    // now move both the pointer 1 node at a time.
//    while (right) {
//        left = left->next;
//        right = right->next;
//    }
//
//    // at last left pointer will be at desired node.
//    return left->data;
//}
