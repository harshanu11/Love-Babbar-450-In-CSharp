namespace Love_Babbar_450_In_CSharp._06_binary_trees
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
        public NodeBinary DeepCopy(NodeBinary data)
        {
            data = (NodeBinary)this.MemberwiseClone();
            //cl.cl2 = new CopyClassTest();
            //cl.num = 0;
            return data;
        }
    }
}
