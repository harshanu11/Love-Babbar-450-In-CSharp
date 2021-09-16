using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _09_backtracking
{
    public class _02_print_all_solution_in_N_queen_problem
    {
		/*
			link: https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
			video: https://youtu.be/i05Ju7AftcM
		*/
		[Fact]
		public void print_all_solution_in_N_queen_problem() 
		{
			var ans = SolveNQueens(4);
			//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

		}


		private int N;
		public IList<IList<string>> SolveNQueens(int n)
		{
			N = n;
			var res = new List<IList<string>>();
			char[][] board = new char[N][];
			for (int i = 0; i < N; i++)
			{
				board[i] = new char[N];
				Array.Fill(board[i], '.');
			}

			Helper(res, board, 0);
			return res;
		}

		private void Helper(IList<IList<string>> res, char[][] board, int rowIndex)
		{
			if (rowIndex == N)
			{
				IList<string> list = new List<string>();
				for (int i = 0; i < N; i++)
				{
					string s = new string(board[i]);
					list.Add(s);
				}
				res.Add((list));
				return;
			}

			for (int colIndex = 0; colIndex < N; colIndex++)
			{
				if (IsValid(board, rowIndex, colIndex))
				{
					board[rowIndex][colIndex] = 'Q';
					Helper(res, board, rowIndex + 1);
					board[rowIndex][colIndex] = '.';
				}
			}
		}

		private bool IsValid(char[][] board, int rowIndex, int colIndex)
		{
			for (int i = 0; i < rowIndex; i++)
				if (board[i][colIndex] == 'Q') return false;

			for (int i = rowIndex - 1, j = colIndex - 1; i >= 0 && j >= 0; i--, j--)
				if (board[i][j] == 'Q') return false;

			for (int i = rowIndex - 1, j = colIndex + 1; i >= 0 && j < N; i--, j++)
			{
				if (board[i][j] == 'Q') return false;
			}

			return true;
		}

	}
}
