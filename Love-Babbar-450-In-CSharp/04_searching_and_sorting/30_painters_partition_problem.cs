/*
    link: https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

    video [approach]: https://youtu.be/2JSQIhPcHQg

    sol1: https://www.geeksforgeeks.org/painters-partition-problem/
    sol2 (using binary search): https://www.geeksforgeeks.org/painters-partition-problem-set-2/

    video [code]: https://youtu.be/U4vEszMVNsM
min time to job done
Input:
n = 5
k = 3 painter
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35

*/

//// ----------------------------------------------------------------------------------------------------------------------- //
//bool isValid(int* arr, int n, int k, long long maxTime) {
//    long long painters = 1;
//    long long t = 0;
//    for (long long i = 0;i < n;i++) {
//        t += arr[i];
//        if (t > maxTime) {
//            painters++;
//            t = arr[i];
//        }
//        if (painters > k) return false;
//    }
//    return true;
//}

//long long minTime(int arr[], int n, int k)
//{
//    long long lb = 0, ub = 0;
//    long long ans = 0;
//    for (long long i = 0;i < n;i++) {
//        lb = max(lb, (long long)arr[i]);
//        ub += arr[i];
//    }

//    while (lb <= ub) {
//        long long mid = (lb + ub) / 2;

//        if (isValid(arr, n, k, mid)) {
//            ans = mid;
//            ub = mid - 1;
//        }
//        else lb = mid + 1;
//    }
//    return ans;
//}