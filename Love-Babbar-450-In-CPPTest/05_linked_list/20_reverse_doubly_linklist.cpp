///*
//    link: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
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
///*
//    TC: O(N)
//    SC: O(1)
//*/
//Node* reverseDLL(Node* head)
//{
//    //Your code here
//    Node* curr = head, * next = NULL, * prev = NULL;
//
//    while (curr) {
//
//        // saving next of current node in "next" named node
//        next = curr->next;
//
//        // current node's next is prev value.
//        curr->next = prev;
//
//        // current node's prev will be next named node
//        curr->prev = next;
//
//        // setting up prev and curr for future iteration.
//        prev = curr;
//        curr = next;
//    }
//
//    // assigning head to last node 
//    head = prev;
//    return head;
//}
//
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using stack
//    TC: O(N)
//    SC: O(N)
//*/
//void reverse()
//{
//    stack<int> st;
//    Node* temp = head;
//    while (temp != NULL) {
//        st.push(temp->data);
//        temp = temp->next;
//    }
//
//    // added all the elements sequemce wise in the
//    // st
//    temp = head;
//    while (temp != NULL) {
//        temp->data = st.top();
//        st.pop();
//        temp = temp->next;
//    }
//
//    // popped all the elements and the added in the
//    // linked list,
//    // which are in the reversed order->
//}