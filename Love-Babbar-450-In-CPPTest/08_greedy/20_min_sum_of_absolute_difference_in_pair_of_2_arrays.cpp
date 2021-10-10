/*
	link: https://www.geeksforgeeks.org/minimum-sum-absolute-difference-pairs-two-arrays/#:~:text=It%20consists%20of%20two%20steps,result%20to%20the%20sum%20S.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find minimum sum of absolute
// differences of two arrays.
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
using namespace std;

// Returns minimum possible pairwise absolute
// difference of two arrays.
long long int findMinSum(int a[], int b[], int n)
{
	// Sort both arrays
	sort(a, a + n);
	sort(b, b + n);

	// Find sum of absolute differences
	long long int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + abs(a[i] - b[i]);

	return sum;
}

// Driver code
//int main()
//{
//	// Both a[] and b[] must be of same size.
//	long long int a[] = { 4, 1, 8, 7 };
//	long long int b[] = { 2, 3, 6, 5 };
//	int n = sizeof(a) / sizeof(a[0]);
//	printf("%lld\n", findMinSum(a, b, n));
//	return 0;
//}
