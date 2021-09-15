using System;
using System.Collections.Generic;
using System.Text;

namespace Love_Babbar_450_In_CSharp._15_bit_manipulation
{
    public class _01_count_set_bits_in_num
    {
        // https://practice.geeksforgeeks.org/problems/set-bits0143/1
        public int setBits1(int N)
        {
            // Write Your Code here
            return 0;// __builtin_popcount(N);
        }
        public int setBits2(int N)
        {
            // Write Your Code here

            int ans = 0;
            while (N != 0)
            {
                if ((N & 1) != 0)
                {
                    ans++;
                }
                N = N >> 1;
            }
            return ans;
        }
        public int setBits3(int N)
        {
            // Write Your Code here

            int ans = 0;
            for (int i = 0; i < 32; i++)
            {
                if ((N & (1 << i)) != 0)
                {
                    ans++;
                }
            }
            return ans;
        }
    }
}
