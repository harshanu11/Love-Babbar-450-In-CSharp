using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace Love_Babbar_450_In_CSharp._08_greedy
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
    public class _01_activity_selection_problem
    {
        [Fact]
        public void greedy_arrayTest()
        {

        }

        /*
            link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

            custom sort function to sort the finishing time.
            why static ?
            in some online judge platform we have to keep it static so it wont change in lifetime of the program.
        */


        // ----------------------------------------------------------------------------------------------------------------------- //
        private bool compare(Tuple<int, int> meeting1, Tuple<int, int> meeting2)
        {
            if (meeting1.Item2 == meeting2.Item2)
            {
                return meeting1.Item1 < meeting2.Item1;
            }
            return meeting1.Item2 < meeting2.Item2;
        }

        private int maxMeetings(int[] start, int[] end, int n)
        {
            // using vector pair as we want to sort acc. to the finishing time
            List<Tuple<int, int>> timeTable = new List<Tuple<int, int>>(n);
            for (int i = 0; i < n; i++)
            {
                timeTable[i] = new Tuple<int, int>(start[i], end[i]);
            }

            //C++ TO C# CONVERTER TODO TASK: The 'Compare' parameter of std::sort produces a boolean value, while the .NET Comparison parameter produces a tri-state result:
            //ORIGINAL LINE: sort(timeTable.begin(), timeTable.end(), compare);
            // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& issue
            //timeTable.Sort(compare);


            int temp = int.MinValue;
            int meetings = 0;
            foreach (Tuple<int, int> p in timeTable)
            {
                // whenever we have starting time larger than prev. finishing time add meeting to room
                if (p.Item1 > temp)
                {
                    temp = p.Item2;
                    meetings++;
                }
            }
            return meetings;
        }

        //------------------------------------------------------------------------------------------------------------------------//
        //Function to find the maximum number of meetings that can
        //be performed in a meeting room.
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

        private class ComparatorAnonymousInnerClass : IComparer<pair>
        {
            public int Compare(pair s1, pair s2)
            {
                return s1.second - s2.second;
            }
        }

    }
    
}




internal class Solution
{

}
