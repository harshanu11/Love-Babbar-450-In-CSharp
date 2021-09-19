using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _21_subarray_with_sum_0
    {
        /*
            link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

        Rearrange array in alternating positive & negative items with O(1) extra space | Set 1
        Input:  arr[] = {1, 2, 3, -4, -1, 4}
        Output: arr[] = {-4, 1, -1, 2, 3, 4}
        
        Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
        output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
        */

        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
//bool subArrayExists(int arr[], int n)
//{
//    // if the element 0 itself is present.
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] == 0) return 1;
//    }
//    set<int> s;
//    s.insert(arr[0]);
//    for (int i = 1; i < n; i++)
//    {
//        arr[i] += arr[i - 1];

//        //   
//        if (s.find(arr[i]) != s.end() || arr[i] == 0) return 1;
//        s.insert(arr[i]);
//    }
//    return 0;
//}



//// ----------------------------------------------------------------------------------------------------------------------- //
//// alternate solution
//bool subArrayExists(int arr[], int n)
//{
//    //using map to store the prefix sum which has appeared already.
//    unordered_map<int, bool> sumMap;

//    int sum = 0;
//    //iterating over the array.
//    for (int i = 0; i < n; i++)
//    {
//        //storing prefix sum.
//        sum += arr[i];

//        //if prefix sum is 0 or if it is already present in map then it is
//        //repeated which means there is a subarray whose summation is 0,
//        //so we return true.
//        if (sum == 0 || sumMap[sum] == true)
//            return true;

//        //storing true in map for every prefix sum obtained.
//        sumMap[sum] = true;
//    }
//    //returning false if we don't get any subarray with 0 sum.
//    return false;
//}
