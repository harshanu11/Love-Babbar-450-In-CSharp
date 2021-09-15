using System;

namespace Love_Babbar_450_In_CSharp._05_linked_list
{
    public class LocalLinkedList
    {
        public NodeLL head;
        public LocalLinkedList()
        {
            head = null;
        }

        /* Function to reverse the linked list */
        public void reverse()
        {
            // Initialize current, previous and
            // next pointers
            NodeLL current = head;
            NodeLL prev = null;
            NodeLL next = null;

            while (current != null)
            {
                // Store next
                next = current.next;

                // Reverse current node's pointer
                current.next = prev;

                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            head = prev;
        }

        /* Function to print linked list */
        public void print()
        {
            NodeLL temp = head;
            while (temp != null)
            {
                Console.Write(temp.data);
                Console.Write(" ");
                temp = temp.next;
            }
        }

        public void pushFirst(int data)
        {
            NodeLL temp = new NodeLL(data);
            temp.next = head;
            head = temp;
        }
    }
}
