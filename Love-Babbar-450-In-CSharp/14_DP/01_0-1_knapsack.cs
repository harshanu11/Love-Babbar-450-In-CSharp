using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace DP
{
    public class _01_0_1_knapsack
    {
        /*
			link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
		*/

        private static int[,] memoArr = new int[1001, 1001];
        [Fact]
        public void reverse_arrayTest()
        {

            for (int r = 0; r < memoArr.GetLength(0); r++)
            {
                for (int c = 0; c < memoArr.GetLength(1); c++)
                {
                    memoArr[r, c] = -1;
                }
            }
            // ans = 9
            var ans = knapSack(4, new int[] { 1, 2, 3 }, new int[] { 4, 5, 1 }, 3);
            ans = knapSackGeek(4, new int[] { 1, 2, 3 }, new int[] { 4, 5, 1 }, 3);
            for (int r = 0; r < memoArr.GetLength(0); r++)
            {
                for (int c = 0; c < memoArr.GetLength(1); c++)
                {
                    memoArr[r, c] = -1;
                }
            }
            // ans 0 
            ans = knapSack(3, new int[] { 1, 2, 3 }, new int[] { 4, 5, 1 }, 3);
            ans = knapSackGeek(3, new int[] { 1, 2, 3 }, new int[] { 4, 5, 1 }, 3);

            ans = knapSackLst(4, new int[] { 1, 2, 3 }, new int[] { 4, 5, 1 }, 3);
            ans = knapSackTab(4, new int[] { 1, 2, 3 }, new int[] { 4, 5, 1 }, 3);
        }

        // memoization with global
        private int recur(int w, int[] wt, int[] val, int n)
        {
            if (n == 0 || w == 0)
            {
                return 0;
            }
            if (memoArr[n, w] != -1)
            {
                return memoArr[n, w];
            }
            if (wt[n - 1] <= w)
            {
                return memoArr[n, w] = Math.Max(val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1), recur(w, wt, val, n - 1));
            }
            else if (wt[n - 1] > w)
            {
                return memoArr[n, w] = recur(w, wt, val, n - 1);
            }
            return 0;
        }
        private int knapSack(int w, int[] wt, int[] val, int n)
        {
            recur(w, wt, val, n);
            return memoArr[n, w];
        }

        //----------------------------------------------------geek---------------
        int knapSackGeek(int W, int[] wt, int[] val, int n)
        {
            int i = 0, w = 0;
            int[,] K = new int[n + 1, W + 1];

            //building table K[][] in bottom up manner.
            for (i = 0; i <= n; i++)
            {
                for (w = 0; w <= W; w++)
                {
                    //base case
                    if (i == 0 || w == 0)
                        K[i, w] = 0;

                    //if weight of current item is more than Knapsack capacity W
                    //then this item cannot be included in the optimal solution.
                    else if (wt[i - 1] <= w)
                        K[i, w] = Math.Max(val[i - 1] + K[i - 1, w - wt[i - 1]], K[i - 1, w]);
                    //else updating K[i][w] as K[i-1][w].
                    else
                        K[i, w] = K[i - 1, w];
                }
            }
            //returning the result.
            return K[n, W];
        }

        // memoization with global (another way, code is just same as above)
        private List<List<int>> memoLst = new List<List<int>>();
        private int recurLst(int w, int[] wt, int[] val, int n)
        {
            if (n == 0 || w == 0)
            {
                return 0;
            }
            if (memoLst[n][w] != -1)
            {
                return memoLst[n][w];
            }
            if (wt[n - 1] <= w)
            {
                return memoLst[n][w] = Math.Max(val[n - 1] + recurLst(w - wt[n - 1], wt, val, n - 1), recurLst(w, wt, val, n - 1));
            }
            else if (wt[n - 1] > w)
            {
                return memoLst[n][w] = recurLst(w, wt, val, n - 1);
            }
            return 0;
        }
        private int knapSackLst(int w, int[] wt, int[] val, int n)
        {
            // memoLst = VectorHelper.NestedList(, , -1);
            for (int r = 0; r < n + 1; r++)
            {
                memoLst.Add(new List<int>());
                for (int c = 0; c < w + 1; c++)
                {
                    memoLst[r].Add(-1);
                }
            }

            return recurLst(w, wt, val, n);
        }

        // tabulation
        private int knapSackTab(int w, int[] wt, int[] val, int n)
        {
            int[,] memo = new int[w + 1, w + 1];
            //memo.Resize(n + 1, VectorHelper.InitializedList(w + 1, -1));
            for (int r = 0; r < memo.GetLength(0); r++)
            {
                for (int c = 0; c < memo.GetLength(1); c++)
                {
                    memo[r, c] = -1;
                }
            }
            for (int i = 0; i < n + 1; i++)
            {
                memo[i, 0] = 0;
            }
            for (int j = 0; j < w + 1; j++)
            {
                memo[0, j] = 0;
            }

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < w + 1; j++)
                {
                    if (wt[i - 1] <= j)
                    {
                        memo[i, j] = Math.Max(val[i - 1] + memo[i - 1, j - wt[i - 1]], memo[i - 1, j]);
                    }
                    else
                    {
                        memo[i, j] = memo[i - 1, j];
                    }
                }
            }
            return memo[n, w];
        }
    }
}
