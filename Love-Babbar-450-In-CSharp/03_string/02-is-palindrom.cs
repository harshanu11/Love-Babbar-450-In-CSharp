using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _03_string
{
    /*
        link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
    */

    public class _02_is_palindrom
    {
        [Fact]
        public void palindrom_stringTest()
        {
            var ans = isPlaindrome1("racecar");
            ans = isPlaindrome1("racecar");
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        // method 1
        public int isPlaindrome1(string s)
        {
            // Your code goes here
            int len = s.Length;
            for (int i = 0; i < len / 2; i++)
            {
                if (s[i] != s[len - i - 1])
                {
                    return 0;
                }
            }
            return 1;
        }
    }
}
