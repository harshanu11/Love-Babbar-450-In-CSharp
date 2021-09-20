using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _07_binary_search_trees
{
    public class _02_deletion_of_node_in_BST
    {
		/*
			 link: https://leetcode.com/problems/delete-node-in-a-bst/

			 video: https://youtu.be/5_AZcOOc-kM
		*/

		[Fact]
		public void Test() 
		{
			NodeBinary root = new NodeBinary();
			root.InsertBST(root, 5);
			root.InsertBST(root, 3);
			root.InsertBST(root, 6);
			root.InsertBST(root, 2);
			root.InsertBST(root, 4);
			root.InsertBST(root, 7);

			var ans = deleteNode(root,3);
		}


		// ----------------------------------------------------------------------------------------------------------------------- //
		private NodeBinary deleteNode(NodeBinary root, int key)
		{
			// base case
			if (root == null)
			{
				return null;
			}

			// if value of root matches with the key
			if (root.data == key)
			{

				// if there is no right child then simply attach root's parent with root's child
				if (root.right != null)
				{
					NodeBinary left = root.left;
					root = null;
					return left;
				}
				// if there is no left child then simply attach root's parent with root's child
				else if (root.left != null)
				{
					NodeBinary right = root.right;
					root = null;
					return right;
				}
				// then swap with the right-subtrees' smallest child with curr-value, also BST won't change (trace it!)
				// alternative way we can also swap left-subtrees' greatest child with curr-value, still BST won't change
				else
				{
					NodeBinary right = root.right;
					while (right.left != null)
					{
						right = right.left;
					}
					//swap(root.data, right.data);
					root.data = root.data ^ right.data;
					right.data = root.data ^ right.data;
					root.data = root.data ^ right.data;
				}
			}

			// get deleted and arranged root from the recursion
			root.left = deleteNode(root.left, key);
			root.right = deleteNode(root.right, key);
			return root;
		}

	}
}
/*
    link: https://leetcode.com/problems/delete-node-in-a-bst/

    video: https://youtu.be/5_AZcOOc-kM
*/




//// ----------------------------------------------------------------------------------------------------------------------- //
//TreeNode* deleteNode(TreeNode* root, int key)
//{
//	// base case
//	if (!root) return NULL;

//	// if value of root matches with the key
//	if (root->val == key)
//	{

//		// if there is no right child then simply attach root's parent with root's child
//		if (!root->right)
//		{
//			TreeNode* left = root->left;
//			delete root;
//			return left;
//		}
//		// if there is no left child then simply attach root's parent with root's child
//		else if (!root->left)
//		{
//			TreeNode* right = root->right;
//			delete root;
//			return right;
//		}
//		// then swap with the right-subtrees' smallest child with curr-value, also BST won't change (trace it!)
//		// alternative way we can also swap left-subtrees' greatest child with curr-value, still BST won't change
//		else
//		{
//			TreeNode* right = root->right;
//			while (right->left)
//			{
//				right = right->left;
//			}
//			swap(root->val, right->val);
//		}
//	}

//	// get deleted and arranged root from the recursion
//	root->left = deleteNode(root->left, key);
//	root->right = deleteNode(root->right, key);
//	return root;
//}
