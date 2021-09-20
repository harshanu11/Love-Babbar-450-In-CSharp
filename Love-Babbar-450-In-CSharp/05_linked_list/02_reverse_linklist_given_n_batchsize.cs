using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _05_linked_list
{
    public class _02_reverse_linklist_given_n
    {
        /*
			link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
			sol: https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
			sol2: https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/
        Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
		*/

        [Fact]
        public void reverse_InGroup_LinkList()
        {
            _01_reverse_linklist o = new _01_reverse_linklist();
            o.AddFirst(1);
            o.AddLast(2);
            o.AddLast(2);
            o.AddLast(4);
            o.AddLast(5);
            o.AddLast(6);
            o.AddLast(7);
            o.AddLast(8);
            //            K = 4
            //Output: 4 2 2 1 8 7 6 5
            var ans = reverse12(o.head, 4);
            ans = ReverseUsingStack(o.head, 4);

        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
			Time Complexity: O(n).
				Traversal of list is done only once and it has 'n' elements.
			Auxiliary Space: O(n/k).
				For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.
		*/
        private NodeLL reverse1(NodeLL head, int k)
        {
            if (head == null) return null;
            int count = 0;
            NodeLL curr = head;
            NodeLL prev = null;
            NodeLL next = null;

            while (count < k && curr != null)
            {
                next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            if (next != null)
            {
                head.next = reverse1(next, k);
            }

            return prev;
        }
        NodeLL reverse12(NodeLL head, int k)
        {
            if (head == null) return null;
            int count = 0;
            NodeLL current = head;
            NodeLL prev = null;
            NodeLL next = null;
            while (count < k && current != null)
            {
                // save next node 
                next = current.next;
                // remover next node and make curr next to prev
                current.next = prev;
                // time to move right n make prev to crrent
                prev = current;
                // refresh curr with temp
                current = next;
                count++;
            }
            if (next != null)
            {
                head.next = reverse12(next, k);
            }
            return head = prev;
        }
        // ----------------------------------------------------------------------------------------------------------------------- //
        /*  
            using stack
            TC: O(n)
            SC: O(k) -> size of the stack each time.
        */
        private NodeLL ReverseUsingStack(NodeLL head, int k)
        {
            // Create a stack of NodeLL*
            Stack<NodeLL> mystack = new Stack<NodeLL>();
            NodeLL current = head;
            NodeLL prev = null;

            while (current != null)
            {

                // Terminate the loop whichever comes first
                // either current == NULL or count >= k
                int count = 0;
                while (current != null && count < k)
                {
                    mystack.Push(current);
                    current = current.next;
                    count++;
                }

                // Now pop the elements of stack one by one
                while (mystack.Count > 0)
                {

                    // If final list has not been started yet.
                    if (prev == null)
                    {
                        prev = mystack.Peek();
                        head = prev;
                        mystack.Pop();
                    }
                    else
                    {
                        prev.next = mystack.Peek();
                        prev = prev.next;
                        mystack.Pop();
                    }
                }
            }

            // Next of last element will point to NULL.
            prev.next = null;

            return head;
        }
    }
}
