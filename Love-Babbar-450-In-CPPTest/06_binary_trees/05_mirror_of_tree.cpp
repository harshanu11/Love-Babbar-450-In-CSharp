/*
    link: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
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
// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by swapping the left and right sub-tree
*/

class mirror_of_tree
{

    //typedef struct nodeBT {
    //    int val;
    //    struct nodeBT* left;
    //    struct nodeBT* right;
    //} nodeBT;

    // Helper function that
    // allocates a new nodeBT with the
    // given data and NULL left and right pointers
    nodeBT* createNode(int val)
    {
        nodeBT* newNode = (nodeBT*)malloc(sizeof(nodeBT));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    //// Function to print the inrder traversal
    //void inorder(nodeBT* root)
    //{
    //    if (root == NULL)
    //        return;
    //    inorder(root->left);
    //    printf("%d ", root->data);
    //    inorder(root->right);
    //}

    // Function to convert to mirror tree
    nodeBT* mirrorTree(nodeBT* root)
    {
        // Base Case
        if (root == NULL)
            return root;
        nodeBT* t = root->left;
        root->left = root->right;
        root->right = t;

        if (root->left)
            mirrorTree(root->left);
        if (root->right)
            mirrorTree(root->right);

        return root;
    }

    // Driver Code
    int main()
    {

        nodeBT* tree = createNode(5);
        tree->left = createNode(3);
        tree->right = createNode(6);
        tree->left->left = createNode(2);
        tree->left->right = createNode(4);
        printf("Inorder of original tree: ");
        //inorder(tree);

        // Function call
        mirrorTree(tree);

        printf("\nInorder of Miror tree: ");
        //inorder(tree);
        return 0;
    }








    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        by making separate mirror tree
    */
    // C implementation of the approach


// A binary tree nodeBT has data, pointer to
// left child and a pointer to right child
    //typedef struct nodeBT {
    //    int val;
    //    struct nodeBT* left;
    //    struct nodeBT* right;
    //} nodeBT;

    // Helper function that allocates a new nodeBT with the
    // given data and NULL left and right pointers
    //nodeBT* createNode(int val)
    //{
    //    nodeBT* newNode = (nodeBT*)malloc(sizeof(nodeBT));
    //    newNode->val = val;
    //    newNode->left = NULL;
    //    newNode->right = NULL;
    //    return newNode;
    //}

    // Helper function to print Inorder traversal
    //void inorder(nodeBT* root)
    //{
    //    if (root == NULL)
    //        return;
    //    inorder(root->left);
    //    printf("%d ", root->data);
    //    inorder(root->right);
    //}

    // mirrorify function takes two trees,
    // original tree and a mirror tree
    // It recurses on both the trees,
    // but when original tree recurses on left,
    // mirror tree recurses on right and
    // vice-versa
    void mirrorify(nodeBT* root, nodeBT** mirror)
    {
        if (root == NULL) {
            mirror = NULL;
            return;
        }

        // Create new mirror nodeBT from original tree nodeBT
        *mirror = createNode(root->data);
        mirrorify(root->left, &((*mirror)->right));
        mirrorify(root->right, &((*mirror)->left));
    }

    // Driver code
    int main1()
    {

        nodeBT* tree = createNode(5);
        tree->left = createNode(3);
        tree->right = createNode(6);
        tree->left->left = createNode(2);
        tree->left->right = createNode(4);

        // Print inorder traversal of the input tree
        printf("Inorder of original tree: ");
        //inorder(tree);
        nodeBT* mirror = NULL;
        mirrorify(tree, &mirror);

        // Print inorder traversal of the mirror tree
        printf("\nInorder of mirror tree: ");
        //inorder(mirror);

        return 0;
    }

};



