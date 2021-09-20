/*
    link: https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1
Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, 
there are 7 0s and 1 1s, so number 
of 0s - number of 1s is 6. 
*/

//// ----------------------------------------------------------------------------------------------------------------------- //

//int maxSubstring(string s)
//{
//    int len = s.size();
//    int dp[len];
//    dp[0] = (s[0] == '1') ? -1 : 1;
//    int omax = dp[0];
//    for (int i = 1;i < len;i++) {
//        // if char is 1 then give it -1 or prev_count - 1.
//        if (s[i] == '1') {
//            dp[i] = max(-1, dp[i - 1] - 1);
//        }
//        // if char is 0 then 1 or prev_count + 1.
//        else {
//            dp[i] = max(1, dp[i - 1] + 1);
//        }
//        // main_part find overall max parallely.
//        omax = max(omax, dp[i]);
//    }
//    return omax;
//}

//// ----------------------------------------------------------------------------------------------------------------------- //