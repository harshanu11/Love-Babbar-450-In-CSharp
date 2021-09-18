using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using Xunit;

namespace _09_backtracking
{
    /*
    link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

    sol: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

    sol(no. of ways): https://www.geeksforgeeks.org/count-number-ways-reach-destination-maze/

    video: https://youtu.be/rKo9MPe0c5A
    video2: https://youtu.be/bLGZhJlt4y0
*/

    public class _01_rat_in_maze
    {
        [Fact]
        public void reverse_arrayTest()
        {
            int[,] m = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
            int n = m.GetLength(0);
            int[][] maze = new int[5][] { new int[] { 1, 0, 0, 0, 0 }
                                        , new int[] { 1, 1, 1, 1, 1 }
                                        , new int[] { 1, 1, 1, 0, 1 }
                                        , new int[] { 0, 0, 0, 0, 1 }
                                        , new int[] { 0, 0, 0, 0, 1 }
                                    };
            var ans = findPath(maze, maze.GetLength(0));
            var ansJArray = solveMaze(maze, maze.GetLength(0));
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            simple using dfs or backtracking

            [Depth First Search (DFS) uses the concept of backtracking at its very core.
            So, in DFS, we basically try exploring all the paths from the given node
            recursively until we reach the goal. After we search in a particular branch
            of a tree in DFS, we can land up in two possible states.]

            TC: O((N ^ 2) ^ 4)
            SC: O(N * N)
        */

        private List<string> ansLst = new List<string>();
        private void dfs(int x, int y, string ansStr, int[][] m, bool[][] vis, int Size)
        {
            if (x < 0 || y < 0 || x >= Size || y >= Size) return;
            if (m[x][y] == 0 || vis[x][y] == true) return;
            if (x == Size - 1 && y == Size - 1)
            {
                ansLst.Add(ansStr);
                return;
            }
            vis[x][y] = true;
            dfs(x + 1, y, ansStr + "D", m, vis, Size);
            dfs(x, y + 1, ansStr + "R", m, vis, Size);
            dfs(x, y - 1, ansStr + "L", m, vis, Size);
            dfs(x - 1, y, ansStr + "U", m, vis, Size);
            vis[x][y] = false;
        }

        private List<string> findPath(int[][] maze, int Size)
        {
            if (maze[Size - 1][Size - 1] == 0 || maze[0][0] == 0) return new List<string>(ansLst);
            bool[][] vis = new bool[maze.GetLength(0)][];
            for (int r = 0; r < vis.GetLength(0); r++) vis[r] = new bool[vis.GetLength(0)];
            dfs(0, 0, "", maze, vis, Size);
            return new List<string>(ansLst);
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            Rat in a Maze | Backtracking-2

            TC: O(2^(n^2))
        */

        /* A recursive utility function
        to solve Maze problem */
        private bool solveMazeUtil(int[][] maze, int x, int y, int[][] sol, int Size)
        {
            if (x == Size - 1 && y == Size - 1 && maze[x][y] == 1)
            {
                sol[x][y] = 1;
                return true;
            }
            if (isSafe(maze, x, y, Size) == true)
            {
                // Check if the current block is already part of solution path.   
                if (sol[x][y] == 1) return false;

                // mark x, y as part of solution path
                sol[x][y] = 1;

                /* Move forward in x direction */
                if (solveMazeUtil(maze, x + 1, y, sol, Size) == true) return true;

                /* If moving in x direction
                doesn't give solution then
                Move down in y direction */
                if (solveMazeUtil(maze, x, y + 1, sol, Size) == true) return true;

                /* If moving in y direction
                doesn't give solution then
                Move back in x direction */
                if (solveMazeUtil(maze, x - 1, y, sol, Size) == true) return true;

                /* If moving backwards in x direction
                doesn't give solution then
                Move upwards in y direction */
                if (solveMazeUtil(maze, x, y - 1, sol, Size) == true) return true;

                /* If none of the above movements
                work then BACKTRACK: unmark
                x, y as part of solution path */
                sol[x][y] = 0;
                return false;
            }

            return false;
        }
        private bool isSafe(int[][] maze, int x, int y, int Size)
        {
            if (x >= 0 && x < Size && y >= 0 && y < Size && maze[x][y] == 1) return true;
            return false;
        }


        /* This function solves the Maze problem
        using Backtracking. It mainly uses
        solveMazeUtil() to solve the problem.
        It returns false if no path is possible,
        otherwise return true and prints the path
        in the form of 1s. Please note that there
        may be more than one solutions, this
        function prints one of the feasible
        solutions.*/
        private int[][] solveMaze(int[][] maze, int Size)
        {
            int[][] sol =
            {
                new int[] {0, 0, 0, 0,0},
                new int[] {0, 0, 0, 0,0},
                new int[] {0, 0, 0, 0,0},
                new int[] {0, 0, 0, 0,0},
                new int[] {0, 0, 0, 0,0}
            };

            if (solveMazeUtil(maze, 0, 0, sol, Size) == false)
            {
                Debug.Write("Solution doesn't exist");
                return null;
            }

            //printSolution(sol);
            for (int r = 0; r < 5; r++)
            {
                for (int c = 0; c < 5; c++)
                {
                    Debug.Write(sol[r][c]);
                }
                Debug.WriteLine(" ");
            }
            return sol;
        }

        //-----------------------------------------------------geek 
        static List<String> possiblePaths = new List<String>();
        static String path = "";
        static readonly int MAX = 5;

        // Function returns true if the
        // move taken is valid else 
        // it will return false.
        static bool isSafe(int row, int col, int[,] m,
                              int n, bool[,] visited)
        {
            if (row == -1 || row == n || col == -1 ||
                 col == n || visited[row, col] ||
                             m[row, col] == 0)
                return false;
            return true;
        }

        // Function to print all the possible
        // paths from (0, 0) to (n-1, n-1).
        static void printPathUtil(int row, int col, int[,] m,
                                  int n, bool[,] visited)
        {

            // This will check the initial point
            // (i.e. (0, 0)) to start the paths.
            if (row == -1 || row == n || col == -1 ||
                 col == n || visited[row, col] ||
                             m[row, col] == 0)
                return;

            // If reach the last cell (n-1, n-1)
            // then store the path and return
            if (row == n - 1 && col == n - 1)
            {
                possiblePaths.Add(path);
                return;
            }

            // Mark the cell as visited
            visited[row, col] = true;

            // Try for all the 4 directions (down, left, 
            // right, up) in the given order to get the
            // paths in lexicographical order

            // Check if downward move is valid
            if (isSafe(row + 1, col, m, n, visited))
            {
                path += 'D';
                printPathUtil(row + 1, col, m, n,
                              visited);
                path = path.Substring(0, path.Length - 1);
            }

            // Check if the left move is valid
            if (isSafe(row, col - 1, m, n, visited))
            {
                path += 'L';
                printPathUtil(row, col - 1, m, n,
                              visited);
                path = path.Substring(0, path.Length - 1);
            }

            // Check if the right move is valid
            if (isSafe(row, col + 1, m, n, visited))
            {
                path += 'R';
                printPathUtil(row, col + 1, m, n,
                              visited);
                path = path.Substring(0, path.Length - 1);
            }

            // Check if the upper move is valid
            if (isSafe(row - 1, col, m, n, visited))
            {
                path += 'U';
                printPathUtil(row - 1, col, m, n,
                              visited);
                path = path.Substring(0, path.Length - 1);
            }

            // Mark the cell as unvisited for 
            // other possible paths
            visited[row, col] = false;
        }

        // Function to store and print
        // all the valid paths 
        static void printPath(int[,] m, int n)
        {
            bool[,] visited = new bool[n, MAX];

            // Call the utility function to
            // find the valid paths 
            printPathUtil(0, 0, m, n, visited);

            // Print all possible paths
            for (int i = 0; i < possiblePaths.Count; i++)
                Debug.Write(possiblePaths[i] + " ");
        }

        // Driver code
         void Main1()
        {
            int[,] m = { { 1, 0, 0, 0, 0 },
                  { 1, 1, 1, 1, 1 },
                  { 1, 1, 1, 0, 1 },
                  { 0, 0, 0, 0, 1 },
                  { 0, 0, 0, 0, 1 } };
            int n = m.GetLength(0);
            printPath(m, n);
        }

        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            Count number of ways to reach destination in a Maze

            TC: O(R * C)
        */


        // Returns count of possible paths in a maze[R][C]
        // from (0,0) to (R-1,C-1)
        private int countPaths(int[][] maze)
        {
            // If the initial cell is blocked, there is no
            // way of moving anywhere
            if (maze[0][0] == -1)
            {
                return 0;
            }

            // Initializing the leftmost column
            for (int i = 0; i < DefineConstants.R; i++)
            {
                if (maze[i][0] == 0)
                {
                    maze[i][0] = 1;
                }

                // If we encounter a blocked cell in leftmost
                // row, there is no way of visiting any cell
                // directly below it.
                else
                {
                    break;
                }
            }

            // Similarly initialize the topmost row
            for (int i = 1; i < DefineConstants.C; i++)
            {
                if (maze[0][i] == 0)
                {
                    maze[0][i] = 1;
                }

                // If we encounter a blocked cell in bottommost
                // row, there is no way of visiting any cell
                // directly below it.
                else
                {
                    break;
                }
            }

            // The only difference is that if a cell is -1,
            // simply ignore it else recursively compute
            // count value maze[i][j]
            for (int i = 1; i < DefineConstants.R; i++)
            {
                for (int j = 1; j < DefineConstants.C; j++)
                {
                    // If blockage is found, ignore this cell
                    if (maze[i][j] == -1)
                    {
                        continue;
                    }

                    // If we can reach maze[i][j] from maze[i-1][j]
                    // then increment count.
                    if (maze[i - 1][j] > 0)
                    {
                        maze[i][j] = (maze[i][j] + maze[i - 1][j]);
                    }

                    // If we can reach maze[i][j] from maze[i][j-1]
                    // then increment count.
                    if (maze[i][j - 1] > 0)
                    {
                        maze[i][j] = (maze[i][j] + maze[i][j - 1]);
                    }
                }
            }

            // If the final cell is blocked, output 0, otherwise
            // the answer
            return (maze[DefineConstants.R - 1][DefineConstants.C - 1] > 0) ? maze[DefineConstants.R - 1][DefineConstants.C - 1] : 0;
        }

        // Driver code
        private void Main()
        {
            int[][] maze =
            {
                new int[] {0, 0, 0, 0},
                new int[] {0, -1, 0, 0},
                new int[] {-1, 0, 0, 0},
                new int[] {0, 0, 0, 0}
            };
            Debug.Write(countPaths(maze));
        }

        internal class DefineConstants
        {
            public const int R = 4;
            public const int C = 4;
        }
        

    }
}
