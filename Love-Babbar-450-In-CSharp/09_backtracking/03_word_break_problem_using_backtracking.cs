using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _09_backtracking
{
    public class _03_word_break_problem_using_backtracking
    {

        /*
            link: https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

            video: https://youtu.be/LmHWIsBQBU4

            sol (DP solution): https://www.geeksforgeeks.org/word-break-problem-dp-32-set-2/
        */


        [Fact]
        public void reverse_arrayTest()

        {

        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            TC: O(N * N), one for to iterate the string and other to recursively perform again
            SC: O(dict.size())
        */

        // to access dict. word in O(1)
        private HashSet<string> dict = new HashSet<string>();
        // to push the final ans.
        private List<string> allAns = new List<string>();

        private void backtracking(string str, string ans)
        {
            // it means we reach the end for the certain combination
            if (str.Length == 0)
            {
                // to remove the extra space at the end we did ans.size()-1
                allAns.Add(ans.Substring(0, ans.Length - 1));
                return;
            }

            for (int i = 0; i < str.Length; i++)
            {
                // get left sub-string each time
                string left = str.Substring(0, i + 1);

                // if left sub-string is present
                //if (dict.find(left) != dict.end())
                //{

                //    // find the right sub-string and try it recursively to break;
                //    string right = str.Substring(i + 1);
                //    backtracking(right, ans + left + " ");
                //}
            }
        }

        private List<string> wordBreak(int n, List<string> wordDict, string s)
        {
            dict.Clear();
            allAns.Clear();

            foreach (string curr in wordDict)
            {
                dict.Add(curr);
            }

            // trying out every break possible
            backtracking(s, "");

            return new List<string>(allAns);
        }

    }
}
