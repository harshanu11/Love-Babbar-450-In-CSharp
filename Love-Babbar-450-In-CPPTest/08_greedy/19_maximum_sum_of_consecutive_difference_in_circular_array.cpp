/*
	link: https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1
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

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
	// TEST_CLASS(BTSort)
	// {
	// public:

	//     TEST_METHOD(Test)
	//     {
	//         std::string charM = "harhs";
	//         int age = 14;
	//         age = 55;
	//         std::string lastName = "<<charM <<singh";

	//     }
	// };
}
// ----------------------------------------------------------------------------------------------------------------------- //
/*
	short and efficient
	TC: O(N)
	SC: O(1)
*/
long long int maxSum1(int arr[], int n)
{
	long long int sum = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n / 2; i++)
	{
		sum -= (2 * arr[i]);
		sum += (2 * arr[n - i - 1]);
	}
	return sum;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N)
	SC: O(N)
*/
typedef long long int lli;

long long int maxSum2(int arr[], int n)
{
	sort(arr, arr + n);

	int newArr[5], j = 0;
	lli sum = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		newArr[j] = arr[i];
		j += 2;
	}

	j = 1;
	for (int i = n - 1; i >= n / 2; i--) {
		newArr[j] = arr[i];
		j += 2;
	}

	for (int i = 0; i < n - 1; i++) {
		sum += abs(newArr[i] - newArr[i + 1]);
	}

	sum += abs(newArr[0] - newArr[n - 1]);
	return sum;
}