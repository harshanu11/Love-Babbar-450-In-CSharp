using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace stringg
{/*
    link: https://leetcode.com/problems/reverse-string/
*/

    public class _01_reverse_string
    {
        [Fact]
        public void reverse_StringTest()
        {
            var strArr = "123456".ToCharArray();
           var result =  reverseString(strArr);
            rvereseArrayRecursion(strArr, 0, strArr.Length-1);
        }
        public string reverseString(char[] s)
        {
            int len = s.Length;
            for (int i = 0; i < len / 2; i++)
            {
                char temp = s[i];
                s[i] = s[s.Length - 1-i];
                s[s.Length - 1 - i] = temp;
            }
            return new string(s);
        }
        // TC: O(N)
        private void rvereseArrayRecursion(char[] arr, int start, int end)
        {
            if (start >= end) return;
            var temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            rvereseArrayRecursion(arr, start + 1, end - 1);
        }

    }
}
