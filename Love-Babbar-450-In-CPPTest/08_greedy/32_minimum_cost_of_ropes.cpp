/*
	link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

	sol: https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
	(refer another min-heap code)
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
	using priority_queue

	Time Complexity: O(nLogn), assuming that we use a O(nLogn) sorting algorithm.
		Note that heap operations like insert and extract take O(Logn) time.
	Auxiliary Complexity: O(n).
		The space required to store the values in min heap
*/
int minCost(int arr[], int n)
{
	// Create a priority queue
	// https:// www.geeksforgeeks.org/priority-queue-in-cpp-stl/
	// By default 'less' is used which is for decreasing order
	// and 'greater' is used for increasing order
	priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);

	// Initialize result
	int res = 0;

	// While size of priority queue is more than 1
	while (pq.size() > 1) {
		// Extract shortest two ropes from pq
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		// Connect the ropes: update result and
		// insert the new rope to pq
		res += first + second;
		pq.push(first + second);
	}

	return res;
}