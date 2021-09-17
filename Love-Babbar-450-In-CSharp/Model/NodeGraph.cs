using System.Collections;
using System.Collections.Generic;

namespace Model
{
    public class NodeGraphUsingLL
    {
        private int V;
        public LinkedList<int>[] adj;
        public NodeGraphUsingLL(int v)
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
