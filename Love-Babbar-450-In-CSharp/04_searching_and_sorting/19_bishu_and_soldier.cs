/*
    link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/
https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
roblem
Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.

The second line contains an array of N numbers denoting the power of each soldier

This third line contains Q, which denotes the number of rounds.

Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:

For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.
7
1 2 3 4 5 6 7
3
3
10
2

op
Sample Output
3 6
7 28
2 3

*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//#include<bits/stdc++.h>
//using namespace std;

//int main() {
//    // total ele.
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    for (int i = 0;i < n;i++) {
//        cin >> arr[i];
//    }

//    // total rounds 
//    int q;
//    cin >> q;
//    while (q--) {
//        // power for current round
//        int pow;
//        cin >> pow;

//        // total sum by killing enemy
//        int sum = 0;
//        // count of enemy dead by curr power
//        int count = 0;

//        for (int i = 0;i < n;i++) {
//            if (arr[i] <= pow) sum += arr[i], count++;
//        }
//        cout << count << " " << sum << endl;
//    }
//}