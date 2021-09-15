using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace linked_list
{
    //link: https://www.geeksforgeeks.org/reverse-a-linked-list/

    public partial class _01_reverse_linklist
    {
        public NodeLL head;
        public _01_reverse_linklist()
        {
            head = null;
        }
        /*
            Time Complexity: O(n)
            Space Complexity: O(1)
        */
        [Fact]
        public void reverse_LinkList()
        {
            /* Start with the empty list */
            AddFirst(4);
            AddFirst(3);
            AddFirst(2);
            AddFirst(1);
            AddLast(0);
            print();
            reverse();
            print();
            reverseRecur(head);
            reverseTailUntil(head);
            reverseLLStack(head);
            ll_reverse4(head);
        }
        void AddFirst(int data)
        {
            NodeLL startNode = new NodeLL(data);
            startNode.next = head;
            head = startNode;
        }
        void AddLast(int data)
        {
            NodeLL temp = head;
            NodeLL end = new NodeLL(data);
            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = end;
        }
        void reverse()
        {
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
        void print()
        {
            NodeLL temp = head;
            while (temp != null)
            {
                Console.Write(temp.data);
                Console.Write(" ");
                temp = temp.next;
            }
        }

        /*
            after running this function we just do
            head = reverse(head);

            Time Complexity: O(n)
            Space Complexity: O(1)
        */

        private NodeLL reverseRecur(NodeLL head)
        {
            if (head == null || head.next == null) return head;
            /* reverse the rest list and put
            the first element at the end */
            NodeLL rest = reverseRecur(head.next);
            head.next.next = head;

            /* tricky step -- see the diagram */
            head.next = null;

            /* fix the head pointer */
            return rest;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        // A simple and tail-recursive function to reverse
        // a linked list.  prev is passed as NULL initially.
        private void reverseUtil(NodeLL curr, NodeLL prev, NodeLL head)
        {
            /* If last NodeLL mark it head*/
            if (curr.next == null)
            {
                //C++ TO C# CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'CopyFrom' method should be created:
                //ORIGINAL LINE: *head = curr;
                head.DeepCopy(curr.data);

                /* Update next to prev NodeLL */
                curr.next = prev;
                return;
            }

            /* Save curr->next NodeLL for recursive call */
            NodeLL next = curr.next;

            /* and update next ..*/
            curr.next = prev;

            reverseUtil(next, curr, head);
        }
        private void reverseTailUntil(NodeLL head)
        {
            if (head == null)
            {
                return;
            }
            reverseUtil(head, null, head);
        }



        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using stack
            TC: O(N)
            SC: O(N)
        */
        private void reverseLLStack(NodeLL head)
        {

            // Create a stack "s"
            // of NodeLL type
            Stack<NodeLL> s = new Stack<NodeLL>();
            NodeLL temp = head;
            while (temp.next != null)
            {

                // Push all the nodes
                // in to stack
                s.Push(temp);
                temp = temp.next;
            }
            //C++ TO C# CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'CopyFrom' method should be created:
            //ORIGINAL LINE: *head = temp;
            head.DeepCopy(temp.data);

            while (s.Count > 0)
            {

                // Store the top value of
                // stack in list
                temp.next = s.Peek();

                // Pop the value from stack
                s.Pop();

                // update the next pointer in the
                // in the list
                temp = temp.next;
            }
            temp.next = null;
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            if we dont want to use count function, use vector (push_back)
            TC: O(N)
            SC: O(N)
        */
        private int count(NodeLL head) // code to count the no. of nodes
        {
            NodeLL p = head;
            int k = 1;
            while (p != null)
            {
                p = p.next;
                k++;
            }
            return k;
        }

        private NodeLL ll_reverse4(NodeLL head) // to reverse the linked list
        {
            NodeLL p = head;
            int i = count(head);
            int j = 1;
            int[] arr = new int[i];
            while (i != 0 && p != null)
            {
                arr[j++] = p.data;
                p = p.next;
                i--;
            }
            j--;
            while (j != 0) // loop will break as soon as j=0
            {
                Console.Write(arr[j--]);
                Console.Write(" ");
            }

            return head;
        }



    }
}
