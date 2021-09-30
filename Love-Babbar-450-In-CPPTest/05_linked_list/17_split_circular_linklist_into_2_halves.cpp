///*
//    link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
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
//    using size
//*/
//void splitList(Node* head, Node** head1_ref, Node** head2_ref)
//{
//    // your code goes here
//    int size = 1;
//
//    // to point at last node (just before the head node)
//    Node* last = head;
//    while (last->next != head) {
//        size++;
//        last = last->next;
//    }
//
//    // if size is even we have to reduce size.
//    if (size % 2 == 0) size--;
//    size = size / 2;
//
//    // this pointer will be at middle
//    Node* middle = head;
//    for (int i = 0;i < size;i++) {
//        middle = middle->next;
//    }
//
//    // attach head1_ref at 1st linklist part
//    *head1_ref = head;
//    // attach head2_ref at 2nd linklist part
//    *head2_ref = middle->next;
//
//    // making 1st part of linklist circular
//    middle->next = *head1_ref;
//    // making 2nd part of linklist circular
//    last->next = *head2_ref;
//}
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using slow-fast pointer
//*/
////void splitList(Node* head, Node** head1_ref, Node** head2_ref)
////{
////    Node* slow = head, * fast = head;
////
////    while (fast->next != head and fast->next->next != head) {
////        slow = slow->next;
////        fast = fast->next->next;
////    }
////
////    // now for even size linklist we have move fast pointer 1 more time (trace the code for even length linklist)
////    if (fast->next->next == head) {
////        fast = fast->next;
////    }
////
////    // assign each head_ref to its own part 
////    *head1_ref = head;
////    *head2_ref = slow->next;
////
////    // completing the cycle and attaching the last node to its own head.
////    slow->next = *head1_ref;
////    fast->next = *head2_ref;
////}