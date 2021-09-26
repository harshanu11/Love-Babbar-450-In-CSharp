using Model;
using Xunit;

namespace _07_binary_search_trees
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
        private NodeBinary search(NodeBinary root, int key)
        {
            if (root == null || root.data == key) return root;
            if (root.data < key) return search(root.right, key);
            return search(root.left, key);
        }
    }
}
