/*
	link: https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
*/

#include "01_level_order_traversal.cpp"
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

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
	//TEST_CLASS(BTSort)
	//{
	//public:

	//	TEST_METHOD(Test)
	//	{
	//		std::string charM = "harhs";
	//		int age = 14;
	//		age = 55;
	//		std::string lastName = "<<charM <<singh";

	//	}
	//};
}

class construct_binary_tree_from_string_using_bracket_presentation
{
	// ----------------------------------------------------------------------------------------------------------------------- //
	/*
		Time Complexity: O(N2)
		Auxiliary Space: O(N)
	*/

	/* A binary tree node has data, pointer to left
	child and a pointer to right child */

	/* Helper function that allocates a new node */
	nodeBT* newNode(int data)
	{
		nodeBT* node = (nodeBT*)malloc(sizeof(nodeBT));
		node->data = data;
		node->left = node->right = NULL;
		return (node);
	}

	/* This function is here just to test */
	void preOrder(nodeBT* node)
	{
		if (node == NULL)
			return;
		printf("%d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}

	// function to return the index of close parenthesis
	int findIndex(string str, int si, int ei)
	{
		if (si > ei)
			return -1;

		// Inbuilt stack
		stack<char> s;

		for (int i = si; i <= ei; i++) {

			// if open parenthesis, push it
			if (str[i] == '(')
				s.push(str[i]);

			// if close parenthesis
			else if (str[i] == ')') {
				if (s.top() == '(') {
					s.pop();

					// if stack is empty, this is
					// the required index
					if (s.empty())
						return i;
				}
			}
		}
		// if not found return -1
		return -1;
	}

	// function to construct tree from string
	nodeBT* treeFromString(string str, int si, int ei)
	{
		// Base case
		if (si > ei)
			return NULL;

		// new root
		nodeBT* root = newNode(str[si] - '0');
		int index = -1;

		// if next char is '(' find the index of
		// its complement ')'
		if (si + 1 <= ei && str[si + 1] == '(')
			index = findIndex(str, si + 1, ei);

		// if index found
		if (index != -1) {

			// call for left subtree
			root->left = treeFromString(str, si + 2, index - 1);

			// call for right subtree
			root->right
				= treeFromString(str, index + 2, ei - 1);
		}
		return root;
	}

	// Driver Code
	int main()
	{
		string str = "4(2(3)(1))(6(5))";
		nodeBT* root = treeFromString(str, 0, str.length() - 1);
		preOrder(root);
	}








	// ----------------------------------------------------------------------------------------------------------------------- //
	/*
		another recursive approach
	*/

	// custom data type for tree building
	struct nodeBT1 {
		int data;
		struct nodeBT1* left;
		struct nodeBT1* right;
		nodeBT1(int val)
		{
			data = val;
			left = right = NULL;
		}
	};

	// Below function accepts sttring and a pointer variable as
	// an argument
	// and draw the tree. Returns the root of the tree
	nodeBT* constructtree(string s, int* start)
	{
		// Assuming there is/are no negative
		// character/characters in the string
		if (s.size() == 0 || *start >= s.size())
			return NULL;

		// constructing a number from the continuous digits
		int num = 0;
		while (*start < s.size() && s[*start] != '('
			&& s[*start] != ')') {
			int num_here = (int)(s[*start] - '0');
			num = num * 10 + num_here;
			*start = *start + 1;
		}

		// creating a node from the constructed number from
		// above loop
		struct nodeBT* root = new nodeBT(num);

		// check if start has reached the end of the string
		if (*start >= s.size())
			return root;

		// As soon as we see first right parenthesis from the
		// current node we start to construct the tree in the
		// left
		if (*start < s.size() && s[*start] == '(') {
			*start = *start + 1;
			root->left = constructtree(s, start);
		}
		if (*start < s.size() && s[*start] == ')')
			*start = *start + 1;

		// As soon as we see second right parenthesis from the
		// current node we start to construct the tree in the
		// right
		if (*start < s.size() && s[*start] == '(') {
			*start = *start + 1;
			root->right = constructtree(s, start);
		}
		if (*start < s.size() && s[*start] == ')')
			*start = *start + 1;
		return root;
	}

	
	int main2()
	{
		string s = "4(2(3)(1))(6(5))";
		// cin>>s;
		int start = 0;
		nodeBT* root = constructtree(s, &start);
		//preorder(root);
		return 0;
	}

};
