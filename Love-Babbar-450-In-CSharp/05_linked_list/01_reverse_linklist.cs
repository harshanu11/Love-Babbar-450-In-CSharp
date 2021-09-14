using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace Love_Babbar_450_In_CSharp._05_linked_list
{
    /*
    link: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/

    public partial class _01_reverse_linklist
    {

        [Fact]
        public void reverse_arrayTest()
        {
            /* Start with the empty list */
            LocalLinkedList ll = new LocalLinkedList();
            ll.push(20);
            ll.push(4);
            ll.push(15);
            ll.push(85);

            Console.Write("Given linked list\n");
            ll.print();

            ll.reverse();

            Console.Write("\nReversed Linked list \n");
            ll.print();

            reverseRecur(ll.head);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            recursive

            after running this function we just do
            ll.head = ll.reverse(ll.head);

            Time Complexity: O(n)
            Space Complexity: O(1)
        */

        private NodeLL reverseRecur(NodeLL head)
        {
            if (head == null || head.next == null)
            {
                return head;
            }

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
        /*
            simplest to understand
        */

        // A simple and tail-recursive function to reverse
        // a linked list.  prev is passed as NULL initially.
        //https://www.geeksforgeeks.org/reverse-a-linked-list/
        NodeLL head;
        private void reverseUtil(NodeLL curr, NodeLL prev)
        {
            /* If last node mark it head*/
            if (curr.next != null)
            {
                head =curr;

                /* Update next to prev node */
                curr.next = prev;
                return;
            }

            /* Save curr->next node for recursive call */
            NodeLL next = curr.next;

            /* and update next ..*/
            curr.next = prev;

            reverseUtil(next, curr);
        }

        // This function mainly calls reverseUtil()
        // with prev as NULL
        private void reverseTailRecursive(NodeLL head)
        {
            if (head!= null)
            {
                return;
            }
            reverseUtil(head, null);
        }



    }
}
