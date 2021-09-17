using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _06_binary_trees
{
    public class _02_reverse_level_order_traversal
    {


        /*
            link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

            sol: https://www.geeksforgeeks.org/reverse-level-order-traversal/
        */


        [Fact]
        public void ReverseTraversetTest() 
        {
            NodeBinary root = newNode(40);
            root.left = newNode(60);
            root.right = newNode(20);
            root.left.left = newNode(30);
            root.left.right = newNode(10);
            var ans = reverseLevelOrder(root);

        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            same code as in 1_level_order.....
            here just change the level iteration from i=height to 1.
        */
        private int height(NodeBinary node)
        {
            if (node == null)
            {
                return 0;
            }
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

        private void getCurrentLevel(NodeBinary root, int level, List<int> ans)
        {
            if (root == null)
            {
                return;
            }

            if (level == 1)
            {
                ans.Add(root.data);
            }
            else if (level > 1)
            {
                getCurrentLevel(root.left, level - 1, ans);
                getCurrentLevel(root.right, level - 1, ans);
            }
        }

        private void levelOrderTraversal(NodeBinary root, List<int> ans)
        {
            int h = height(root);
            for (int i = h; i >= 1; i--)
            {
                getCurrentLevel(root, i, ans);
            }
        }

        private List<int> reverseLevelOrder(NodeBinary root)
        {
            // code here
            List<int> ans = new List<int>();
            levelOrderTraversal(root, ans);
            return new List<int>(ans);
        }
        public NodeBinary newNode(int data)
        {
            NodeBinary Node = new NodeBinary(data);
            Node.data = data;
            Node.left = null;
            Node.right = null;

            return (Node);
        }


    }
}
