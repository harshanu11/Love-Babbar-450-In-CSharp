///*
//    sol: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

//    video: https://youtu.be/jbhuqIASjoM?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
//*/


//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//    TC: O((V + E) * logV) => log V for insertion in priority_queue
//    SC: O(V) + O(V), for distTo and priority_queue
//*/
//#include<bits/stdc++.h>
//using namespace std;

//typedef pair<int, int> pii;

//int main() {
//    int n, m, source;
//    cin >> n >> m;
//    vector<pii > g[n + 1]; 	// 1-indexed adjacency list for of graph

//    int a, b, wt;
//    for (int i = 0; i < m; i++) {
//        cin >> a >> b >> wt;
//        g[a].push_back(make_pair(b, wt));
//        g[b].push_back(make_pair(a, wt));
//    }

//    cin >> source;

//    // Dijkstra's algorithm begins from here
//    priority_queue<pii, vector<pii >, greater<pii > > pq;// min-heap ; In pair => (dist,from)
//    vector<int> distTo(n + 1, INT_MAX); 	// 1-indexed array for calculating shortest paths; 

//    distTo[source] = 0;
//    pq.push(make_pair(0, source));	// (dist,from)

//    while (!pq.empty()) {
//        int dist = pq.top().first;
//        int curr = pq.top().second;
//        pq.pop();

//        vector<pii >::iterator it;
//        for (auto it : g[curr]) {
//            int next = it.first;
//            int nextDist = it.second;
//            if (distTo[next] > distTo[curr] + nextDist) {
//                distTo[next] = distTo[curr] + nextDist;
//                pq.push(make_pair(distTo[next], next));
//            }
//        }

//    }

//    cout << "The distances from source, " << source << ", are : \n";
//    for (int i = 1; i <= n; i++)	cout << distTo[i] << " ";
//    cout << "\n";

//    return 0;
//}