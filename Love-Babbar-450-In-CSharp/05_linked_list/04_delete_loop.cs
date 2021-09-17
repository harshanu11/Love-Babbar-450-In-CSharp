using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _05_linked_list
{
    public class _04_delete_loop
    {

        /*
            link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

            sol: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
        */

        [Fact]
        public void reverse_arrayTest()
        {


        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using hashing
            TC: O(N)
            SC: O(N)
        */
        private void removeLoop(NodeLL head)
        {
            HashSet<NodeLL> s = new HashSet<NodeLL>();
            NodeLL curr = head;
            s.Add(curr);

            //while (curr.next != null)
            //{
            //	if (s.find(curr.next) != s.end())
            //	{
            //		curr.next = null;
            //		return;
            //	}
            //	s.Add(curr.next);
            //	curr = curr.next;
            //}
        }

        /* Function to remove loop.
        loop_node --> Pointer to
        one of the loop nodes
        head --> Pointer to the
        start node of the linked list */



        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            check one by one
        */

        private void removeLoop(NodeLL loop_node, NodeLL head)
        {
            NodeLL ptr1;
            NodeLL ptr2;

            /* Set a pointer to the beginning
            of the Linked List and
            move it one by one to find the
            first node which is
            part of the Linked List */
            ptr1 = head;
            while (true)
            {
                /* Now start a pointer from
                loop_node and check if
            it ever reaches ptr2 */
                ptr2 = loop_node;
                while (ptr2.next != loop_node && ptr2.next != ptr1)
                {
                    ptr2 = ptr2.next;
                }

                /* If ptr2 reahced ptr1
                then there is a loop. So
                break the loop */
                if (ptr2.next == ptr1)
                {
                    break;
                }

                /* If ptr2 did't reach ptr1
                then try the next node
                * after ptr1 */
                ptr1 = ptr1.next;
            }

            /* After the end of loop ptr2
            is the last node of the
            loop. So make next of ptr2 as NULL */
            ptr2.next = null;
        }

        private int detectAndRemoveLoop(NodeLL list)
        {
            NodeLL slow_p = list;
            NodeLL fast_p = list;

            //while (slow_p != null && fast_p != null && fast_p.next)
            //{
            //	slow_p = slow_p.next;
            //	fast_p = fast_p.next.next;

            //	/* If slow_p and fast_p meet at
            //		some point then
            //	there is a loop */
            //	if (slow_p == fast_p)
            //	{
            //		removeLoop(slow_p, list);

            //		/* Return 1 to indicate that loop is found */
            //		return 1;
            //	}
            //}

            /* Return 0 to indeciate that ther is no loop*/
            return 0;
        }

        /* Function to remove loop.
        loop_node --> Pointer to one of the loop nodes
        head --> Pointer to the start node of the linked list */








        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            moving chain of loop length
        */

        /* Function to remove loop. */
        private void removeLoop2(NodeLL loop_node, NodeLL head)
        {
            NodeLL ptr1 = loop_node;
            NodeLL ptr2 = loop_node;

            // Count the number of nodes in loop
            uint k = 1;
            uint i;
            while (ptr1.next != ptr2)
            {
                ptr1 = ptr1.next;
                k++;
            }

            // Fix one pointer to head
            ptr1 = head;

            // And the other pointer to k nodes after head
            ptr2 = head;
            for (i = 0; i < k; i++)
            {
                ptr2 = ptr2.next;
            }

            /* Move both pointers at the same pace,
            they will meet at loop starting node */
            while (ptr2 != ptr1)
            {
                ptr1 = ptr1.next;
                ptr2 = ptr2.next;
            }

            // Get pointer to the last node
            while (ptr2.next != ptr1)
            {
                ptr2 = ptr2.next;
            }

            /* Set the next node of the loop ending node
            to fix the loop */
            ptr2.next = null;
        }

        /* This function detects and removes loop in the list
        If loop was there in the list then it returns 1,
        otherwise returns 0 */
        private int detectAndRemoveLoop2(NodeLL list)
        {
            NodeLL slow_p = list;
            NodeLL fast_p = list;

            // Iterate and find if loop exists or not
            //while (slow_p != null && fast_p != null && fast_p.next)
            //{
            //	slow_p = slow_p.next;
            //	fast_p = fast_p.next.next;

            //	/* If slow_p and fast_p meet at some point then there
            //	is a loop */
            //	if (slow_p == fast_p)
            //	{
            //		removeLoop(slow_p, list);

            //		/* Return 1 to indicate that loop is found */
            //		return 1;
            //	}
            //}

            /* Return 0 to indicate that there is no loop*/
            return 0;
        }







        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            Optimized Method 2: Without Counting Nodes in Loop
        */


        // Function to detect and remove loop
        // in a linked list that may contain loop
        private void detectAndRemoveLoop3(NodeLL head)
        {
            // If list is empty or has only one node
            // without loop
            if (head == null || head.next == null)
            {
                return;
            }

            NodeLL slow = head;
            NodeLL fast = head;

            // Move slow and fast 1 and 2 steps
            // ahead respectively.
            slow = slow.next;
            fast = fast.next.next;

            // Search for loop using slow and
            // fast pointers
            //while (fast != null && fast.next)
            //{
            //	if (slow == fast)
            //	{
            //		break;
            //	}
            //	slow = slow.next;
            //	fast = fast.next.next;
            //}

            /* If loop exists */
            if (slow == fast)
            {
                slow = head;

                // this check is needed when slow
                // and fast both meet at the head of the LL
                // eg: 1->2->3->4->5 and then
                // 5->next = 1 i.e the head of the LL
                if (slow == fast)
                {
                    while (fast.next != slow)
                    {
                        fast = fast.next;
                    }
                }
                else
                {
                    while (slow.next != fast.next)
                    {
                        slow = slow.next;
                        fast = fast.next;
                    }
                }

                /* since fast->next is the looping point */
                fast.next = null; // remove loop
            }
        }

    }
}
