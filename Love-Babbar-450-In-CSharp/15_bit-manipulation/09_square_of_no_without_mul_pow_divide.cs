using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _15_bit_manipulation
{
    public class _09_square_of_no_without_mul_pow_divide
    {
        [Fact] public void Test() { }


        /*
            link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/#:~:text=Given%20an%20integer%20n%2C%20calculate,*%2C%20%2F%20and%20pow().&text=A%20Simple%20Solution%20is%20to%20repeatedly%20add%20n%20to%20result.
            sol: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/#:~:text=Given%20an%20integer%20n%2C%20calculate,*%2C%20%2F%20and%20pow().&text=A%20Simple%20Solution%20is%20to%20repeatedly%20add%20n%20to%20result.
        */

        // ----------------------------------------------------------------------------------------------------------------------- //

        // naive method
        private int without_MPD(int n)
        {
            n = Math.Abs(n);
            for (int i = 0; i < n; i++)
            {
                n += n;
            }
            return n;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

        // approach 2
        // TC: O(log N) 
        private int without_MPD1(int n)
        {
            n = Math.Abs(n);
            if (n == 0)
            {
                return 0;
            }
            if (n == 1)
            {
                return 1;
            }
            if ((n % 2) != 0)
            {
                return ((without_MPD(n / 2) << 2) + ((n / 2) << 2) + 1);
            }
            else
            {
                return (without_MPD(n / 2) << 2);
            }
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

        // approach 3
        // TC: O(log N)
        private int without_MPD2(int n)
        {
            n = Math.Abs(n);
            int ans = n;
            for (int i = 0; i < 32; i++)
            {
                int temp = (1 << i);
                if ((temp & n) != 0)
                {
                    ans += (n << i);
                }
            }
            return ans;
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

    }
}
