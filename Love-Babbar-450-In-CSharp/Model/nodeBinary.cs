namespace Model
{
    /*
      link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

      sol: https://www.geeksforgeeks.org/level-order-tree-traversal/
  */




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


    //C++ TO C# CONVERTER WARNING: The following #include directive was ignored:
    //#include <bits/stdc++.h>

    /* A binary tree node has data,
    pointer to left child
    and a pointer to right child */
    public class NodeBinary
    {
        public int data;
        public NodeBinary left;
        public NodeBinary right;
        public NodeBinary(int Data)
        {
            data = Data;
        }
        public NodeBinary()
        {
        }
        public NodeBinary DeepCopy(NodeBinary data)
        {
            data = (NodeBinary)this.MemberwiseClone();
            //cl.cl2 = new CopyClassTest();
            //cl.num = 0;
            return data;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            insert a node in BST
            TC: O(log N)    // if its not skewed tree
                O(N)        // it skewed tree
        */
        // Insert function definition.
        public NodeBinary InsertBST(NodeBinary root, int key)
        {
            if (root == null) return new NodeBinary(key);
            // Insert data.
            if (key > root.data) root.right = InsertBST(root.right, key);
            else root.left = InsertBST(root.left, key);
            return root;
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
    }
}
