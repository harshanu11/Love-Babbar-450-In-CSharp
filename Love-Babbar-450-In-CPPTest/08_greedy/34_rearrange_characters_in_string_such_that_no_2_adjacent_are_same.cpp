/*
	link: https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems

	sol (refer codes here): https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

	video: https://youtu.be/69u_bfwoHm0

*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using const. size array
	TC: O(N)
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
using namespace std;

int main61() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = s.size();

		int cnt[26] = { 0 };

		// get count of every char
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}

		int mx = 0;
		for (int i = 0; i < 26; i++) {
			mx = max(mx, cnt[i]);
		}

		if (mx <= (n + 1) / 2) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
