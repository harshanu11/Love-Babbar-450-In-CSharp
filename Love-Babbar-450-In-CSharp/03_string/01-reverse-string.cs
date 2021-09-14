using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace Love_Babbar_450_In_CSharp._03_string
{/*
    link: https://leetcode.com/problems/reverse-string/
*/

    public class _01_reverse_string
    {
        [Fact]
        public void reverse_arrayTest()
        {
            
           var result =  reverseString("123456".ToCharArray());
        }
        public void reverseStringInBuilt(List<char> s)
        {
            s.Reverse();

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

    }
}
