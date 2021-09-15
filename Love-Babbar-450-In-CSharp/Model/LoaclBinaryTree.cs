using System;

namespace Love_Babbar_450_In_CSharp._06_binary_trees
{
    public class LoaclBinaryTree
    {
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
                Console.Write(root.data);
                Console.Write(" ");
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

        /* Helper function that allocates
        a new node with the given data and
        NULL left and right pointers. */

        public NodeBinary newNode(int data)
        {
            NodeBinary Node = new NodeBinary(data);
            Node.data = data;
            Node.left = null;
            Node.right = null;

            return (Node);
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
