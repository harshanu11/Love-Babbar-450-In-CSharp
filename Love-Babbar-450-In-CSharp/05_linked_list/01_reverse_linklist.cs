using Model;
using System;
using System.Collections.Generic;
using System.Diagnostics;
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
                Debug.Write(temp.data);
                Debug.Write(" ");
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
                Debug.Write(arr[j--]);
                Debug.Write(" ");
            }

            return head;
        }

    }
}
/*
    link: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
// Iterative C++ program to reverse
// a linked list
//#include <iostream>
//using namespace std;

///* Link list node */
//struct Node
//{
//    int data;
//    struct Node* next;
//    Node(int data)
//    {
//        this->data = data;
//        next = NULL;
//    }
//};

//struct LinkedList
//{
//    Node* head;
//    LinkedList() { head = NULL; }

//    /* Function to reverse the linked list */
//    void reverse()
//    {
//        // Initialize current, previous and
//        // next pointers
//        Node* current = head;
//        Node* prev = NULL, *next = NULL;

//        while (current != NULL)
//        {
//            // Store next
//            next = current->next;

//            // Reverse current node's pointer
//            current->next = prev;

//            // Move pointers one position ahead.
//            prev = current;
//            current = next;
//        }
//        head = prev;
//    }

//    /* Function to print linked list */
//    void print()
//    {
//        struct Node* temp = head;
//        while (temp != NULL) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//}

//void push(int data)
//{
//    Node* temp = new Node(data);
//    temp->next = head;
//    head = temp;
//}
//};

///* Driver code*/
//int main()
//{
//    /* Start with the empty list */
//    LinkedList ll;
//    ll.push(20);
//    ll.push(4);
//    ll.push(15);
//    ll.push(85);

//    cout << "Given linked list\n";
//    ll.print();

//    ll.reverse();

//    cout << "\nReversed Linked list \n";
//    ll.print();
//    return 0;
//}










//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    recursive

//    after running this function we just do
//    ll.head = ll.reverse(ll.head);

//    Time Complexity: O(n)
//    Space Complexity: O(1)
//*/

//Node* reverse(Node* head)
//{
//    if (head == NULL || head->next == NULL)
//        return head;

//    /* reverse the rest list and put
//    the first element at the end */
//    Node* rest = reverse(head->next);
//    head->next->next = head;

//    /* tricky step -- see the diagram */
//    head->next = NULL;

//    /* fix the head pointer */
//    return rest;
//}




//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    simplest to understand
//*/

//// A simple and tail-recursive function to reverse
//// a linked list.  prev is passed as NULL initially.
//void reverseUtil(Node* curr, Node* prev, Node** head)
//{
//    /* If last node mark it head*/
//    if (!curr->next)
//    {
//        *head = curr;

//        /* Update next to prev node */
//        curr->next = prev;
//        return;
//    }

//    /* Save curr->next node for recursive call */
//    Node* next = curr->next;

//    /* and update next ..*/
//    curr->next = prev;

//    reverseUtil(next, curr, head);
//}

//// This function mainly calls reverseUtil()
//// with prev as NULL
//void reverse(Node** head)
//{
//    if (!head)
//        return;
//    reverseUtil(*head, NULL, head);
//}





//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using stack
//    TC: O(N)
//    SC: O(N)
//*/
//void reverseLL(Node** head)
//{

//    // Create a stack "s"
//    // of Node type
//    stack<Node*> s;
//    Node* temp = *head;
//    while (temp->next != NULL)
//    {

//        // Push all the nodes
//        // in to stack
//        s.push(temp);
//        temp = temp->next;
//    }
//    *head = temp;

//    while (!s.empty())
//    {

//        // Store the top value of
//        // stack in list
//        temp->next = s.top();

//        // Pop the value from stack
//        s.pop();

//        // update the next pointer in the
//        // in the list
//        temp = temp->next;
//    }
//    temp->next = NULL;
//}





//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    if we dont want to use count function, use vector (push_back)
//    TC: O(N)
//    SC: O(N)
//*/
//int count(node* head) // code to count the no. of nodes
//{
//    node* p = head;
//    int k = 1;
//    while (p != NULL)
//    {
//        p = p->next;
//        k++;
//    }
//    return k;
//}

//node* ll_reverse(node* head)  // to reverse the linked list
//{
//    node* p = head;
//    long int i = count(head), j = 1;
//    long int arr[i];
//    while (i && p != NULL)
//    {
//        arr[j++] = p->val;
//        p = p->next;
//        i--;
//    }
//    j--;
//    while (j) // loop will break as soon as j=0
//    {
//        cout << arr[j--] << " ";
//    }

//    return head;
//}
