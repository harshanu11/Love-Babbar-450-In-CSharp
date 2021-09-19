using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _19_common_ele_in_3_sorted_arr
    {

        /*
			link: https://practice.geeksforgeeks.org/problems/common-elements1132/1

        
            Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
            Note: can you take care of the duplicates without using any additional Data Structure?
            
            Example 1:
            
            Input:
            n1 = 6; A = {1, 5, 10, 20, 40, 80}
            n2 = 5; B = {6, 7, 20, 80, 100}
            n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
            Output: 20 80
            Explanation: 20 and 80 are the only
            common elements in A, B and C.
		*/

        [Fact] public void Test() { }



        // ----------------------------------------------------------------------------------------------------------------------- //
        private List<int> commonElements(int[] a, int[] b, int[] c, int n1, int n2, int n3)
        {
            SortedSet<int> ans = new SortedSet<int>();
            int i = 0;
            int j = 0;
            int k = 0;
            while (i < n1 && j < n2 && k < n3)
            {
                if (a[i] == b[j] && a[i] == c[k])
                {
                    ans.Add(a[i]);
                    i++;
                    j++;
                    k++;
                }
                else if (a[i] < b[j] || a[i] < c[k])
                {
                    i++;
                }
                else if (b[j] < a[i] || b[j] < c[k])
                {
                    j++;
                }
                else if (c[k] < b[j] || c[k] < a[i])
                {
                    k++;
                }
            }
            List<int> nn = new List<int>();
            //C++ TO C# CONVERTER TODO TASK: The following line could not be converted:
            //for (ele : ans)
            //{
            //    nn.Add(ele);
            //}
            return new List<int>(nn);
        }



        // ----------------------------------------------------------------------------------------------------------------------- //
        // alternate solution (improved)


    }
}
