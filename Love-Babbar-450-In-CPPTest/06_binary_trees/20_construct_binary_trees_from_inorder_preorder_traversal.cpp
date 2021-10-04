///*
//    link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1
//
//    sol: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
//*/
//
//#include "01_level_order_traversal.cpp"
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
//    TEST_CLASS(BTSort)
//    {
//    public:
//
//        TEST_METHOD(Test)
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
//class construct_binary_trees_from_inorder_preorder_traversal
//{
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        Accepted solution (other are correct code but showing segmentation error, figured a lot but... :<( )
//    */
//    int findIndex(int arr[], int start, int target)
//    {
//        int i = 0;
//        while (arr[start + i] != target) i++;
//        return i;
//    }
//
//    nodeBT* buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
//    {
//        if (n == 0) return NULL;
//
//        nodeBT* ret = new nodeBT(preorder[preStart]);
//
//        int i = findIndex(inorder, inStart, preorder[preStart]);
//
//        ret->left = buildUtil(inorder, preorder, inStart, preStart + 1, i);
//        ret->right = buildUtil(inorder, preorder, inStart + i + 1, preStart + i + 1, n - i - 1);
//
//        return ret;
//    }
//
//    nodeBT* buildTree(int inorder[], int preorder[], int n)
//    {
//        return buildUtil(inorder, preorder, 0, 0, n);
//    }
//
//
//
//
//
//
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        using index
//
//        TC: O(N^2)
//    */
//
//    /* A binary tree nodeBT has data, pointer to left child
//    and a pointer to right child */
//
//
//    /* Prototypes for utility functions */
//    int search(char arr[], int strt, int end, char value);
//    nodeBT* newNode(char data);
//
//    /* Recursive function to construct binary
//    of size len from Inorder traversal in[]
//    and Preorder traversal pre[]. Initial values
//    of inStrt and inEnd should be 0 and len -1.
//    The function doesn't do any error checking
//    for cases where inorder and preorder do not
//    form a tree */
//    nodeBT* buildTree(char in[], char pre[], int inStrt, int inEnd)
//    {
//        static int preIndex = 0;
//
//        if (inStrt > inEnd)
//            return NULL;
//
//        /* Pick current nodeBT from Preorder
//        traversal using preIndex
//        and increment preIndex */
//        nodeBT* tNode = newNode(pre[preIndex++]);
//
//        /* If this nodeBT has no children then return */
//        if (inStrt == inEnd)
//            return tNode;
//
//        /* Else find the index of this nodeBT in Inorder traversal */
//        int inIndex = search(in, inStrt, inEnd, tNode->data);
//
//        /* Using index in Inorder traversal, construct left and
//        right subtress */
//        tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
//        tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
//
//        return tNode;
//    }
//
//    /* UTILITY FUNCTIONS */
//    /* Function to find index of value in arr[start...end]
//    The function assumes that value is present in in[] */
//    int search(char arr[], int strt, int end, char value)
//    {
//        int i;
//        for (i = strt; i <= end; i++)
//        {
//            if (arr[i] == value)
//                return i;
//        }
//    }
//
//    /* Helper function that allocates a new nodeBT with the
//    given data and NULL left and right pointers. */
//    nodeBT* newNode(char data)
//    {
//        nodeBT* nodeBT;
//        nodeBT->data = data;
//        nodeBT->left = NULL;
//        nodeBT->right = NULL;
//
//        return (nodeBT);
//    }
//
//    /* This funtcion is here just to test buildTree() */
//    void printInorder(nodeBT* nodeBT)
//    {
//        if (nodeBT == NULL)
//            return;
//
//        /* first recur on left child */
//        printInorder(nodeBT->left);
//
//        /* then print the data of nodeBT */
//        cout << nodeBT->data << " ";
//
//        /* now recur on right child */
//        printInorder(nodeBT->right);
//    }
//
//    /* Driver code */
//    int main()
//    {
//        char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
//        char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
//        int len = sizeof(in) / sizeof(in[0]);
//        nodeBT* root = buildTree(in, pre, 0, len - 1);
//
//        /* Let us test the built tree by
//        printing Insorder traversal */
//        cout << "Inorder traversal of the constructed tree is \n";
//        printInorder(root);
//    }
//
//
//
//
//
//
//
//
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        using hashing (to search in O(1))
//        TC: O(N)
//    */
//    /* C++ program to construct tree using inorder
//    and preorder traversals */
//
//    /* A binary tree nodeBT has data, pointer to left child
//    and a pointer to right child */
//
//    struct nodeBT* newNode(char data)
//    {
//         nodeBT* nodeBT =  nodeBT;
//        nodeBT->data = data;
//        nodeBT->left = nodeBT->right = NULL;
//        return (nodeBT);
//    }
//
//    /* Recursive function to construct binary of size
//    len from Inorder traversal in[] and Preorder traversal
//    pre[]. Initial values of inStrt and inEnd should be
//    0 and len -1. The function doesn't do any error
//    checking for cases where inorder and preorder
//    do not form a tree */
//    struct nodeBT* buildTree(char in[], char pre[], int inStrt,
//        int inEnd, unordered_map<char, int>& mp)
//    {
//        static int preIndex = 0;
//
//        if (inStrt > inEnd)
//            return NULL;
//
//        /* Pick current nodeBT from Preorder traversal using preIndex
//        and increment preIndex */
//        char curr = pre[preIndex++];
//        struct nodeBT* tNode = newNode(curr);
//
//        /* If this nodeBT has no children then return */
//        if (inStrt == inEnd)
//            return tNode;
//
//        /* Else find the index of this nodeBT in Inorder traversal */
//        int inIndex = mp[curr];
//
//        /* Using index in Inorder traversal, construct left and
//        right subtress */
//        tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
//        tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
//
//        return tNode;
//    }
//
//    // This function mainly creates an unordered_map, then
//    // calls buildTree()
//    struct nodeBT* buldTreeWrap(char in[], char pre[], int len)
//    {
//        // Store indexes of all items so that we
//        // we can quickly find later
//        unordered_map<char, int> mp;
//        for (int i = 0; i < len; i++)
//            mp[in[i]] = i;
//
//        return buildTree(in, pre, 0, len - 1, mp);
//    }
//
//    /* This funtcion is here just to test buildTree() */
//    void printInorder(struct nodeBT* nodeBT)
//    {
//        if (nodeBT == NULL)
//            return;
//        printInorder(nodeBT->left);
//        printf("%c ", nodeBT->data);
//        printInorder(nodeBT->right);
//    }
//
//    /* Driver program to test above functions */
//    int main1()
//    {
//        char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
//        char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
//        int len = sizeof(in) / sizeof(in[0]);
//
//        struct nodeBT* root = buldTreeWrap(in, pre, len);
//
//        /* Let us test the built tree by printing
//        Insorder traversal */
//        printf("Inorder traversal of the constructed tree is \n");
//        printInorder(root);
//    }
//
//
//
//
//
//
//    // ----------------------------------------------------------------------------------------------------------------------- //
//    /*
//        using stack and queue
//    */
//
//    set<nodeBT*> s;
//    stack<nodeBT*> st;
//
//    // Function to build tree using given traversal
//    nodeBT* buildTree(int preorder[], int inorder[], int n)
//    {
//
//        nodeBT* root = NULL;
//        for (int pre = 0, in = 0; pre < n;)
//        {
//
//            nodeBT* nodeBT = NULL;
//            do
//            {
//               // nodeBT =  nodeBT(preorder[pre]);
//                if (root == NULL)
//                {
//                    root = nodeBT;
//                }
//                if (st.size() > 0)
//                {
//                    if (s.find(st.top()) != s.end())
//                    {
//                        s.erase(st.top());
//                        st.top()->right = nodeBT;
//                        st.pop();
//                    }
//                    else
//                    {
//                        st.top()->left = nodeBT;
//                    }
//                }
//                st.push(nodeBT);
//            } while (preorder[pre++] != inorder[in] && pre < n);
//
//            nodeBT = NULL;
//            while (st.size() > 0 && in < n &&
//                st.top()->data == inorder[in])
//            {
//                nodeBT = st.top();
//                st.pop();
//                in++;
//            }
//
//            if (nodeBT != NULL)
//            {
//                s.insert(nodeBT);
//                st.push(nodeBT);
//            }
//        }
//
//        return root;
//    }
//
//};
//
//construct_binary_trees_from_inorder_preorder_traversal::construct_binary_trees_from_inorder_preorder_traversal()
//{
//}
//
//construct_binary_trees_from_inorder_preorder_traversal::~construct_binary_trees_from_inorder_preorder_traversal()
//{
//}
//
