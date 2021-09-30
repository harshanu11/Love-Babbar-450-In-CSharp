///*
//    link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
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
///*
//    using hashing
//    TC: O(N)
//    SC: O(N)
//*/
//Node* removeDuplicates(Node* head)
//{
//    unordered_set<int> s;
//    Node* curr = head;
//
//    // prev is address of last unique ele's pos.
//    Node* prev = NULL;
//
//    while (curr) {
//
//        // skip elements which are already present
//        while (curr && s.find(curr->data) != s.end()) {
//            prev->next = curr->next;
//            curr = curr->next;
//        }
//
//        // if till the end of LL all are included
//        if (curr == NULL) {
//            prev->next = NULL;
//            return head;
//        }
//
//        // element is unique add to set.
//        s.insert(curr->data);
//
//        // as current ele is unique set it's address to prev.
//        prev = curr;
//
//        // move ahead.
//        curr = curr->next;
//    }
//    return head;
//}
//
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using 2 loops
//    TC: O(n^2)
//    SC: O(1)
//*/
//void removeDuplicates1(struct Node* start)
//{
//    struct Node* ptr1, * ptr2, * dup;
//    ptr1 = start;
//
//    /* Pick elements one by one */
//    while (ptr1 != NULL && ptr1->next != NULL)
//    {
//        ptr2 = ptr1;
//
//        /* Compare the picked element with rest
//           of the elements */
//        while (ptr2->next != NULL)
//        {
//            /* If duplicate then delete it */
//            if (ptr1->data == ptr2->next->data)
//            {
//                /* sequence of steps is important here */
//                dup = ptr2->next;
//                ptr2->next = ptr2->next->next;
//                delete(dup);
//            }
//            else /* This is tricky */
//                ptr2 = ptr2->next;
//        }
//        ptr1 = ptr1->next;
//    }
//}
