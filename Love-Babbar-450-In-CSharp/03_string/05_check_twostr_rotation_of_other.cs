using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _03_string
{
    public class _05_check_rotation_of_other
    {
        [Fact]
        public void reverse_arrayTest()
        {


        }

        /*
            link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

            ref for string::npos: https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/
        */


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using concatenation
        */
        private void check_rotated(string a, string b)
        {
            // for eg.: a="AACD" b="ACDA"

            a += a;
            // a="AACDAACD"
            // now string b must be sub-string in a hence.

            // find will return 0th based index from where the substring will start.
            if (a.IndexOf(b) != -1)
            {
                Debug.Write("YES");
            }
            else
            {
                Debug.Write("NO");
            }
        }



        // ----------------------------------------------------------------------------------------------------------------------- //
        // this was just to check ele. in array
        private void algo()
        {
            List<int> a = new List<int>();
            List<int> b = new List<int>();
            a = new List<int>() { 1, 2, 3, 4, 5, 6 };
            b = new List<int>() { 5, 6, 1, 2, 3, 4 };
            //int idx = find(b.GetEnumerator(), b.end(), a[0]) - b.GetEnumerator();
            //rotate(b.GetEnumerator(), b.GetEnumerator() + idx, b.end());
            if (a == b)
            {
                Debug.Write("YES");
                Debug.Write("\n");
            }
            else
            {
                Debug.Write("NO");
                Debug.Write("\n");
            }
        }

    }
}
/*
    link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

    ref for string::npos: https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    using concatenation
//*/
//void check_rotated(string a, string b)
//{
//    // for eg.: a="AACD" b="ACDA"

//    a += a;
//    // a="AACDAACD"
//    // now string b must be sub-string in a hence.

//    // find will return 0th based index from where the substring will start.
//    if (a.find(b) != string::npos) cout << "YES";
//    else cout << "NO";
//}



//// ----------------------------------------------------------------------------------------------------------------------- //
//// this was just to check ele. in array
//void algo()
//{
//    vector<int> a, b;
//    a = { 1,2,3,4,5,6 };
//    b = { 5,6,1,2,3,4 };
//    int idx = find(b.begin(), b.end(), a[0]) - b.begin();
//    rotate(b.begin(), b.begin() + idx, b.end());
//    if (a == b) cout << "YES" << endl;
//    else cout << "NO" << endl;
//}