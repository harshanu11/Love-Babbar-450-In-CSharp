using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _06_binary_trees
{
    public class _05_mirror_of_tree
    {
        [Fact]
        public void reverse_arrayTest() { }



		/*
			link: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
		*/



		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			by swapping the left and right sub-tree
		*/


		// Helper function that
		// allocates a new NodeBinary with the
		// given data and NULL left and right pointers
		public static NodeBinary createNode(int val)
		{
			NodeBinary newNode = new NodeBinary();
			newNode.data = val;
			newNode.left = null;
			newNode.right = null;
			return newNode;
		}

		// Function to print the inrder traversal
		public void inorder(NodeBinary root)
		{
			if (root == null)
			{
				return;
			}
			inorder(root.left);
			Debug.Write(root.data);
			inorder(root.right);
		}

		// Function to convert to mirror tree
		public static NodeBinary mirrorTree(NodeBinary root)
		{
			// Base Case
			if (root == null)
			{
				return root;
			}
			NodeBinary t = root.left;
			root.left = root.right;
			root.right = t;

			if (root.left != null)
			{
				mirrorTree(root.left);
			}
			if (root.right != null)
			{
				mirrorTree(root.right);
			}

			return root;
		}

		// Driver Code
		internal static void Main2()
		{

			NodeBinary tree = createNode(5);
			tree.left = createNode(3);
			tree.right = createNode(6);
			tree.left.left = createNode(2);
			tree.left.right = createNode(4);
			Debug.Write("Inorder of original tree: ");
			//inorder1(tree);

			// Function call
			mirrorTree(tree);

			Debug.Write("\nInorder of Miror tree: ");
			//inorder1(tree);
		}

		// Helper function that allocates a new NodeBinary with the
		// given data and NULL left and right pointers
		//C++ TO C# CONVERTER TODO TASK: The typedef 'NodeBinary' was defined in multiple preprocessor conditionals and cannot be replaced in-line:
		public static NodeBinary createNode1(int val)
		{
			//C++ TO C# CONVERTER TODO TASK: The typedef 'NodeBinary' was defined in multiple preprocessor conditionals and cannot be replaced in-line:
			NodeBinary newNode = new NodeBinary();
			newNode.data = val;
			newNode.left = null;
			newNode.right = null;
			return newNode;
		}

		// Helper function to print Inorder traversal
		//C++ TO C# CONVERTER TODO TASK: The typedef 'NodeBinary' was defined in multiple preprocessor conditionals and cannot be replaced in-line:
		public  void inorder1(NodeBinary root)
		{
			if (root == null)
			{
				return;
			}
			inorder(root.left);
			Debug.Write(root.data);
			inorder(root.right);
		}

		// mirrorify function takes two trees,
		// original tree and a mirror tree
		// It recurses on both the trees,
		// but when original tree recurses on left,
		// mirror tree recurses on right and
		// vice-versa
		//C++ TO C# CONVERTER TODO TASK: The typedef 'NodeBinary' was defined in multiple preprocessor conditionals and cannot be replaced in-line:
		public static void mirrorify(NodeBinary root, NodeBinary mirror)
		{
			if (root == null)
			{
				mirror = null;
				return;
			}

			// Create new mirror NodeBinary from original tree NodeBinary
			mirror = createNode(root.data);
			mirrorify(root.left, (mirror.right));
			mirrorify(root.right, (mirror.left));
		}

		// Driver code
		internal static void Main3()
		{

			//C++ TO C# CONVERTER TODO TASK: The typedef 'NodeBinary' was defined in multiple preprocessor conditionals and cannot be replaced in-line:
			NodeBinary tree = createNode(5);
			tree.left = createNode(3);
			tree.right = createNode(6);
			tree.left.left = createNode(2);
			tree.left.right = createNode(4);

			// Print inorder traversal of the input tree
			Debug.Write("Inorder of original tree: ");
			//inorder(tree);
			//C++ TO C# CONVERTER TODO TASK: The typedef 'NodeBinary' was defined in multiple preprocessor conditionals and cannot be replaced in-line:
			NodeBinary mirror = null;
			mirrorify(tree, mirror);

			// Print inorder traversal of the mirror tree
			Debug.Write("\nInorder of mirror tree: ");
			//inorder(mirror);

		}








		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			by making separate mirror tree
		*/
		// C implementation of the approach

		// A binary tree NodeBinary has data, pointer to
		// left child and a pointer to right child



}
}
/*
    link: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    by swapping the left and right sub-tree
//*/

