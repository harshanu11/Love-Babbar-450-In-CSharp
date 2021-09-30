/*
	link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
	TEST_CLASS(StringClass)
	{
	public:

		TEST_METHOD(isPlaindromeTest)
		{
			std::string charM = "harhs";
			int age = 14;
			age = 55;
			std::string lastName = "<<charM <<singh";

		}
	};
}
// ----------------------------------------------------------------------------------------------------------------------- //
// method 1
class Solution {
public:


	int isPlaindrome(string s)
	{
		// Your code goes here
		int len = s.size();
		for (int i = 0;i < len / 2;i++) {
			if (s[i] != s[len - i - 1]) return 0;
		}
		return 1;
	}

};



// ----------------------------------------------------------------------------------------------------------------------- //
// method 2
class Solution2 {
public:


	int isPlaindrome(string s)
	{
		// Your code goes here
		string temp = s;
		reverse(temp.begin(), temp.end());
		return (temp == s);
	}

};