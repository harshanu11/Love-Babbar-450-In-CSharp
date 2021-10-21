/*
	link: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/



#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>

class nodeLL {
public:
	int flag;
	int data;
	nodeLL* next;
	nodeLL* prev;
	nodeLL(int data)
	{
		this->data = data;
		next = NULL;
	}
};
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
	TEST_CLASS(LinkListtest)
	{
	public:

		TEST_METHOD(ReverseLLTestTest)
		{
			/* Start with the empty list */
			LinkedList ll;
			ll.pushLL(20);
			ll.pushLL(4);
			ll.pushLL(15);
			ll.pushLL(85);
			ll.reverseLL();
			nodeLL head = NULL;
			//nodeLL* para = ;
			reverseLL2(ll.head);
			reverseLL3(&ll.head);
			reverseLLusingStack(&ll.head);
			ll_reverseWithoutCount(ll.head);
		}

		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			recursive
		
			after running this function we just do
			ll.head = ll.reverse(ll.head);
		
			Time Complexity: O(n)
			Space Complexity: O(1)
		*/

		nodeLL* reverseLL2(nodeLL* head)
		{
			if (head == NULL || head->next == NULL)
				return head;

			/* reverse the rest list and put
			the first element at the end */
			nodeLL* rest = reverseLL2(head->next);
			head->next->next = head;

			/* tricky step -- see the diagram */
			head->next = NULL;

			/* fix the head pointer */
			return rest;
		}
		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			Time Complexity: O(n)
			Space Complexity: O(1)
		*/
		// Iterative C++ program to reverse
		// a linked list
		struct LinkedList {
		public:nodeLL* head;
			  LinkedList() { head = NULL; }

			  /* Function to reverse the linked list */
			  void reverseLL()
			  {
				  // Initialize current, previous and
				  // next pointers
				  nodeLL* current = head;
				  nodeLL* prev = NULL, * next = NULL;

				  while (current != NULL) {
					  // Store next
					  next = current->next;

					  // Reverse current nodeLL's pointer
					  current->next = prev;

					  // Move pointers one position ahead.
					  prev = current;
					  current = next;
				  }
				  head = prev;
			  }

			  /* Function to print linked list */
			  void printLL()
			  {
				  struct nodeLL* temp = head;
				  while (temp != NULL) {
					  cout << temp->data << " ";
					  temp = temp->next;
				  }
			  }

			  void pushLL(int data)
			  {
				  nodeLL* temp = new nodeLL(data);
				  temp->next = head;
				  head = temp;
			  }
		};
		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			simplest to understand
		*/

		// A simple and tail-recursive function to reverse
		// a linked list.  prev is passed as NULL initially.
		void reverseUtil(nodeLL* curr, nodeLL* prev, nodeLL** head)
		{
			/* If last nodeLL mark it head*/
			if (!curr->next) {
				*head = curr;

				/* Update next to prev nodeLL */
				curr->next = prev;
				return;
			}

			/* Save curr->next nodeLL for recursive call */
			nodeLL* next = curr->next;

			/* and update next ..*/
			curr->next = prev;

			reverseUtil(next, curr, head);
		}

		// This function mainly calls reverseUtil()
		// with prev as NULL
		void reverseLL3(nodeLL** head)
		{
			if (!head)
				return;
			reverseUtil(*head, NULL, head);
		}


		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			using stack
			TC: O(N)
			SC: O(N)
		*/
		void reverseLLusingStack(nodeLL** head)
		{

			// Create a stack "s"
			// of nodeLL type
			stack<nodeLL*> s;
			nodeLL* temp = *head;
			while (temp->next != NULL)
			{

				// Push all the nodes
				// in to stack
				s.push(temp);
				temp = temp->next;
			}
			*head = temp;

			while (!s.empty())
			{

				// Store the top value of
				// stack in list
				temp->next = s.top();

				// Pop the value from stack
				s.pop();

				// update the next pointer in the
				// in the list
				temp = temp->next;
			}
			temp->next = NULL;
		}

		// ----------------------------------------------------------------------------------------------------------------------- //
/*
	if we dont want to use count function, use vector (push_back)
	TC: O(N)
	SC: O(N)
*/
		int count(nodeLL* head) // code to count the no. of nodes
		{
			nodeLL* p = head;
			int k = 1;
			while (p != NULL)
			{
				p = p->next;
				k++;
			}
			return k;
		}

		nodeLL* ll_reverseWithoutCount(nodeLL* head)  // to reverse the linked list
		{
			nodeLL* p = head;
			long int i = count(head), j = 1;
			long int arr[5];
			while (i && p != NULL)
			{
				arr[j++] = p->data;
				p = p->next;
				i--;
			}
			j--;
			while (j) // loop will break as soon as j=0
			{
				cout << arr[j--] << " ";
			}

			return head;
		}

	};
}



