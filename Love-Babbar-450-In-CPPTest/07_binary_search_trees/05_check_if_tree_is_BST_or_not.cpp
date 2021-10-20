///*
//	link: https://practice.geeksforgeeks.org/problems/check-for-bst/1
//
//	sol: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
//*/
//
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
//#include "03_min_max_value_in_BST.cpp"
//#include "../06_binary_trees/01_level_order_traversal.cpp"
//
//using namespace std;
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace LoveBabbar450InCPPTest
//{
//	TEST_CLASS(BTSort)
//	{
//	public:
//
//		TEST_METHOD(Test)
//		{
//			std::string charM = "harhs";
//			int age = 14;
//			age = 55;
//			std::string lastName = "<<charM <<singh";
//
//		}
//	};
//}
//// ----------------------------------------------------------------------------------------------------------------------- //
//// wrong method (as it won't compare with previous root)
//bool isBST(nodeBT* root)
//{
//	if (!root) return true;
//
//	if (root->left && root->left->data > root->data) return false;
//	if (root->right && root->right->data < root->data) return false;
//
//	return isBST(root->left) && isBST(root->right);
//}
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
//// Correct but not efficient
///* Returns true if a binary tree is a binary search tree */
//int isBST2(struct nodeBT* nodeBT)
//{
//	if (nodeBT == NULL)
//		return 1;
//
//	///* false if the max of the left is > than us */
//	//if (nodeBT->left != NULL && maxValue(nodeBT->left) > nodeBT->data)
//	//	return 0;
//
//	///* false if the min of the right is <= than us */
//	//if (nodeBT->right != NULL && minValue(nodeBT->right) < nodeBT->data)
//		return 0;
//
//	/* false if, recursively, the left or right is not a BST */
//	if (!isBST2(nodeBT->left) || !isBST2(nodeBT->right))
//		return 0;
//
//	/* passing all that, it's a BST */
//	return 1;
//}
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//	Correct and Efficient
//	TC: O(N)
//*/
////int isBSTUtil1(nodeBT* nodeBT, int min, int max);
////
/////* Returns true if the given
////tree is a binary search tree
////(efficient version). */
////int isBST3(nodeBT* nodeBT)
////{
////	return(isBSTUtil1(nodeBT, INT_MIN, INT_MAX));
////}
//
///* Returns true if the given
//tree is a BST and its values
//are >= min and <= max. */
////int isBSTUtil2(nodeBT* nodeBT, int min, int max)
////{
////	/* an empty tree is BST */
////	if (nodeBT == NULL)
////		return 1;
////
////	/* false if this nodeBT violates
////	the min/max constraint */
////	if (nodeBT->data < min || nodeBT->data > max)
////	{
////		return 0;
////	}
////
////
////	/* otherwise check the subtrees recursively,
////	tightening the min or max constraint */
////	return
////		isBSTUtil2(nodeBT->left, min, nodeBT->data - 1) && // Allow only distinct values
////		isBSTUtil2(nodeBT->right, nodeBT->data + 1, max); // Allow only distinct values
////}
//
//
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//	using null pointer
//*/
//// Returns true if given tree is BST.
//bool isBST6(nodeBT* root, nodeBT* l = NULL, nodeBT* r = NULL)
//{
//	// Base condition
//	if (root == NULL)
//		return true;
//
//	// if left nodeBT exist then check it has
//	// correct data or not i.e. left nodeBT's data
//	// should be less than root's data
//	if (l != NULL && root->data <= l->data)
//		return false;
//
//	// if right nodeBT exist then check it has
//	// correct data or not i.e. right nodeBT's data
//	// should be greater than root's data
//	if (r != NULL && root->data >= r->data)
//		return false;
//
//	// check recursively for every nodeBT.
//	return isBST6(root->left, l, root) &&
//		isBST6(root->right, root, r);
//}
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//	using in-order traversal
//*/
//bool isBST4(nodeBT* root)
//{
//	static nodeBT* prev = NULL;
//
//	// traverse the tree in inorder fashion
//	// and keep track of prev nodeBT
//	if (root)
//	{
//		if (!isBST4(root->left))
//			return false;
//
//		// Allows only distinct valued nodes
//		if (prev != NULL &&
//			root->data <= prev->data)
//			return false;
//
//		prev = root;
//
//		return isBST4(root->right);
//	}
//
//	return true;
//}
//
//
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//	using static variable
//*/
//bool isBSTUtil(struct nodeBT* root, nodeBT*& prev)
//{
//	// traverse the tree in inorder fashion and 
//	// keep track of prev nodeBT
//	if (root)
//	{
//		if (!isBSTUtil(root->left, prev))
//			return false;
//
//		// Allows only distinct valued nodes 
//		if (prev != NULL && root->data <= prev->data)
//			return false;
//
//		prev = root;
//
//		return isBSTUtil(root->right, prev);
//	}
//
//	return true;
//}
//
//bool isBST5(nodeBT* root)
//{
//	nodeBT* prev = NULL;
//	return isBSTUtil(root, prev);
//}