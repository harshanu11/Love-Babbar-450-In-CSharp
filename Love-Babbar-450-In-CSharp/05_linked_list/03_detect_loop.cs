using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _05_linked_list
{
    public class _03_detect_loop
    {
        /*
            link: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

            sol: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

            out of all the algo, revise Floyd's Cycle-Finding Algorithm

            but beware it is use to detect the loop it wont give us last node.
        */

        [Fact]
        public void reverse_arrayTest()

        {
            NodeLL head = new NodeLL(1);
            head.next = new NodeLL(2);
            head.next.next = new NodeLL(3);
            head.next.next.next = new NodeLL(4);
            head.next.next.next.next = new NodeLL(5);

            /* Create a loop for testing(5 is pointing to 3) */
            head.next.next.next.next.next = head.next.next;
            bool found = detectLoop1(head);
            if (found)
                Debug.Write("Loop Found");
            else
                Debug.Write("No Loop Found");
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using hashing
            TC: O(N)
            SC: O(N)
        */
        private bool detectLoop1(NodeLL head)
        {
            HashSet<NodeLL> s = new HashSet<NodeLL>();
            while (head != null)
            {
                // If we have already has this node
                // in hashmap it means their is a cycle
                // (Because you we encountering the
                // node second time).
                if (s.Contains(head))
                    return true;

                // If we are seeing the node for
                // the first time, insert it in hash
                s.Add(head);

                head = head.next;
            }

            return false;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            altering the value
            as all data are positive, alter their sign
            hence if we get any data negative, loop is detected

            TC: O(N)
            SC: O(1)
        */
        private bool detectLoop2(NodeLL head)
        {
            while (head != null)
            {
                if (head.data < 0)
                {
                    return true;
                }
                head.data = -(head.data);
                head = head.next;
            }
            return false;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using flag

            struct Node {
                int data;
                struct Node* next;
                int flag;                   // add flag
            };
        */
        private bool detectLoop3(NodeLL h)
        {
            while (h != null)
            {
                // If this node is already traverse
                // it means there is a cycle
                // (Because you we encountering the
                // node for the second time).
                if (h.flag == 1)
                {
                    return true;
                }

                // If we are seeing the node for
                // the first time, mark its flag as 1
                h.flag = 1;

                h = h.next;
            }

            return false;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            Floyd's Cycle-Finding Algorithm

            This is the fastest method
            1. Traverse linked list using two pointers.
            2. Move one pointer(slow_p) by one and another pointer(fast_p) by two.
            3. If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn't have a loop.

            TC: O(N)
            SC: O(1)
        */
        private bool detectLoop4(NodeLL list)
        {
            NodeLL slow_p = list;
            NodeLL fast_p = list;

            while (slow_p != null && fast_p != null
               && fast_p.next != null)
            {
                slow_p = slow_p.next;
                fast_p = fast_p.next.next;
                if (slow_p == fast_p)
                {
                    return true;
                }
            }
            return false;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            by assigning null to next pointer, if we visit such node whose next pointer is pointing to null
            then its visited node.

            TC: O(N)
            SC: O(1)
        */
        private bool detectLoop5(NodeLL head)
        {

            // Create a temporary node
            NodeLL temp = new NodeLL();
            while (head != null)
            {

                // This condition is for the case
                // when there is no loop
                if (head.next == null)
                {
                    return false;
                }

                // Check if next is already
                // pointing to temp
                if (head.next == temp)
                {
                    return true;
                }

                // Store the pointer to the next node
                // in order to get to it in the next step
                NodeLL nex = head.next;

                // Make next point to temp
                head.next = temp;

                // Get to the next node in the list
                head = nex;
            }

            return false;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            by analyzing length of the link list each time.
            Time complexity: O(n^2)
            Auxiliary Space: O(1)
        */
        private bool detectLoop6(NodeLL head)
        {

            // Create a temporary node
            NodeLL temp = new NodeLL();

            NodeLL first;
            NodeLL last;

            /*first always points to head*/
            first = head;
            /*last pointer initially points to head*/
            last = head;

            /*current_length stores no of nodes between current
             * position of first and last*/
            int current_length = 0;

            /*current_length stores no of nodes between previous
             * position of first and last*/
            int prev_length = -1;

            while (current_length > prev_length && last != null)
            {
                // set prev_length to current length then update the
                // current length
                prev_length = current_length;
                // distance is calculated
                current_length = distance(first, last);
                // last node points the next node
                last = last.next;
            }

            if (last == null)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        static int distance(NodeLL first, NodeLL last)
        {

            /*counts no of nodes between first and last*/
            int counter = 0;
            NodeLL curr;
            curr = first;
            while (curr != last)
            {
                counter += 1;
                curr = curr.next;
            }
            return counter + 1;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            unusual approach
            Time Complexity: O(N)
            Auxiliary Space: O(1)
        */
        private bool detectLoop7(NodeLL head)
        {

            // If the head is null we will return false
            if (head == null)
            {
                return false;
            }
            else
            {

                // Traversing the linked list
                // for detecting loop
                while (head != null)
                {
                    // If loop found
                    if (head.data == -1)
                    {
                        return true;
                    }

                    // Changing the data of visited node to any
                    // value which is outside th given range here it
                    // is supposed the given range is (1 <= Data on
                    // Node <= 10^3)
                    else
                    {
                        head.data = -1;
                        head = head.next;
                    }
                }
                // If loop not found return false
                return false;
            }
        }


    }
}
