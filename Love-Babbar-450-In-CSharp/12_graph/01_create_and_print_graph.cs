using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace graph
{
    public class _01_create_and_print_graph
    {
        /*
		    link: https://www.javatpoint.com/graph-theory-graph-representations#:~:text=In%20graph%20theory%2C%20a%20graph,to%20it%20by%20an%20edge).
		    link: https://onedrive.live.com/?authkey=%21AJrTq%5FU8BPKIWDk&cid=842AECBB531CCEA4&id=842AECBB531CCEA4%211179&parId=842AECBB531CCEA4%211164&o=OneUp
		*/


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using adjacency matrix:

            TC: O(1) => for searching
            SC: O(N^2)
        */
        [Fact]
        public void AddEdge_GraphTest()
        {
            GraphOps g = new GraphOps(4);
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.addEdge(1, 2);
            g.addEdge(2, 0);
            g.addEdge(2, 3);
            g.addEdge(3, 3);
            int u = 1;
            int v = 3;
            if (g.isReachable(u, v))
                Debug.WriteLine("There is a path from " + u + " to " + v);
            else
                Debug.WriteLine("There is no path from " + u + " to " + v);
            u = 3;
            v = 1;
            if (g.isReachable(u, v))
                Debug.WriteLine("There is a path from " + u + " to " + v);
            else
                Debug.WriteLine("There is no path from " + u + " to " + v);
            adjMatrix();
        }

        private void adjMatrix()
        {
            int rows = 4;
            int cols = 4;

            int[,] adj = new int[rows + 1, cols + 1];

            for (int i = 0; i < rows; i++)
            {
                int u;
                int v;
                u = 1;
                v = 1;
                adj[u, v] = 1;
                adj[v, u] = 1;
            }
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using adjacency list

            TC: O(Edges of that vertex)
            SC: O(N + (2*E))
        */

        //private int adjList()
        //{
        //	int rows;
        //	int cols;
        //	rows = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
        //	cols = int.Parse(ConsoleInput.ReadToWhiteSpace(true));

        //	List<int> adj = new List<int>(rows + 1);

        //	for (int i = 0; i < m; i++)
        //	{
        //		int u;
        //		int v;
        //		u = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
        //		v = int.Parse(ConsoleInput.ReadToWhiteSpace(true));

        //		adj[u].push_back(v);
        //		adj[v].push_back(u); // comment this line for directed graph

        //		// for weighted graph use: adj[u].push_back({v, wt});
        //		//                         adj[v].push_back({u, wt});
        //	}
        //}

    }

    public class GraphOps
    {
        private int V;
        private LinkedList<int>[] adj;
        public GraphOps(int v)
        {
            V = v;
            adj = new LinkedList<int>[v];
            for (int i = 0; i < v; ++i)
                adj[i] = new LinkedList<int>();
        }
        public void addEdge(int v, int w)
        {
            adj[v].AddLast(w);
        }
        public bool isReachable(int s, int d)
        {
            bool[] visited = new bool[V];

            // Create a queue for BFS
            LinkedList<int> queue = new LinkedList<int>();

            visited[s] = true;
            queue.AddLast(s);

            IEnumerator i;
            while (queue.Count != 0)
            {

                s = queue.First.Value;
                queue.RemoveFirst();
                int n;
                i = adj[s].GetEnumerator();

                while (i.MoveNext())
                {
                    n = (int)i.Current;

                    if (n == d)
                        return true;

                    if (!visited[n])
                    {
                        visited[n] = true;
                        queue.AddLast(n);
                    }
                }
            }

            // If BFS is complete without visited d
            return false;
        }
    }
}
