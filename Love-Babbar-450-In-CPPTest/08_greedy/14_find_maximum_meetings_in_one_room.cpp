/*
	link: https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N logN)
*/

// C++ program to find maximum number of meetings
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

// Structure for storing starting time,
// finishing time and position of meeting.
struct meeting {
	int start;
	int end;
	int pos;
};

// Comparator function which can compare
// the second element of structure used to
// sort pairs in increasing order of second value.
bool comparator(struct meeting m1, meeting m2)
{
	return (m1.end < m2.end);
}

// Function for finding maximum meeting in one room
void maxMeeting(int s[], int f[], int n)
{
	struct meeting meet[5];
	for (int i = 0; i < n; i++)
	{
		// Starting time of meeting i.
		meet[i].start = s[i];

		// Finishing time of meeting i
		meet[i].end = f[i];

		// Original position/index of meeting
		meet[i].pos = i + 1;
	}

	// Sorting of meeting according to their finish time.
	sort(meet, meet + n, comparator);

	// Vector for storing selected meeting.
	vector<int> m;

	// Initially select first meeting.
	m.push_back(meet[0].pos);

	// time_limit to check whether new
	// meeting can be conducted or not.
	int time_limit = meet[0].end;

	// Check for all meeting whether it
	// can be selected or not.
	for (int i = 1; i < n; i++) {
		if (meet[i].start >= time_limit)
		{
			// Push selected meeting to vector
			m.push_back(meet[i].pos);

			// Update time limit.
			time_limit = meet[i].end;
		}
	}

	// Print final selected meetings.
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
}

// Driver code
int main48()
{
	// Starting time
	int s[] = { 1, 3, 0, 5, 8, 5 };

	// Finish time
	int f[] = { 2, 4, 6, 7, 9, 9 };

	// Number of meetings.
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	maxMeeting(s, f, n);

	return 0;
}
