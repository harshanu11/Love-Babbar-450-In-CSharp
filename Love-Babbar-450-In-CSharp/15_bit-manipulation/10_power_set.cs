using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _15_bit_manipulation
{
    public class _10_power_set
    {
        [Fact] public void Test() { }


        /*
            link: https://practice.geeksforgeeks.org/problems/power-set4302/1
        */

        // ----------------------------------------------------------------------------------------------------------------------- //

        // TC: O(2^n)
        private List<string> AllPossibleStrings(string s)
        {
            List<string> ans = new List<string>();
            int len = s.Length;
            // here (1<<len) is equivalent to pow(2, len);
            for (int i = 1; i < (1 << len); i++)
            {
                int temp = i;
                string temp_string = "";
                for (int k = 0; k < len; k++)
                {
                    if ((temp & 1 << i) != 0)
                    {
                        temp_string += s[i];
                    }
                }
                ans.Add(temp_string);
            }
            ans.Sort();
            return new List<string>(ans);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //

    }
}
/*
    link: https://practice.geeksforgeeks.org/problems/power-set4302/1
*/

// ----------------------------------------------------------------------------------------------------------------------- //

//// TC: O(2^n)
//vector<string> AllPossibleStrings(string s)
//{
//	vector<string> ans;
//	int len = s.size();
//	// here (1<<len) is equivalent to pow(2, len);
//	for (int i = 1; i < (1 << len); i++)
//	{
//		int temp = i;
//		string temp_string = "";
//		for (int i = 0; i < len; i++)
//		{
//			if (temp & 1 << i)
//			{
//				temp_string += s[i];
//			}
//		}
//		ans.push_back(temp_string);
//	}
//	sort(ans.begin(), ans.end());
//	return ans;
//}

//// ----------------------------------------------------------------------------------------------------------------------- //