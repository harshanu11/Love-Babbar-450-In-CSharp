using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _16_count_inversion
    {
        /*
    link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

    video (recommended to save time): https://youtu.be/kQ1mJlwW-c0

    condition here is convertion counts if (arr[i]>arr[j] && i<j) <-- keep in mind everytime

        Given an array of integers. Find the Inversion Count in the array. 

        Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
        Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
         
        
        Example 1:
        
        Input: N = 5, arr[] = {2, 4, 1, 3, 5}
        Output: 3
        Explanation: The sequence 2, 4, 1, 3, 5 
        has three inversions (2, 1), (4, 1), (4, 3).
*/


        [Fact] public void Test() { }
    }
}
