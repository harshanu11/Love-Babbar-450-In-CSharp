using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _06_binary_trees
{
    public class _03_height_of_tree
    {

		/*
			link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

			sol: https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

			**note**: maximum depth of tree === height of the tree.
		*/


		[Fact]
		public void reverse_arrayTest()

		{
			NodeBinary o = new NodeBinary();
			NodeBinary root = o.newNode(1);
			root.left = o.newNode(2);
			root.right = o.newNode(3);
			root.left.left = o.newNode(4);
			root.left.right = o.newNode(5);
			var ans = height(root);
		}
		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			TC: O(N)
		*/
		private int height(NodeBinary node)
		{
			// if node is null, we return 0.
			if (node == null)
			{
				return 0;
			}

			//else we call the recursive function, height for left and right 
			//subtree and choose their maximum. we also add 1 to the result
			//which indicates height of root of the tree.
			else
			{
				int lHeight = height(node.left);
				int rHeight = height(node.right);

				if (lHeight > rHeight)
				{
					return lHeight + 1;
				}
				else
				{
					return rHeight + 1;
				}
			}
		}

	}
}
