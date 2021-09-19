using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _30_choclate_distribution_problem
    {
        /*
    link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

        Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. 
        Each packet can have a variable number of chocolates. 
        There are M students, the task is to distribute chocolate packets among M students such that :
        1. Each student gets exactly one packet.
        2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.


        Input:
        N = 8, M = 5
        A = {3, 4, 1, 9, 56, 7, 9, 12}
        Output: 6
        Explanation: The minimum difference between 
        maximum chocolates and minimum chocolates 
        is 9 - 3 = 6 by choosing following M packets :
        {3, 4, 9, 7, 9}.

*/

        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//long long findMinDiff(vector<long long> a, long long n, long long m)
//{
//    // sorted so that we can different window(sub-array) of size m.
//    sort(a.begin(), a.end());

//    long long ans = a[m - 1] - a[0];    // took first window from 0 to m-1.

//    // now we iterate every window(sub-array) and check for the max-min from that range.
//    for (int i = 1; i < n - m + 1; i++)
//    {
//        ans = min(a[i + m - 1] - a[i], ans);
//    }
//    return ans;
//}