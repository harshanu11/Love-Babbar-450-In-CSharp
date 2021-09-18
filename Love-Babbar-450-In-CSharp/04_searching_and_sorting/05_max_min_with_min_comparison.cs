using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _04_searching_and_sorting
{
    public class _05_max_min_with_min_comparison
    {
        [Fact]
        public void reverse_arrayTest() { }


        /*
            link: https://practice.geeksforgeeks.org/problems/middle-of-three2926/1
        */


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            TC: O(1)
        */
        private int middle1(int A, int B, int C)
        {
            //code here//Position this line where user code will be pasted.
            int sum = A + B + C;
            //sum -= min({ A, B, C}) +max({ A, B, C});
            return sum;
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            TC: O(1)
        */
        private int middle2(int A, int B, int C)
        {
            if (A < B)
            {
                return (A > C) ? A : Math.Min(C, B);
            }
            return (A < C) ? A : Math.Max(B, C);
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            similar solution as above.
            TC: O(1)
        */
        private int middle3(int A, int B, int C)
        {
            if (A < B)
            {
                return (B < C) ? B : Math.Max(A, C);
            }
            return (A < C) ? A : Math.Max(B, C);
        }

    }
}
