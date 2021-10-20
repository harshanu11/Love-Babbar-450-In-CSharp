/*
	link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

	note: array is pass by reference so no need to worry while changing value it will change in original array.
*/
//#include "pch.h"
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
	TEST_CLASS(ArrayTest)
	{
	public:

		TEST_METHOD(RevrseTest)
		{
			int arr[] = { 1000, 11, 445, 1, 330, 3000 };
			rvereseArrayRecur(arr, 0, 5);
			rvereseArray1(arr, 0, 5);
			rvereseArrayBit(arr, 0, 5);


		}
		// ----------------------------------------------------------------------------------------------------------------------- //
		// TC: O(N)
		void rvereseArray1(int arr[], int start, int end)
		{
			while (start < end)
			{
				int temp = arr[start];
				arr[start] = arr[end];
				arr[end] = temp;
				start++;
				end--;
			}
		}


		// ----------------------------------------------------------------------------------------------------------------------- //
		// TC: O(N)
		void rvereseArrayRecur(int arr[], int start, int end)
		{
			if (start >= end)
				return;

			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;

			// Recursive Function calling
			rvereseArrayRecur(arr, start + 1, end - 1);
		}
		// ----------------------------------------------------------------------------------------------------------------------- //
		// TC: O(N)
		// TC: O(N)
		void rvereseArrayBit(int arr[], int start, int end)
		{
			for (int a = 0; a < (start+end) / 2; a++)
			{
				arr[a] = arr[a] ^ arr[end - a];
				arr[end - a] = arr[a] ^ arr[end - a];
				arr[a] = arr[a] ^ arr[end  - a];
			}
		}
	};
}


