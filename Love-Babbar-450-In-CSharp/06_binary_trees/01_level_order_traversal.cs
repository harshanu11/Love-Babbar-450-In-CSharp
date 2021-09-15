using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace binary_trees
{
    public class _01_level_order_traversal
    {
        [Fact]
        public void reverse_arrayTest()
        {
            LoaclBinaryTree lbt = new LoaclBinaryTree();
            NodeBinary root = lbt.newNode(1);
            root.left = lbt.newNode(2);
            root.right = lbt.newNode(3);
            root.left.left = lbt.newNode(4);
            root.left.right = lbt.newNode(5);

            Console.Write("Level Order traversal of binary tree is \n");
            lbt.printLevelOrderRecursive(root);
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

    }
}
