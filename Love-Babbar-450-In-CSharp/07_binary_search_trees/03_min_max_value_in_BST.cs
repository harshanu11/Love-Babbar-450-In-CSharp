using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _07_binary_search_trees
{
    public class _03_min_max_value_in_BST
    {
		/*
			link: https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
		*/
		[Fact]
		public void reverse_arrayTest()

		{

		}

		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			TC: O(N)
		*/
		//Function to find the minimum element in the given BST.
		private int minValue(NodeBinary root)
		{
			// base case
			if (root == null)
			{
				return -1;
			}

			NodeBinary current = root;

			//leftmost node is minimum so we move in BST till left node is not NULL.
			while (current.left != null)
			{
				current = current.left;
			}
			//returning the data at leftmost node.
			return (current.data);
		}



		// for max value (same as above)
		private int maxValue(NodeBinary root)
		{
			// base case
			if (root == null)
			{
				return -1;
			}

			NodeBinary current = root;

			// rightmost node is maximum so we move in BST till right node is not NULL.
			while (current.right != null)
			{
				current = current.right;
			}
			// returning the data at rightmost node.
			return (current.data);
		}

	}
}
