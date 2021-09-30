///*
//    link: https://www.geeksforgeeks.org/deletion-circular-linked-list/
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
//void deleteNode(Node* head, int key) {
//
//    // case 1: if head is null
//    if (head == NULL) return;
//
//    // case 2: if head is the only circular loop
//    if (head->next == head && head->data == key) {
//        free(head);
//        head = NULL;
//        return;
//    }
//
//    Node* last = head;
//
//    // case 3: if key is found at head only.
//    if (head->data == key) {
//        while (last->next != head) last = last->next;
//
//        // assigning the last's next to currently head's next
//        last->next = head->next;
//        free(head);
//
//        // assigning fresh address to head.
//        head = last->next;
//        return;
//    }
//
//    // case 4: if key is there in between.
//    while (last->next != head && last->next->data != key) {
//        last = last->next;
//    }
//
//    if (last->next->data == key) {
//        Node* d = last->next;
//        last->next = last->next->next;
//        free(d);
//        return;
//    }
//
//    // here if code reaches means key is not found.
//}