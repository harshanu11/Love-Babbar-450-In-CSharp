using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _15_bit_manipulation
{
    public class _05_no_is_power_of_2
    {
        [Fact]
        public void reverse_arrayTest() { }


        /*
            link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
        */

        // ----------------------------------------------------------------------------------------------------------------------- //

        // method 1 (naive method) ( :) not for corporate use)
        private bool isPowerofTwo(long n)
        {
            if (n == 0)
            {
                return false;
            }
            double power = 0;// isPowerofTwo(n);
            if (Math.Floor(power) == power)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

        // method 2
        // TC: O(log N)
        // crux: if there is only 1 set bit then and then only it will be power of 2. try diff. combo as well but will not work.
        private long countSetBit(long n)
        {
            long count = 0;
            while (n != 0)
            {
                if ((n & 1) != 0)
                {
                    count++;
                }
                n >>= 1;
            }
            return count;
        }
        private bool isPowerofTwo1(long n)
        {
            if (countSetBit(n) == 1L)
            {
                return true;
            }
            return false;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// method 1 (naive method) ( :) not for corporate use)
//bool isPowerofTwo(long long n)
//{
//    if (n == 0) return false;
//    long double power = log2(n);
//    if (floor(power) == power) return true;
//    else return false;
//}

//// ----------------------------------------------------------------------------------------------------------------------- //

//// method 2
//// TC: O(log N)
//// crux: if there is only 1 set bit then and then only it will be power of 2. try diff. combo as well but will not work.
//long long countSetBit(long long n)
//{
//    long long count = 0;
//    while (n)
//    {
//        if (n & 1) count++;
//        n >>= 1;
//    }
//    return count;
//}
//bool isPowerofTwo(long long n)
//{
//    if (countSetBit(n) == 1LL) return true;
//return false;
//}

//// ----------------------------------------------------------------------------------------------------------------------- //