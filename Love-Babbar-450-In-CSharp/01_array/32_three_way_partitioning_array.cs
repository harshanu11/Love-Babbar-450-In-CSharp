using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _32_three_way_partitioning_array
    {
        /*
    link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
        Three way partitioning 
Easy Accuracy: 50.02% Submissions: 54381 Points: 2
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]

*/
        [Fact] public void Test() { }
    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
*/



//// ----------------------------------------------------------------------------------------------------------------------- //
//void threeWayPartition(vector<int>& array, int a, int b)
//{
//    int low = 0, high = array.size() - 1, mid = 0;

//    while (mid <= high)
//    {
//        if (array[mid] < a)
//        {
//            swap(array[mid++], array[low++]);   // we r sure after swap we won't get <a, bcoz it would have processed earlier.
//        }
//        else if (array[mid] > b)
//        {
//            swap(array[high--], array[mid]);    // here it is possible that after swap we can get >b value again hence no increment in mid.
//        }
//        else mid++;
//    }
//}