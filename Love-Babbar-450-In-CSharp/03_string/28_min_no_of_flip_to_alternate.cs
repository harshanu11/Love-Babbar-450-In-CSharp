/*
    link: https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1
Input:
S = "001"
Output: 1
Explanation: We can flip the 0th bit to 1
to have "101".
​Example 2:

Input: 
S = "0001010111"
Output: 2
Explanation: We can flip the 1st and 8th bit
to have "0101010101".
*/


// ----------------------------------------------------------------------------------------------------------------------- //
//int minFlips(string s)
//{
//    // your code here
//    int ans1 = 0, ans2 = 0;


//    for (int i = 0;i < s.size();i++) {
//        // for 1010101....
//        if (i % 2 == 0 && s[i] != '1' || i % 2 && s[i] != '0') ans1++;
//        // for 0101010...
//        if (i % 2 == 0 && s[i] != '0' || i % 2 && s[i] != '1') ans2++;
//    }
//    return min(ans1, ans2);
//}