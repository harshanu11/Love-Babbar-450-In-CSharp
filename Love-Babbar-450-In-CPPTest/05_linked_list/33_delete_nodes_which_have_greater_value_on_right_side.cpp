///*
//    link: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
//
//    there's another method of deleting the node which is smaller.
//
//    add this in code and it will work fine. (**but its optional**)
//    else {
//        next = curr->next;
//        curr->next = NULL;
//        free(curr);
//        curr = next;
//    }
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
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    by reversing the linklist
//
//    TC: O(N)
//    SC: O(1)
//*/
//Node* reverse(Node* head) {
//    Node* prev = NULL, * next = NULL, * curr = head;
//
//    while (curr) {
//        next = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = next;
//    }
//    return prev;
//}
//Node* compute(Node* head)
//{
//    head = reverse(head);
//
//    Node* prev = head, * curr = head->next, * next = NULL;
//
//    // code to directly attach greater or equal value of curr to prev.
//    while (curr) {
//        if (curr->data >= prev->data) {
//            prev->next = curr;
//            prev = curr;
//        }
//        curr = curr->next;
//    }
//
//    // prev's next should be NULL as no more >= data.
//    prev->next = NULL;
//
//    // again reverse the head.
//    head = reverse(head);
//
//    // return head.
//    return head;
//}
