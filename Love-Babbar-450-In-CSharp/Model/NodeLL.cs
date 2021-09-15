namespace Love_Babbar_450_In_CSharp._05_linked_list
{
    /*
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    // Iterative C++ program to reverse
    // a linked list

    /* Link list node */
    public class NodeLL
    {
        public int data;
        public NodeLL next;
        public NodeLL(int data)
        {
            this.data = data;
            next = null;
        }
        public NodeLL DeepCopy(int data)
        {
            NodeLL cl = new NodeLL(data);
            cl = (NodeLL)this.MemberwiseClone();
            //cl.cl2 = new CopyClassTest();
            //cl.num = 0;
            return cl;
        }
    }
}
