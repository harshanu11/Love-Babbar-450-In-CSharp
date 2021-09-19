using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _27_array_subset_of_another_array
    {
        /*
            link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
        Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
        Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

        */
        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//// TC: O(N)
//// SC: O(N)
//string isSubset(int a1[], int a2[], int n, int m)
//{
//    unordered_set<int> s;
//    for (int i = 0; i < n; i++)
//    {
//        s.insert(a1[i]);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        if (s.find(a2[i]) == s.end()) return "No";
//    }
//    return "Yes";
//}



//// ----------------------------------------------------------------------------------------------------------------------- //
//// similar solution.
//string isSubset(int a1[], int a2[], int n, int m)
//{

//    unordered_map<int, int> um, um2;

//    for (int i = 0; i < n; i++)
//    {
//        um[a1[i]]++;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        um2[a2[i]]++;
//    }

//    int count = 0;
//    for (auto it = um2.begin(); it != um2.end(); it++)
//    {
//        if (um[it->first] >= it->second)
//        {
//            count++;
//        }
//    }

//    if (count == m)
//        return "Yes";
//    else
//        return "No";
//}