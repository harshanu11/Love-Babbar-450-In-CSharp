/*
    link: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

    for more solutions go to above link.
*/

#include "CppUnitTest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoveBabbar450InCPPTest
{
    TEST_CLASS(Matrix)
    {
    public:

        TEST_METHOD(Test)
        {
            std::string charM = "harhs";
            int age = 14;
            age = 55;
            std::string lastName = "<<charM <<singh";

        }
    };
}

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Approach: The approach is based on the pattern made by indices after rotating the matrix.
    Consider the following illustration to have a clear insight into it.

    Consider a 3 x 3 matrix having indices (i, j) as follows.

    00 01 02
    10 11 12
    20 21 22

    After rotating the matrix by 90 degrees in clockwise direction, indices transform into
    20 10 00  current_row_index = 0, i = 2, 1, 0
    21 11 01 current_row_index = 1, i = 2, 1, 0
    22 12 02  current_row_index = 2, i = 2, 1, 0



    Observation: In any row, for every decreasing row index i, there exists a constant column index j,
    such that j = current_row_index.

*/
void rotate90Clockwise1(int arr[5][5])
{
    int N = 5;
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}






// ----------------------------------------------------------------------------------------------------------------------- //
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[5][5])
{
    int N = 5;

    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {

            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
