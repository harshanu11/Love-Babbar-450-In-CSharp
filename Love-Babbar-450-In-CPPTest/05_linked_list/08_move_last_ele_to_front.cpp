///*
//    link: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
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
//void moveToFront(Node* head) {
//
//    if (head == NULL || head->next == NULL) return;
//
//    // to get address of last node
//    Node* last = head;
//
//    // to get address second last node
//    Node* second_last = NULL;
//
//    // iterate till the end
//    while (last->next != NULL) {
//        //prev = last;
//        last = last->next;
//    }
//
//    // second last will point to NULL
//    second_last->next = NULL;
//
//    // last node will point to first node
//    last->next = head;
//
//    // head will point to fresh node.
//    head->next = last;
//}