/*
	link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

	sol: https://www.geeksforgeeks.org/level-order-tree-traversal/
*/

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
//#ifndef AAA_HEADER
#define AAA_HEADER
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/* A binary tree nodeBT has data,
pointer to left child
and a pointer to right child */
//#pragma once
//class nodeBT
//{
//public:
//	int data;
//	nodeBT* left, * right;
//	int c = 0;
//	int hd;
//	nodeBT() {}
//	nodeBT(int d)
//	{
//		nodeBT* nodeBT{};
//		nodeBT->data = d;
//		nodeBT->left = NULL;
//		nodeBT->right = NULL;
//	}
//};
class nodeBT
{
	public:
	int data;
	nodeBT* left, * right;
	nodeBT* node;

	//nodeBT() {}
	nodeBT(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
namespace LoveBabbar450InCPPTest1
{
	TEST_CLASS(BTTest)
	{
	public:

		TEST_METHOD(BTLevelOrderTraversalTest)
		{
			nodeBT* root = new nodeBT(1);
			root->left = new nodeBT(2);
			root->right = new nodeBT(3);
			root->left->left = new nodeBT(4);
			root->left->right = new nodeBT(5);

			cout << "Level Order traversal of binary tree is \n";
			printLevelOrderBT(root);

		}
		// ----------------------------------------------------------------------------------------------------------------------- //
/*
	by printing current level

	Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes
		O(n) time where n is the number of nodes in the skewed tree.
		So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).

	Space Complexity: O(n) in worst case. For a skewed tree, printGivenLevel() uses
		O(n) space for call stack. For a Balanced tree, the call stack uses O(log n) space,
		(i.e., the height of the balanced tree).
*/
// Recursive CPP program for level
// order traversal of Binary Tree



	/* Print nodes at a current level */
		void printCurrentLevelBT(nodeBT* root, int level)
		{
			if (root == NULL)
				return;
			if (level == 1)
				cout << root->data << " ";
			else if (level > 1)
			{
				printCurrentLevelBT(root->left, level - 1);
				printCurrentLevelBT(root->right, level - 1);
			}
		}
		// Function to print the inrder traversal
		void inorderBT(nodeBT* root)
		{
			if (root == NULL)
				return;
			inorderBT(root->left);
			printf("%d ", root->data);
			inorderBT(root->right);
		}
		// A utility function to do inorder traversal of BST
		//static void inorder1BT(struct nodeBT* root, int s)
		//{
		//	if (root != NULL) {
		//		inorder1BT(root->left, s);

		//		if (root->c > (s / 2))
		//			printf("%d \n", root->data);

		//		inorder1BT(root->right, s);
		//	}
		//}

		/* Compute the "height" of a tree -- the number of
			nodes along the longest path from the root nodeBT
			down to the farthest leaf nodeBT.*/
		int heightBT(nodeBT* nodeBT)
		{
			if (nodeBT == NULL)
				return 0;
			else
			{
				/* compute the height of each subtree */
				int lheight = heightBT(nodeBT->left);
				int rheight = heightBT(nodeBT->right);

				/* use the larger one */
				if (lheight > rheight)
				{
					return(lheight + 1);
				}
				else {
					return(rheight + 1);
				}
			}
		}

		/* Helper function that allocates
		a new nodeBT with the given data and
		NULL left and right pointers. */
		nodeBT* newNodeBT(int data)
		{
			nodeBT* nodeBT;
			nodeBT->data = data;
			nodeBT->left = NULL;
			nodeBT->right = NULL;

			return(nodeBT);
		}

		static void preorderBT(nodeBT* root)
		{
			if (root == NULL)
				return;
			cout << root->data << " ";
			preorderBT(root->left);
			preorderBT(root->right);
		}

		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			using queue
			TC: O(N)
			SC: O(N)
			---> where n is the number of nodes in the binary trees
		*/
		void printLevelOrderBT(nodeBT* root)
		{
			// Base Case
			if (root == NULL)  return;

			// Create an empty queue for level order traversal
			queue<nodeBT*> q;

			// Enqueue Root and initialize height
			q.push(root);

			while (q.empty() == false)
			{
				// Print front of queue and remove it from queue
				nodeBT* nodeBT = q.front();
				cout << nodeBT->data << " ";
				q.pop();

				/* Enqueue left child */
				if (nodeBT->left != NULL)
					q.push(nodeBT->left);

				/*Enqueue right child */
				if (nodeBT->right != NULL)
					q.push(nodeBT->right);
			}
		}

	};
}