//#include <iostream>
//using namespace std;

//typedef struct treenode
//{
//	int val;
//	struct treenode* left;
//    struct treenode* right;
//}
//node;

//// Helper function that
//// allocates a new node with the
//// given data and NULL left and right pointers
//node* createNode(int val)
//{
//	node* newNode = (node*)malloc(sizeof(node));
//	newNode->val = val;
//	newNode->left = NULL;
//	newNode->right = NULL;
//	return newNode;
//}

//// Function to print the inrder traversal
//void inorder(node* root)
//{
//	if (root == NULL)
//		return;
//	inorder(root->left);
//	printf("%d ", root->val);
//	inorder(root->right);
//}

//// Function to convert to mirror tree
//treenode* mirrorTree(node* root)
//{
//	// Base Case
//	if (root == NULL)
//		return root;
//	node* t = root->left;
//	root->left = root->right;
//	root->right = t;

//	if (root->left)
//		mirrorTree(root->left);
//	if (root->right)
//		mirrorTree(root->right);

//	return root;
//}

//// Driver Code
//int main()
//{

//	node* tree = createNode(5);
//	tree->left = createNode(3);
//	tree->right = createNode(6);
//	tree->left->left = createNode(2);
//	tree->left->right = createNode(4);
//	printf("Inorder of original tree: ");
//	inorder(tree);

//	// Function call
//	mirrorTree(tree);

//	printf("\nInorder of Miror tree: ");
//	inorder(tree);
//	return 0;
//}








//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    by making separate mirror tree
//*/
//// C implementation of the approach
//# include <malloc.h>
//# include <stdio.h>

//// A binary tree node has data, pointer to
//// left child and a pointer to right child
//typedef struct treenode
//{
//	int val;
//	struct treenode* left;
//    struct treenode* right;
//}
//node;

//// Helper function that allocates a new node with the
//// given data and NULL left and right pointers
//node* createNode(int val)
//{
//	node* newNode = (node*)malloc(sizeof(node));
//	newNode->val = val;
//	newNode->left = NULL;
//	newNode->right = NULL;
//	return newNode;
//}

//// Helper function to print Inorder traversal
//void inorder(node* root)
//{
//	if (root == NULL)
//		return;
//	inorder(root->left);
//	printf("%d ", root->val);
//	inorder(root->right);
//}

//// mirrorify function takes two trees,
//// original tree and a mirror tree
//// It recurses on both the trees,
//// but when original tree recurses on left,
//// mirror tree recurses on right and
//// vice-versa
//void mirrorify(node* root, node** mirror)
//{
//	if (root == NULL)
//	{
//		mirror = NULL;
//		return;
//	}

//	// Create new mirror node from original tree node
//	*mirror = createNode(root->val);
//	mirrorify(root->left, &((*mirror)->right));
//	mirrorify(root->right, &((*mirror)->left));
//}

//// Driver code
//int main()
//{

//	node* tree = createNode(5);
//	tree->left = createNode(3);
//	tree->right = createNode(6);
//	tree->left->left = createNode(2);
//	tree->left->right = createNode(4);

//	// Print inorder traversal of the input tree
//	printf("Inorder of original tree: ");
//	inorder(tree);
//	node* mirror = NULL;
//	mirrorify(tree, &mirror);

//	// Print inorder traversal of the mirror tree
//	printf("\nInorder of mirror tree: ");
//	inorder(mirror);

//	return 0;
//}
