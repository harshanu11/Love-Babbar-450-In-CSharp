/*
    link: https://www.javatpoint.com/graph-theory-graph-representations#:~:text=In%20graph%20theory%2C%20a%20graph,to%20it%20by%20an%20edge).

    link: https://onedrive.live.com/?authkey=%21AJrTq%5FU8BPKIWDk&cid=842AECBB531CCEA4&id=842AECBB531CCEA4%211179&parId=842AECBB531CCEA4%211164&o=OneUp

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
#define rows 4
#define cols 4
#define m 4
namespace LoveBabbar450InCPPTest
{


    TEST_CLASS(Graph)
    {
    public:

        TEST_METHOD(GraphTest)
        {


        }
    };


    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using adjacency matrix:

        TC: O(1) => for searching
        SC: O(N^2)
    */

    int adjMatrix() {
         rows, cols;
        //cin >> rows >> cols;

        int adj[rows + 1][rows + 1];

        for (int i = 0; i < rows; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }





    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        using adjacency list

        TC: O(Edges of that vertex)
        SC: O(N + (2*E))
    */

    int adjList() {
        rows, cols;
        //cin >> rows >> cols;

        vector<int> adj1(rows + 1);

        for (int i = 0; i < 5; i++) {
            int u, v;
           // cin >> u >> v;

      /*      adj1[u].push_back(v);
            adj1[v].push_back(u); */       // comment this line for directed graph

            // for weighted graph use: adj[u].push_back({v, wt});
            //                         adj[v].push_back({u, wt});
        }
    }
}
