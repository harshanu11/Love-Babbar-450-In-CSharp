/*
    link: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

    sol: https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/
    video: https://youtu.be/_j7yb_nWFO8
*/

#include "01_level_order_traversal.cpp"
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
    //TEST_CLASS(BTSort)
    //{
    //public:

    //    TEST_METHOD(Test)
    //    {
    //        std::string charM = "harhs";
    //        int age = 14;
    //        age = 55;
    //        std::string lastName = "<<charM <<singh";

    //    }
    //};
}
class check_if_BT_contains_duplicate_subtree_of_size_2
{
    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using hashMap
        TC: O(N)
    */
    unordered_map<string, int> m;
    string recur(nodeBT* root) {
        // base case
        if (!root) return "$";

        string s;
        // it it's leaf nodeBT
        if (!root->left && !root->right) {
            s = to_string(root->data);
            return s;
        }

        // if it's not leaf nodeBT make string...
        s += to_string(root->data);
        s += recur(root->left);
        s += recur(root->right);

        // increase count of it.
        m[s]++;

        // and return current string for parent
        return s;
    }
    bool dupSub1(nodeBT* root)
    {
        m.clear();          // this is necessary as life of global variable is till all code are executed.
        recur(root);

        // if any string appear twice means duplication
        for (auto i : m) {
            if (i.second >= 2) return true;
        }
        return false;
    }





    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using hashSet
        TC: O(N)
    */
    unordered_set<string> s;
    string recur(nodeBT* root, bool& ans) {
        // base case
        if (!root) return "$";

        string str;
        // it it's leaf nodeBT
        if (!root->left && !root->right) {
            str = to_string(root->data);
            return str;
        }

        // if it's not leaf nodeBT make string...
        str += to_string(root->data);
        str += recur(root->left);
        str += recur(root->right);


        // if string is found in hashSet then set ans = true;
        if (s.find(str) != s.end()) ans = true;

        s.insert(str);

        // and return current string for parent
        return str;
    }
    bool dupSub2(nodeBT* root)
    {
        s.clear();          // this is necessary as life of global variable is till all codes are executed.

        bool ans = false;
        recur(root, ans);

        return ans;
    }








    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        another form of code.
        TC: O(N)
    */

    const char MARKER = '$';
    unordered_set<string> subtrees;

    // This function returns empty string if tree
    // contains a duplicate subtree of size 2 or more.
    string dupSubUtil(nodeBT* root)
    {
        string s = "";

        // If current nodeBT is NULL, return marker
        if (root == NULL) return s + MARKER;

        // If left subtree has a duplicate subtree.
        string lStr = dupSubUtil(root->left);
        if (lStr.compare(s) == 0) return s;

        // Do same for right subtree
        string rStr = dupSubUtil(root->right);
        if (rStr.compare(s) == 0)
            return s;

        // Serialize current subtree
        s = s + to_string(root->data) + lStr + rStr;

        // If current subtree already exists in hash
        // table. [Note that size of a serialized tree
        // with single nodeBT is 3 as it has two marker
        // nodes.
        if ((rStr != "$" || lStr != "$") &&
            subtrees.find(s) != subtrees.end())
            return "";

        subtrees.insert(s);

        return s;
    }
    bool dupSub3(nodeBT* root)
    {
        //your code here
        subtrees.clear();
        return dupSubUtil(root) == "";
    }


};

