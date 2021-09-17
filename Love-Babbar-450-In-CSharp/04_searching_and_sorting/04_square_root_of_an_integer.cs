using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _04_searching_and_sorting
{
    public class _04_square_root_of_an_integer
    {
        [Fact]
        public void reverse_arrayTest()
        {


        }


        /*
            link: https://practice.geeksforgeeks.org/problems/count-squares3649/1
        */



        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            note: said "less than N"
            TC: O(1)
        */
        private double countSquares1(double N)
        {

            double ans = Math.Sqrt(N - 1);

            return ans;
        }



        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            TC: O(sqrt(n-1))
        */
        private int countSquares2(int N)
        {
            // code here
            int i = 1;
            int count = 0;
            while ((i * i) < N)
            {
                i++;
            }
            return i - 1;
        }

    }
}
