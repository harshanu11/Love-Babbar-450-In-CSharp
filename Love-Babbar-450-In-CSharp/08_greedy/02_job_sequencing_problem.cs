using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _08_greedy
{
    public class _02_job_sequencing_problem
    {
        /*
			link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

			logic:
				1. sort by profit so that we can prioritize the best
				2. now for every job find :
					a. if the current job is empty then fill it
					b. if not the current job then find the job slot which is empty and having deadline less than current

			warning: we cannot the replace the filled job as if the job exist for that deadline then we have to fill it.
		*/
        [Fact]
        public void Test()
        {
            Job[] j = new Job[] {
                new Job() { id =1, deadLine=4,profit= 20} ,
                new Job() { id =2, deadLine=1,profit= 10} ,
                new Job() { id =3, deadLine=1,profit= 40} ,
                new Job() { id =4, deadLine=1,profit= 30} ,
            };
            var ans = JobScheduling(j, 4);
        }

        public class Job
        {
            public int id { get; set; }
            public int deadLine { get; set; }
            public int profit { get; set; }
        }
        class compare : IComparer<Job>
        {
            public int Compare(Job s1, Job s2)
            {
                return s1.profit - s2.profit;
            }
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        //Function to find the maximum profit and the number of jobs done.
        public List<int> JobScheduling(Job[] arr, int n)
        {
            Array.Sort(arr, new compare());
            int[] a = new int[n + 1];

            for (int i = 0; i < n; i++)
            {
                for (int j = Math.Min(arr[i].deadLine, n); j > 0; j--)
                {
                    if (a[j] == 0)
                    {
                        a[j] = arr[i].profit;
                        break;
                    }
                }
            }
            int cnt = 0;
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != 0)
                {
                    cnt++;
                    ans += a[i];
                }
            }
            return new List<int>() { cnt, ans };
        }
    }

}
