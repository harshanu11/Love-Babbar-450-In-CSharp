﻿using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _09_backtracking
{
    public class _04_remove_invalid_paranthesis
    {
        [Fact]
        public void reverse_arrayTest() { }

/*
	link: https://leetcode.com/problems/remove-invalid-parentheses/

	video (this code gives TLE so tweaked code is below): https://youtu.be/Cbbf5qe5stw
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// this function will return how many
private int getMin(string s)
	{
		Stack<char> st = new Stack<char>();

		foreach (char c in s)
		{
			if (c == '(')
			{
				st.Push(c);
			}
			// we are using else if as to ignore letters
			else if (c == ')')
			{
				if (st.Count == 0)
				{
					st.Push(c);
				}
				else if (st.Peek() == ')')
				{
					st.Push(c);
				}
				else if (st.Peek() == '(')
				{
					st.Pop();
				}
			}
		}
		return st.Count;
	}


	private void backtracking(string s, int minRemAllowed, SortedSet<string> hs, HashSet<string> vis)
	{
		// track record of every string visited at every stack call
		vis.Add(s);

		// if no more letters to remove
		if (minRemAllowed == 0)
		{
			// and our string is balanced then add to the set
			if (getMin(s) == 0)
			{
				hs.Add(s);
			}
			return;
		}

		for (int i = 0; i < s.Length; i++)
		{
			// get left ignoring the ith letter
			string left = s.Substring(0, i);
			// get right ignoring the ith letter
			string right = s.Substring(i + 1);

			// if currently formed string is already visited then ignore the stack call
			//if (vis.find(left + right) != vis.end())
			//{
			//	continue;
			//}
			backtracking(left + right, minRemAllowed - 1, hs, vis);
		}
	}


	private List<string> removeInvalidParentheses(string s)
	{
		// vs.clear();

		int minRemoval = getMin(s);
		SortedSet<string> hs = new SortedSet<string>();
		HashSet<string> vis = new HashSet<string>();

		backtracking(s, minRemoval, hs, vis);

		// finally convert set to vector
		List<string> vs = new List<string>(hs);

		return new List<string>(vs);
	}

}
}
/*
	link: https://leetcode.com/problems/remove-invalid-parentheses/

	video (this code gives TLE so tweaked code is below): https://youtu.be/Cbbf5qe5stw
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
//// this function will return how many
//int getMin(string s)
//{
//	stack<char> st;

//	for (char c : s) {
//	if (c == '(') st.push(c);
//	// we are using else if as to ignore letters
//	else if (c == ')')
//	{
//		if (st.size() == 0) st.push(c);
//		else if (st.top() == ')') st.push(c);
//		else if (st.top() == '(') st.pop();
//	}
//}
//return st.size();
//}


//void backtracking(string s, int minRemAllowed, set<string>& hs, unordered_set<string>& vis)
//{
//	// track record of every string visited at every stack call
//	vis.insert(s);

//	// if no more letters to remove
//	if (minRemAllowed == 0)
//	{
//		// and our string is balanced then add to the set
//		if (getMin(s) == 0)
//		{
//			hs.insert(s);
//		}
//		return;
//	}

//	for (int i = 0; i < s.size(); i++)
//	{
//		// get left ignoring the ith letter
//		string left = s.substr(0, i);
//		// get right ignoring the ith letter
//		string right = s.substr(i + 1);

//		// if currently formed string is already visited then ignore the stack call
//		if (vis.find(left + right) != vis.end()) continue;
//		backtracking(left + right, minRemAllowed - 1, hs, vis);
//	}
//}


//vector<string> removeInvalidParentheses(string s)
//{
//	// vs.clear();

//	int minRemoval = getMin(s);
//	set<string> hs;
//	unordered_set<string> vis;

//	backtracking(s, minRemoval, hs, vis);

//	// finally convert set to vector
//	vector<string> vs(hs.begin(), hs.end());

//	return vs;
//}