﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;
// devide and concore
//https://leetcode.com/problems/maximum-subarray/
namespace ConsoleTest
{
    public class ConsoleTest
    {
        [Fact]
        public void reverse_arrayTest()
        {
            //var nums = new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            var nums = new int[] { -2, -2 };
            AllContigusSubArray(nums);
            AllPossibleSubArrayRec(new int[] { 1, 2, 3 }, 0, 0);
        }
        List<string> vs1 = new List<string>();
        void AllPossibleSubArrayRec(int[] arr,
                        int start, int end)
        {
            // Stop if we have reached
            // the end of the array
            if (end == arr.Length)
                return;

            // Increment the end point
            // and start from 0
            else if (start > end)
                AllPossibleSubArrayRec(arr, 0, end + 1);

            // Print the subarray and
            // increment the starting point
            else
            {
                string str = "[";
                Debug.Write("[");
                for (int i = start; i < end; i++)
                {
                    str += arr[i] + ", ";
                    Debug.Write(arr[i] + ", ");
                    vs1.Add(str);
                }
                str = "]";
                Debug.WriteLine(arr[end] + "]");
                AllPossibleSubArrayRec(arr, start + 1, end);
            }
            return;
        }
        public void AllContigusSubArray(int[] nums)
        {
            List<string> vs = new List<string>();
            for (int i = 0; i < nums.Length; i++)
            {
                string s = "";
                for (int j = i; j < nums.Length; j++)
                {
                    s += "," + nums[j];
                }
                vs.Add(s);
            }
        }
    }

}
