using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _06_binary_trees
{
    public class _01_level_order_traversal
    {
        NodeBinary o = new NodeBinary();
        [Fact]
        public void reverse_arrayTest()
        {
            NodeBinary root = o.newNode(1);
            root.left = o.newNode(2);
            root.right = o.newNode(3);
            root.left.left = o.newNode(4);
            root.left.right = o.newNode(5);

            Debug.Write("Level Order traversal of binary tree is \n");
            printLevelOrderRecursive(root);
            printLevelOrderQueue(root);

        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using queue
            TC: O(N)
            SC: O(N)
            ---> where n is the number of nodes in the binary trees
        */
        private void printLevelOrderQueue(NodeBinary root)
        {
            if (root == null) return;
            Queue<NodeBinary> queue = new Queue<NodeBinary>();
            queue.Enqueue(root);
            while (queue.Count != 0)
            {
                NodeBinary tempNode = queue.Dequeue();
                Debug.Write(tempNode.data + " ");
                if (tempNode.left != null)
                {
                    queue.Enqueue(tempNode.left);
                }
                if (tempNode.right != null)
                {
                    queue.Enqueue(tempNode.right);
                }
            }
        }

        /* Print nodes at a current level */
        /* Function protoypes */
        public void printCurrentLevel(NodeBinary root, int level)
        {
            if (root == null)
            {
                return;
            }
            if (level == 1)
            {
                Debug.Write(root.data);
                Debug.Write(" ");
            }
            else if (level > 1)
            {
                printCurrentLevel(root.left, level - 1);
                printCurrentLevel(root.right, level - 1);
            }
        }
        /* CSompute the "height" of a tree -- the number of
            nodes along the longest path from the root node
            down to the farthest leaf node.*/

        public int height(NodeBinary node)
        {
            if (node == null)
            {
                return 0;
            }
            else
            {
                /* compute the height of each subtree */
                int lheight = height(node.left);
                int rheight = height(node.right);

                /* use the larger one */
                if (lheight > rheight)
                {
                    return (lheight + 1);
                }
                else
                {
                    return (rheight + 1);
                }
            }
        }



        /* Function to print level
        order traversal a tree*/
        public void printLevelOrderRecursive(NodeBinary root)
        {
            int h = height(root);
            int i;
            for (i = 1; i <= h; i++)
            {
                printCurrentLevel(root, i);
            }
        }
    }
}
