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
			vector<char> str = {'1','2'};
			reverseString(str);
		}
		// TC: O(N)
		void rvereseArrayRecursion(char arr[], int start, int end)
		{
			if (start >= end) return;
			auto temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			rvereseArrayRecursion(arr, start + 1, end - 1);
		}
		void reverseString(vector<char>& s) {
			int len = s.size();
			for (int i = 0; i < len / 2; i++) {
				swap(s[i], s[len - i - 1]);
			}
		}
	};
}
