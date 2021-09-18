using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _14_DP
{
    public class _05_LC_substring
    {
        [Fact]
        public void reverse_arrayTest() { }

        /*
            link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

            variation of DP_tut/LCS/2_LC_substring...
        */

        // ----------------------------------------------------------------------------------------------------------------------- //

        private int[][] memo = RectangularArrays.RectangularIntArray(1001, 1001);

        private int longestCommonSubstr(string s1, string s2, int n, int m)
        {
            // memset(memo, -1, sizeof(memo));
            // your code here
            int result = 0;
            for (int i = 0; i < n + 1; i++)
            {
                memo[i][0] = 0;
            }
            for (int j = 0; j < m + 1; j++)
            {
                memo[0][j] = 0;
            }

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < m + 1; j++)
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        memo[i][j] = 1 + memo[i - 1][j - 1];
                        result = Math.Max(result, memo[i][j]);
                    }
                    else
                    {
                        memo[i][j] = 0;
                    }
                }
            }
            return result;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

        //Helper class added by C++ to C# Converter:

        //----------------------------------------------------------------------------------------
        //	Copyright © 2006 - 2021 Tangible Software Solutions, Inc.
        //	This class can be used by anyone provided that the copyright notice remains intact.
        //
        //	This class includes methods to convert C++ rectangular arrays (jagged arrays
        //	with inner arrays of the same length).
        //----------------------------------------------------------------------------------------
        internal static class RectangularArrays
        {
            public static int[][] RectangularIntArray(int size1, int size2)
            {
                int[][] newArray = new int[size1][];
                for (int array1 = 0; array1 < size1; array1++)
                {
                    newArray[array1] = new int[size2];
                }

                return newArray;
            }
        }

    }
}
