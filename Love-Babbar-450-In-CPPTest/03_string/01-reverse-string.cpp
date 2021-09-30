/*
	link: https://leetcode.com/problems/reverse-string/
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
	TEST_CLASS(StringClass)
	{
	public:

		TEST_METHOD(reverseStringTest)
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
class Solution1 {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};



// ----------------------------------------------------------------------------------------------------------------------- //
// method 2
class Solution2 {
public:
	void reverseString(vector<char>& s) {
		int len = s.size();
		for (int i = 0; i < len / 2; i++) {
			swap(s[i], s[len - i - 1]);
		}
	}
};
