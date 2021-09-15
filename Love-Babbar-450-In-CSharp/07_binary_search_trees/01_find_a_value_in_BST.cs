using Love_Babbar_450_In_CSharp._06_binary_trees;
using Model;
using Xunit;

namespace Love_Babbar_450_In_CSharp._07_binary_search_trees
{
    public class _01_find_a_value_in_BST
    {

        [Fact]
        public void Bst_Test()
        {
            

        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
			using recursion
			TC: O(log N)
		*/
        // C++ function to search a given key in a given BST
        private NodeBinary search(NodeBinary root, int key)
        {
            // Base Cases: root is null or key is present at root
            if (root == null || root.data == key)
            {
                return root;
            }

            // Key is greater than root's key
            if (root.data < key)
            {
                return search(root.right, key);
            }

            // Key is smaller than root's key
            return search(root.left, key);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            insert a node in BST
            TC: O(log N)    // if its not skewed tree
                O(N)        // it skewed tree
        */
        // Insert function definition.
        private NodeBinary Insert(NodeBinary root, int key)
        {
            if (root == null)
            {
                // Insert the first node, if root is NULL.
                return new NodeBinary(key);
            }

            // Insert data.
            if (key > root.data)
            {
                // Insert right node data, if the 'key'
                // to be inserted is greater than 'root' node data.

                // Process right nodes.
                root.right = Insert(root.right, key);
            }
            else
            {
                // Insert left node data, if the 'key'
                // to be inserted is greater than 'root' node data.

                // Process left nodes.
                root.left = Insert(root.left, key);
            }
            // Return 'root' node, after insertion.
            return root;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using iteration
            TC: O(log N) not skewed
                O(N) for skewed
        */
        private void insert(NodeBinary root, int key)
        {
            NodeBinary node = new NodeBinary(key);
            if (root == null)
            {
                root = node;
                return;
            }


            NodeBinary prev = null;
            NodeBinary temp = root;
            while (temp != null)
            {
                if (temp.data > key)
                {
                    //C++ TO C# CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'CopyFrom' method should be created:
                    //ORIGINAL LINE: prev = temp;
                    prev.DeepCopy(temp);
                    temp = temp.left;
                }
                else if (temp.data < key)
                {
                    //C++ TO C# CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'CopyFrom' method should be created:
                    //ORIGINAL LINE: prev = temp;
                    prev.DeepCopy(temp);
                    temp = temp.right;
                }
            }

            if (prev.data > key)
            {
                prev.left = node;
            }
            else
            {
                prev.right = node;
            }
        }


    }
}
