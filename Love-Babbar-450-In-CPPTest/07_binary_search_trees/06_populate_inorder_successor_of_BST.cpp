/*
    link: https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

    sol: https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
*/
#include "../06_binary_trees/01_level_order_traversal.cpp"
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(BTSort)
    {
    public:

        TEST_METHOD(Test)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}
// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using reverse inorder traversal
*/
/* Set next of p and all descendants of p by traversing them in reverse Inorder */
void populateNext(nodeBT* p)
{
    // The first visited nodeBT will be the
    // rightmost nodeBT next of the rightmost
    // nodeBT will be NULL
    static nodeBT* next = NULL;

    if (p)
    {
        // First set the next pointer
        // in right subtree
        populateNext(p->right);

        // Set the next as previously visited
        // nodeBT in reverse Inorder
        //p->next = next;

        // Change the prev for subsequent nodeBT
        next = p;

        // Finally, set the next pointer in
        // left subtree
        populateNext(p->left);
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by passing ref. variable
*/
// A wrapper over populateNextRecur
void populateNextRecur2(nodeBT* p, nodeBT** next_ref)
{
    if (p)
    {
        // First set the next pointer in right subtree
        populateNextRecur2(p->right, next_ref);

        // Set the next as previously visited
        // nodeBT in reverse Inorder
        //p->next = *next_ref;

        // Change the prev for subsequent nodeBT
        *next_ref = p;

        // Finally, set the next pointer in right subtree
        populateNextRecur2(p->left, next_ref);
    }
}
void populateNext2(nodeBT* root)
{
    // The first visited nodeBT will be the rightmost nodeBT
    // next of the rightmost nodeBT will be NULL
    nodeBT* next = NULL;

    populateNextRecur2(root, &next);
}

/* Set next of all descendents of p by
traversing them in reverse Inorder */
