using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace Love_Babbar_450_In_CSharp._06_binary_trees
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
            // Base Case
            if (root == null)
            {
                return;
            }

            // Create an empty queue for level order traversal
            Queue<NodeBinary> q = new Queue<NodeBinary>();

            // Enqueue Root and initialize height
            q.Enqueue(root);

            while (q.Count > 0)
            {
                // Print front of queue and remove it from queue
                NodeBinary node = q.Peek();
                Console.Write(node.data);
                Console.Write(" ");
                q.Dequeue();

                /* Enqueue left child */
                if (node.left != null)
                {
                    q.Enqueue(node.left);
                }

                /*Enqueue right child */
                if (node.right != null)
                {
                    q.Enqueue(node.right);
                }
            }
        }

    }
}
