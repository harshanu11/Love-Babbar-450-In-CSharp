/*
	link: https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1#

	sol: https://www.geeksforgeeks.org/maximize-sum-arrii/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N logN)
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
const long long int mod = (int)1e9 + 7;
int Maximize(int a[], int n)
{
	long long int pro = 0;
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		pro += (i * (a[i] % mod)) % mod;
		pro = pro % mod;
	}
	return pro;
}