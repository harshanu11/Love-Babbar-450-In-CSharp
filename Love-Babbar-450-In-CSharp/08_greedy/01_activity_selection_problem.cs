using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace greedy
{
    internal class pair
    {
        internal int first, second;
        public pair(int start, int finish)
        {
            this.first = start;
            this.second = finish;
        }
    }
    class ComparatorAnonymousInnerClass : IComparer<pair>
    {
        public int Compare(pair s1, pair s2)
        {
            return s1.second - s2.second;
        }
    }
    public class _01_activity_selection_problem
    {
        /*
            link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
            editorial https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

            custom sort function to sort the finishing time.
            why static ?
            in some online judge platform we have to keep it static so it wont change in lifetime of the program.
        */
        [Fact]
        public void greedy_arrayTest()
        {
           var ans = maxMeetings1(new int[] { 1, 3, 0, 5, 8, 5 }, new int[] { 2, 4, 6, 7, 9, 9 }, 6);
            ans = printMaxActivities(new int[] { 1, 3, 0, 5, 8, 5 }, new int[] { 2, 4, 6, 7, 9, 9 }, 6);
        }


        public static int maxMeetings1(int[] start, int[] end, int n)
        {
            pair[] x = new pair[n];

            //pushing the pair of starting and finish time in a list.
            for (int i = 0; i < n; i++)
            {
                x[i] = new pair(start[i], end[i]);
            }


            //comparator function used in sorting the list of pairs 
            //according to increasing order of the finish time.
            Array.Sort(x, new ComparatorAnonymousInnerClass());

            int last = 0;
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                //if the start time of this meeting is greater than or equal
                //to the finish time of previously selected meeting then 
                //we increment the counter and update last.
                if (x[i].first > last)
                {
                    res++;
                    last = x[i].second;
                }
            }
            //returning the counter.
            return res;
        }

        public int printMaxActivities(int[] start,int[] end, int len)
        {
            int i, j;
            int result = 1;
            Console.Write("Following activities are selected : ");

            // The first activity always gets selected
            i = 0;
            Debug.Write(i + " ");

            // Consider rest of the activities
            for (j = 1; j < len; j++)
            {
                // If this activity has start time greater than or
                // equal to the finish time of previously selected
                // activity, then select it
                if (start[j] >= end[i])
                {
                    Debug.Write(j + " ");
                    i = j;
                    result++;
                }
            }
            return result;
        }

    }
    
}