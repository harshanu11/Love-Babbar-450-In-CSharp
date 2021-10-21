/*
    link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

    custom sort function to sort the finishing time.
    why static ?
    in some online judge platform we have to keep it static so it wont change in lifetime of the program.
*/
#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(Greedy)
    {
    public:

        TEST_METHOD(ActivitySelectionTest)
        {
            // Starting time 
            int s[] = { 1, 3, 0, 5, 8, 5 };

            // Finish time 
            int f[] = { 2, 4, 6, 7, 9, 9 };

            // Number of meetings. 
            int n = sizeof(s) / sizeof(s[0]);

            // Function call 
            maxMeetings(s, f, n);

        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        bool static compare(pair<int, int> meeting1, pair<int, int> meeting2) {
            if (meeting1.second == meeting2.second) return meeting1.first < meeting2.first;
            return meeting1.second < meeting2.second;
        }

        int maxMeetings(int start[], int end[], int n)
        {
            // using vector pair as we want to sort acc. to the finishing time
            vector<pair<int, int>> timeTable(n);
            for (int i = 0; i < n; i++) {
                timeTable[i] = { start[i], end[i] };
            }
            sort(timeTable.begin(), timeTable.end(), compare);


            int temp = INT_MIN;
            int meetings = 0;
            for (pair<int, int> p : timeTable) {
                // whenever we have starting time larger than prev. finishing time add meeting to room
                if (p.first > temp) {
                    temp = p.second;
                    meetings++;
                }
            }
            return meetings;
        }
    };
}


