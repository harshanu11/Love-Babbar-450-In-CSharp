///*
//	link: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
//
//	video: https://youtu.be/FWAIf_EVUKE
//
//	(for more ref. or codes): https://www.geeksforgeeks.org/sudoku-backtracking-7/
//*/
//
//
//#include "CppUnitTest.h"
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <unordered_set>
//#include <set>
//#include <unordered_map>
//#include <queue>
//#include <stack>
//
//using namespace std;
//
//namespace LoveBabbar450InCPPTest
//{
//	// TEST_CLASS(BTSort)
//	// {
//	// public:
//
//	//     TEST_METHOD(Test)
//	//     {
//	//         std::string charM = "harhs";
//	//         int age = 14;
//	//         age = 55;
//	//         std::string lastName = "<<charM <<singh";
//
//	//     }
//	// };
//}
//
//// ----------------------------------------------------------------------------------------------------------------------- //
///*
//	TC: O(9^(n*n)) as every N*N place in box has 9 possibilities
//*/
//bool isValid(int row, int col, int curr, int grid[5][5]) {
//	for (int i = 0; i < 9; i++) {
//		// checking in row
//		if (grid[i][col] == curr) return false;
//
//		// checking in col
//		if (grid[row][i] == curr) return false;
//
//		// checking in current block of sudoku
//		if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == curr) return false;
//
//	}
//	return true;
//}
//
//bool SolveSudoku(int grid[5][5])
//{
//	// for every position
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			// if it is to fill then...
//			if (grid[i][j] == 0) {
//				// for every possible no.
//				for (int curr = 1; curr <= 9; curr++) {
//					// if current no. is valid to fill then we will go for the recursion (possibilities)
//					if (isValid(i, j, curr, grid)) {
//						// fill current pos
//						grid[i][j] = curr;
//						// recur for next empty pos
//						if (SolveSudoku(grid)) return true;
//						// if valid filled position didn't return true
//						// because other no. might not accomodate validly
//						// again empty the current pos
//						else grid[i][j] = 0;
//					}
//				}
//				// if not even single no. accomodated return false
//				return false;
//			}
//		}
//	}
//	// if sudoku size is 0x0
//	return true;
//}
//
////Function to print grids of the Sudoku.
//void printGrid(int grid[5][5])
//{
//	// Your code here
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << grid[i][j] << " ";
//		}
//	}
//}