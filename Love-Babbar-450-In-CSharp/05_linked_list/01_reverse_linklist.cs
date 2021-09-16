using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _05_linked_list
{
    //link: https://www.geeksforgeeks.org/reverse-a-linked-list/

    public class _01_reverse_linklist
    {
        public NodeLL head;
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
            AddLast(6);
            print();
            AddAt(5, 4);
            DeleteAt(4);
            reverse();
            print();
            head = reverseRecur(head);
            reverseTailUntil(head);
            reverseLLStack(head);
            ll_reverse4(head);
        }
        public void AddFirst(int data)
        {
            NodeLL startNode = new NodeLL(data);
            startNode.next = head;
            head = startNode;
        }
        public void AddLast(int data)
        {
            NodeLL temp = head;
            NodeLL end = new NodeLL(data);
            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = end;
        }
        public void AddAt(int data, int pos)
        {
            var newNode = new NodeLL(data);
            if (pos == 0) newNode.next = head;
            var prev = head;
            for (int p = 0; p < pos - 1; p++)
            {
                prev = prev.next;
            }
            newNode.next = prev.next;
            prev.next = newNode;
        }
        public void DeleteAt(int pos)
        {
            if (pos == 0) head = head.next;
            var prev = head;

            for (int p = 0; p < pos - 1; p++)
            {
                prev = prev.next;
            }
            prev.next = prev.next.next;
        }
        void reverse()
        {
            NodeLL current = head;
            NodeLL prev = null;
            NodeLL next = null;

            while (current != null)
            {
                // save next node 
                next = current.next;
                // remover next node and make curr next to prev
                current.next = prev;
                // time to move right n make prev to crrent
                prev = current;
                // refresh curr with temp
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

        private NodeLL reverseRecur(NodeLL hedRoot)
        {
            if (hedRoot == null || hedRoot.next == null) return hedRoot;
            NodeLL newHead = reverseRecur(hedRoot.next);
            NodeLL nextHead = hedRoot.next;
            nextHead.next = hedRoot;
            hedRoot.next = null;
            return newHead;
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
