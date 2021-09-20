using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _08_greedy
{
    public class _04_water_connection_problem
    {
        [Fact]
        public void reverse_arrayTest() { }

		/*
	link: https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1

	sol: https://www.geeksforgeeks.org/water-connection-problem/
*/




		// ----------------------------------------------------------------------------------------------------------------------- //
		/*
			using DFS
		*/

		// number of houses and number
		// of pipes
		private int n;
		private int p;

		// Array rd stores the
		// ending vertex of pipe
		private int[] rd = new int[1100];

		// Array wd stores the value
		// of diameters between two pipes
		private int[] wt = new int[1100];

		// Array cd stores the
		// starting end of pipe
		private int[] cd = new int[1100];

		private List<List<int>> ans = new List<List<int>>();

		private int mn;

		private int dfs(int w)
		{
			if (cd[w] == 0)
			{
				return w;
			}
			if (wt[w] < mn)
			{
				mn = wt[w];
			}
			return dfs(cd[w]);
		}

		// Function performing calculations.
		//private List<List<int>> solve(int[][] arr)
		//{
		//	int i = 0;

		//	while (i < p)
		//	{

		//		int q = arr[i][0];
		//		int h = arr[i][1];
		//		int t = arr[i][2];

		//		cd[q] = h;
		//		wt[q] = t;
		//		rd[h] = q;
		//		i++;
		//	}

		//	ans.Clear();

		//	for (int j = 1; j <= n; ++j)
		//	{

		//		/*If a pipe has no ending vertex
		//		but has starting vertex i.e is
		//		an outgoing pipe then we need
		//		to start DFS with this vertex.*/
		//		if (rd[j] == 0 && cd[j] != 0)
		//		{
		//			mn = 1000000000;
		//			int w = dfs(j);

		//			// We put the details of component
		//			// in final output array
		//			ans.Add(new List<int>(j, w, mn));
		//		}
		//	}
		//	return new List<List<int>>(ans);
		//}

		//private List<List<int>> solve(int mainN, int mainP, List<int> a, List<int> b, List<int> d)
		//{
		//	n = mainN;
		//	p = mainP;

		//	//C++ TO C# CONVERTER TODO TASK: The memory management function 'memset' has no equivalent in C#:
		//	memset(rd, 0, sizeof(int));
		//	//C++ TO C# CONVERTER TODO TASK: The memory management function 'memset' has no equivalent in C#:
		//	memset(cd, 0, sizeof(int));
		//	//C++ TO C# CONVERTER TODO TASK: The memory management function 'memset' has no equivalent in C#:
		//	memset(wt, 0, sizeof(int));

		//	int[][] arr = RectangularArrays.RectangularIntArray(p, 3);

		//	for (int i = 0; i < p; i++)
		//	{
		//		arr[i][0] = a[i];
		//		arr[i][1] = b[i];
		//		arr[i][2] = d[i];
		//	}
		//	return new List<List<int>>(solve(arr));
		//}








		// ----------------------------------------------------------------------------------------------------------------------- //
		// logic is correct but TLE (so just go through the logic)
		//private List<List<int>> solve(int n, int p, List<int> a, List<int> b, List<int> d)
		//{
		//	List<List<int>> ans = new List<List<int>>();
		//	SortedDictionary<int, Tuple<int, int>> m = new SortedDictionary<int, Tuple<int, int>>();

		//	for (int i = 0; i < p; i++)
		//	{
		//		m[a[i]] = new Tuple<int, int>(b[i], d[i]);
		//	}

		//	for (int i = 0; i < p; i++)
		//	{
		//		if (m.count(m[a[i]].Item1) <= 0)
		//		{
		//			continue;
		//		}

		//		int curr = m[a[i]].Item1;
		//		while (m.count(curr) > 0)
		//		{
		//			m[a[i]].Item1 = m[curr].Item1;
		//			m[a[i]].Item2 = Math.Min(m[a[i]].Item2, m[curr].Item2);
		//			m[curr].Item2 = int.MaxValue;


		//			curr = m[curr].Item1;

		//		}
		//	}
		//	for (var i = m.GetEnumerator(); i != m.end(); i++)
		//	{
		//		if ((i.second).second != int.MaxValue)
		//		{
		//			ans.Add(new List<int>(i.first, (i.second).first, (i.second).second));
		//		}
		//	}
		//	return new List<List<int>>(ans);
		//}
	}
}
/*
	link: https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1

	sol: https://www.geeksforgeeks.org/water-connection-problem/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using DFS
*/

//// number of houses and number
//// of pipes
//int n, p;

//// Array rd stores the
//// ending vertex of pipe
//int rd[1100];

//// Array wd stores the value
//// of diameters between two pipes
//int wt[1100];

//// Array cd stores the
//// starting end of pipe
//int cd[1100];

//vector<vector<int>> ans;

//int mn;

//int dfs(int w)
//{
//	if (cd[w] == 0)
//		return w;
//	if (wt[w] < mn)
//		mn = wt[w];
//	return dfs(cd[w]);
//}

//// Function performing calculations.
//vector<vector<int>> solve(int arr[][3])
//{
//	int i = 0;

//	while (i < p) {

//		int q = arr[i][0], h = arr[i][1],
//			t = arr[i][2];

//		cd[q] = h;
//		wt[q] = t;
//		rd[h] = q;
//		i++;
//	}

//	ans.clear();

//	for (int j = 1; j <= n; ++j)

//		/*If a pipe has no ending vertex
//		but has starting vertex i.e is
//		an outgoing pipe then we need
//		to start DFS with this vertex.*/
//		if (rd[j] == 0 && cd[j]) {
//			mn = 1000000000;
//			int w = dfs(j);

//			// We put the details of component
//			// in final output array
//			ans.push_back({ j, w, mn });
//		}
//	return ans;
//}

//vector<vector<int>> solve(int mainN, int mainP, vector<int> a, vector<int> b, vector<int> d)
//{
//	n = mainN;
//	p = mainP;

//	memset(rd, 0, sizeof(rd));
//	memset(cd, 0, sizeof(cd));
//	memset(wt, 0, sizeof(wt));

//	int arr[p][3];

//	for (int i = 0;i < p;i++) {
//		arr[i][0] = a[i];
//		arr[i][1] = b[i];
//		arr[i][2] = d[i];
//	}
//	return solve(arr);
//}








//// ----------------------------------------------------------------------------------------------------------------------- //
//// logic is correct but TLE (so just go through the logic)
//vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
//{
//	vector<vector<int>> ans;
//	map<int, pair<int, int>> m;

//	for (int i = 0;i < p;i++) {
//		m[a[i]] = { b[i], d[i] };
//	}

//	for (int i = 0;i < p;i++) {
//		if (m.count(m[a[i]].first) <= 0) continue;

//		int curr = m[a[i]].first;
//		while (m.count(curr) > 0) {
//			m[a[i]].first = m[curr].first;
//			m[a[i]].second = min(m[a[i]].second, m[curr].second);
//			m[curr].second = INT_MAX;


//			curr = m[curr].first;

//		}
//	}
//	for (auto i = m.begin();i != m.end();i++) {
//		if ((i->second).second != INT_MAX) ans.push_back({ i->first, (i->second).first, (i->second).second });
//	}
//	return ans;
//}