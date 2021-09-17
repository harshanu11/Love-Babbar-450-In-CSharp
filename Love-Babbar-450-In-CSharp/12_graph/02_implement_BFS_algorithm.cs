using Model;
using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _12_graph
{
    public class _02_implement_BFS_algorithm
    {
        /*
			link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

			sol: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

			video: https://youtu.be/UeE67iCK2lQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

			travel adjacent node first
			than move to the next node

			The Time complexity of BFS is O(V + E) when Adjacency List is used
			and O(V^2) when Adjacency Matrix is used,
			where V stands for vertices and E stands for edges.

			as it will go to every vertex as well as it will check for corresponding edges
			hence TC becomes V+E
		*/
        [Fact]
        public void BfsTest()
        {
            NodeGraphUsingList g = new NodeGraphUsingList(4);
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.addEdge(1, 2);
            g.addEdge(2, 0);
            g.addEdge(2, 3);
            g.addEdge(3, 3);
            //var ans = bfsOfGraph1(4, g.adj);
            //ans = bfsOfGraph2(4, g.adj);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
			for connected component
		*/
        private List<int> bfsOfGraph1(int V, List<int>[] adj)
        {
            List<bool> vis = new List<bool>(V);
            List<int> ans = new List<int>();

            Queue<int> q = new Queue<int>();
            q.Enqueue(0);
            vis[0] = true;

            while (q.Count > 0)
            {
                int curr = q.Peek();
                q.Dequeue();
                ans.Add(curr);

                foreach (var j in adj[curr])
                {
                    if (!vis[j])
                    {
                        q.Enqueue(j);
                        vis[j] = true;
                    }
                }
            }

            return new List<int>(ans);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
			for disconnected component

			TC: O(N + E)  => visiting every node once
			SC: O(N + E)  => space for every node and vice-verca for both edge
		*/

        private List<int> bfsOfGraph2(int V, List<int>[] adj)
        {
            List<bool> vis = new List<bool>(V);
            List<int> ans = new List<int>();

            for (int i = 0; i < V; i++)
            {
                if (!vis[i])
                {
                    //int i = 0;
                    Queue<int> q = new Queue<int>();
                    q.Enqueue(i);
                    vis[i] = true;

                    while (q.Count > 0)
                    {
                        int curr = q.Peek();
                        q.Dequeue();
                        ans.Add(curr);

                        foreach (var j in adj[curr])
                        {
                            if (!vis[j])
                            {
                                q.Enqueue(j);
                                vis[j] = true;
                            }
                        }
                    }
                }

                return new List<int>(ans);
            }
            return ans;
        }


    }
}
