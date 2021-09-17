namespace Model
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
        public int flag { get; set; }
        public NodeLL()
        {

        }
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
