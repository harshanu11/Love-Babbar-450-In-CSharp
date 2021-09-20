using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _05_linked_list
{
    public class _05_first_node_in_loop
    {

        /*
            link: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
        */
        [Fact]
        public void reverse_arrayTest() { }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            floyd's cycle finding algorithm (or loop detecting)
        */
        private NodeLL detectAndRemoveLoop(NodeLL head)
        {
            // If list is empty or has only one node
            // without loop
            if (head == null || head.next == null)
            {
                return null;
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

            // If loop does not exist
            if (slow != fast)
            {
                return null;
            }

            // If loop exists. Start slow from
            // head and fast from meeting point.
            slow = head;
            while (slow != fast)
            {
                slow = slow.next;
                fast = fast.next;
            }

            return slow;
        }






        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            by assigning every node's next NULL, if any node's next detected NULL means it is visited.
        */
        private NodeLL detectLoop(NodeLL head)
        {

            // Create a temporary node
            NodeLL temp = new NodeLL();
            while (head != null)
            {

                // This condition is for the case
                // when there is no loop
                if (head.next == null)
                {
                    return null;
                }

                // Check if next is already
                // pointing to temp
                if (head.next == temp)
                {
                    break;
                }

                // Store the pointer to the next node
                // in order to get to it in the next step
                NodeLL nex = head.next;

                // Make next point to temp
                head.next = temp;

                // Get to the next node in the list
                head = nex;
            }

            return head;
        }





        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using hashing
        */
        private NodeLL detectCycle(NodeLL A)
        {

            // declaring map to store node address
            HashSet<NodeLL> uset = new HashSet<NodeLL>();

            NodeLL ptr = A;

            // Default consider that no cycle is present
            while (ptr != null)
            {

                // checking if address is already present in map
                //if (uset.find(ptr) != uset.end())
                //{
                //	return ptr;
                //}

                //// if address not present then insert into the set
                //else
                //{
                //	uset.Add(ptr);
                //}

                ptr = ptr.next;
            }
            return null;
        }

    }
}
/*
    link: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    floyd's cycle finding algorithm (or loop detecting)
//*/
//Node* detectAndRemoveLoop(Node* head)
//{
//    // If list is empty or has only one node
//    // without loop
//    if (head == NULL || head->next == NULL)
//        return NULL;

//    Node* slow = head, *fast = head;

//    // Move slow and fast 1 and 2 steps
//    // ahead respectively.
//    slow = slow->next;
//    fast = fast->next->next;

//    // Search for loop using slow and
//    // fast pointers
//    while (fast && fast->next)
//    {
//        if (slow == fast)
//            break;
//        slow = slow->next;
//        fast = fast->next->next;
//    }

//    // If loop does not exist
//    if (slow != fast)
//        return NULL;

//    // If loop exists. Start slow from
//    // head and fast from meeting point.
//    slow = head;
//    while (slow != fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }

//    return slow;
//}






//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    by assigning every node's next NULL, if any node's next detected NULL means it is visited.
//*/
//Node* detectLoop(Node* head)
//{

//    // Create a temporary node
//    Node* temp = new Node;
//    while (head != NULL)
//    {

//        // This condition is for the case
//        // when there is no loop
//        if (head->next == NULL)
//        {
//            return NULL;
//        }

//        // Check if next is already
//        // pointing to temp
//        if (head->next == temp)
//        {
//            break;
//        }

//        // Store the pointer to the next node
//        // in order to get to it in the next step
//        Node* nex = head->next;

//        // Make next point to temp
//        head->next = temp;

//        // Get to the next node in the list
//        head = nex;
//    }

//    return head;
//}





//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using hashing
//*/
//ListNode* detectCycle(ListNode* A)
//{

//    // declaring map to store node address
//    unordered_set<ListNode*> uset;

//    ListNode* ptr = A;

//    // Default consider that no cycle is present
//    while (ptr != NULL)
//    {

//        // checking if address is already present in map
//        if (uset.find(ptr) != uset.end())
//            return ptr;

//        // if address not present then insert into the set
//        else
//            uset.insert(ptr);

//        ptr = ptr->next;
//    }
//    return NULL;
//}
