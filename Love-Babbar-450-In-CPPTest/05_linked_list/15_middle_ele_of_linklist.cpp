///*
//    link: https://leetcode.com/problems/middle-of-the-linked-list/submissions/
//
//
//    case 1: fast->next will be NULL
//            1->2->3->4->5       when fast->next will be NULL slow will be at 3.
//
//    case 2: fast->next->next will be NULL
//            1->2->3->4->5->6    when fast->next->next will be NULL slow will be at 4.
//
//
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
//// ----------------------------------------------------------------------------------------------------------------------- //
////ListNode* middleNode(ListNode* head) {
////    ListNode* slow = head;
////    ListNode* fast = head;
////
////    while (fast->next) {
////        // slow pointer jumps 1 at a time
////        slow = slow->next;
////
////        if (fast->next->next == NULL) break;
////
////        // fast pointer jumps 2 at a time
////        fast = fast->next->next;
////    }
////    return slow;
////}